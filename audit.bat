call docker-run.bat riscv32 riscv32/build.sh src/audit/audit_01.c --output audit --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/audit/audit_09_verify.c --output audit --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/audit/audit_12_verify.c --output audit --with-mul
call docker-run.bat riscv32 riscv32/build.sh src/audit/audit_13_verify.c --output audit --with-mul
