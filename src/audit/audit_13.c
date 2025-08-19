#include <stdint.h>
#include <stddef.h>
#include "../emulator.h"

int main() {
    volatile int32_t a = 0x84226da3;
    volatile int32_t b = 0x80c8c213;

    uint32_t expected_high = 0x3d8da62d;
    uint32_t actual_high;

    __asm__ volatile(
        "mulh %0, %1, %2"
        : "=r"(actual_high)
        : "r"(a), "r"(b));

    if (actual_high == expected_high) {
        print_literal("ok\n", 3);
        return 0;
    } else {
        print_literal("not ok\n", 7);
        return 1;
    }
}