call docker-run.bat riscv32 riscv32/build.sh src/exceptions/read_reg.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/read_invalid.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_reg.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_invalid.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/pc_limit.c --output exceptions --with-mul --no-qemu
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/write_reg.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/write_invalid.c --output exceptions --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/exceptions/write_protected.c --output exceptions --with-mul