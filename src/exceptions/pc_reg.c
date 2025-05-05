#include "defs.h"
int main(int x) {

        // inline assembly to jump to an invalid address
    __asm__ volatile (
        "li t0, %0\n\t"  // Load invalid address into t0
        "jr t0\n\t"      // Jump to the invalid address
        :
        : "i"(REGISTER_BASE_ADDRESS)
        : "t0"
    );


    return 0;
}

