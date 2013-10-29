#include "registers.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    ProcessorStatusRegister p;
    p.data.reg = 0x80;
    printf("%d\n", p.data.flags.N);
    return 0;
}

