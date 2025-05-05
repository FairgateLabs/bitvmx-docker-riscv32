#include "defs.h"
int main(int x) {

        // this will loop forever
    __asm__ volatile (
        "li t0, %0\n\t"  // Load invalid address into t0
        "jr t0\n\t"      // Jump to the invalid address
        :
        : "i"(INVALID_SECTION)
        : "t0"
    );


    return 0;
}

