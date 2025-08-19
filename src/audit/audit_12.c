#include <stdint.h>
#include <stddef.h>
#include "../emulator.h"

int main() {
    volatile uint32_t a = 0x1b49f21b;
    volatile uint32_t b = 0x1f51e1ed;

    uint32_t expected_low = 0x20c9ddff;

    uint32_t result = a * b;
    uint32_t actual_low = result;

    if (actual_low == expected_low) {
        print_literal("ok\n", 3);
        return 0;
    }
    else {
        print_literal("not ok\n", 7);
        return 1;
    }
}