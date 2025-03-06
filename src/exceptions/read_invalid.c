#include "defs.h"
int main(int x) {

    //exception trying to access an invalid section (segmentation fault)
    int* z = (int*)INVALID_SECTION;
    return *z;
}

