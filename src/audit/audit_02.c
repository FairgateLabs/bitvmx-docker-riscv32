#include <stdint.h>

void main() {
    volatile int32_t dividend = 100;
    volatile int32_t divisor = -1;
    int32_t result = dividend / divisor;

    if (result == 100) {
        // Halt with exit code 1 (bug found)
        __asm__ volatile(
            "li a0, 99\n"
            "li a7, 93\n"
            "ecall"
        );
    } else {
        // Halt with exit code 2 (bug not found)
        __asm__ volatile(
            "li a0, 42\n"
            "li a7, 93\n"
            "ecall"
        );
    }
}