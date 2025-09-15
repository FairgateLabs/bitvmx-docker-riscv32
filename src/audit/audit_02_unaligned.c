#include <stdint.h>
#include "../emulator.h"

void main() {
    // x0 = *((int32_t *)(INPUT_ADDRESS + INPUT_SIZE - 2));
    //                                                 ^ Attempting to read 4 bytes starting 2 bytes before the end of the input
    //                                                   section will extend 2 bytes past the valid range. The first 2 bytes
    //                                                   are fine, but the second half of the 4-byte load falls outside the
    //                                                   readable memory, causing the emulator to fail in the second micro-instruction.

    __asm__ volatile (
        "li   a5, %[base]\n"     // a5 = INPUT_ADDRESS
        "li   a6, %[size]\n"     // a6 = INPUT_SIZE
        "add  a5, a5, a6\n"      // a5 = INPUT_ADDRESS + INPUT_SIZE
        "lw   x0, -2(a5)\n"      // x0 = M[a5 - 2]
        :
        : [base] "i" (INPUT_ADDRESS), [size] "i" (INPUT_SIZE)
    );
}