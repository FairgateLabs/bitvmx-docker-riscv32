#include "defs.h"
int main(int x) {

    //exception trying to directly access a register
    int* z = (int*)REGISTER_BASE_ADDRESS;
    *z = 1234;
    return 0;
}

