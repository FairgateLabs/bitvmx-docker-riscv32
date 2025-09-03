#include <stdint.h>

const uint32_t payload[] = {
    0x9308D005, // a7,zero,93
    0x73000000  // ecall
};
int main()
{
    // Create a function pointer that points to our data array.
    int (*function_in_data)(void) = (int (*)(void))payload;
    int result = function_in_data();
    return 100 + result;
}