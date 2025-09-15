#!/bin/bash

cd /data

# Check if the input file argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <input_filename> [--output output_dir] [--with-mul] [--no-qemu]"
    exit 1
fi

# Initialize default architecture
march="rv32i"

echo "Building $1 $2 $3 $4"

# Check if the --with-mul argument is provided
if [ "$2" == "--with-mul" ] || [ "$4" == "--with-mul" ]; then
    march="rv32im"
fi

output_dir=""
if [ "$2" == "--output" ]; then
    output_dir=$3
fi




# Extract the input file name without extension
input_file=$1
base_name=$(basename "$input_file" .c)

# Message
echo "Building $input_file with $march architecture"

# Generate assembly from the input file
$CC -march=$march -mabi=ilp32 -S "$input_file" -o "riscv32/build/${output_dir}/${base_name}.s"

extra_files=""
# Check if the --with-mul argument is provided
if [ "$2" == "--with-mul" ] || [ "$4" == "--with-mul" ]; then
    march="rv32im"
else
    extra_files="/src/mulsi3.c /src/div.S"
    # Generate assembly for mulsi3.c
    $CC -march=$march -mabi=ilp32 -S /src/mulsi3.c -o /src/mulsi3.s
fi


# Link the necessary files into an ELF executable
$CC -march=$march -mabi=ilp32 -nostdlib -T linker/link.ld $extra_files /data/src/entrypoint.s "$input_file" -o "riscv32/build/${output_dir}/${base_name}.elf"

# Run the ELF with QEMU
skip_qemu=false
for arg in "$@"; do
    if [ "$arg" == "--no-qemu" ]; then
        skip_qemu=true
        break
    fi
done

# Run the ELF with QEMU
if [ "$skip_qemu" == true ]; then
    echo "Skipping QEMU"
else
    $QEMU -cpu rv32,c=false -d in_asm -D "riscv32/build/${output_dir}/${base_name}_trace.s" "riscv32/build/${output_dir}/${base_name}.elf"
fi

