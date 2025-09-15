#include <stdint.h>

int main() {
    volatile int32_t dividend = 100;
    volatile int32_t divisor = -1;
    int32_t quot = dividend / divisor;
    int32_t rem = dividend % divisor;

    return (quot == -100 && rem == 0) ? 0 : 1;
}