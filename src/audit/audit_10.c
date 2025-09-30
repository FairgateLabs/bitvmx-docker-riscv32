#include <stdint.h>
#include "../emulator.h"

int main()
{
    __asm__ volatile (
        "auipc t0, 0\n\t"
        "lw t1, 0(t0)\n\t"
    );

    return 0;
}