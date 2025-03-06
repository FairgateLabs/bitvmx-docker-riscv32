call docker-run.bat riscv32 riscv32/build.sh src/exceptions/read_reg.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/read_invalid.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_reg.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_invalid.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_limit.c --output exceptions --with-mul --no-qemu