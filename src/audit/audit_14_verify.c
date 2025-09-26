#include <stdint.h>
#include "../emulator.h"

__attribute__((naked, aligned(8))) int test_switch(int x)
{
    __asm__ volatile(
        // Jump over embedded data
        "j .Lcode_start\n\t"
        "nop\n\t"

        // Embedded lookup table (must be at known offset)
        // with random opcodes so that the emulator does not complain 
        // about invalid opcodes in .text section
        ".Ldata:\n\t"
        ".word 0x00300293\n\t" // [0]
        ".word 0x00a2ee63\n\t" // [4]
        ".word 0x00000317\n\t" // [8]
        ".word 0xfe830313\n\t" // [12]

        ".Lcode_start:\n\t"
        // Bounds check
        "li t0, 3\n\t"
        "bgtu a0, t0, .Ldefault\n\t"

        // Calculate data address with AUIPC
        "auipc t1, 0\n\t"      // t1 = PC
        "addi t1, t1, -24\n\t" // t1 = .Ldata (PC - 24)

        // Load value
        "slli a0, a0, 2\n\t" // a0 = x * 4
        "add t1, t1, a0\n\t" // t1 = &data[x]
        "lw a0, 0(t1)\n\t"   // return data[x]
        "ret\n\t"

        ".Ldefault:\n\t"
        "li a0, -1\n\t"
        "ret");
}

int main(int x)
{
    int t0 = test_switch(0);
    int t1 = test_switch(1);
    int t2 = test_switch(2);
    int t3 = test_switch(3);

    int (*p)(int) = test_switch;
    p = (int (*)(int))((uintptr_t)p | 1);

    int p0 = p(0);
    int p1 = p(1);
    int p2 = p(2);
    int p3 = p(3);

    return !(p0 == t0 && p1 == t1 && p2 == t2 && p3 == t3);
}