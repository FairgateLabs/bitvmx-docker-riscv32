#include <stdint.h>
#include "../emulator.h"

void main() {
    // x0 = *((int32_t *)(INPUT_ADDRESS + INPUT_SIZE)); 
    // This falls directly outside the input section, so it will fail in the first micro-instruction.
    __asm__ volatile (
        "li   a5, %[base]\n"     // a5 = INPUT_ADDRESS
        "li   a6, %[size]\n"     // a6 = INPUT_SIZE
        "add  a5, a5, a6\n"      // a5 = INPUT_ADDRESS + INPUT_SIZE
        "lw   x0, 0(a5)\n" 
        :
        : [base] "i" (INPUT_ADDRESS), [size] "i" (INPUT_SIZE)
    );
}