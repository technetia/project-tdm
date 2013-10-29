#include "registers.h"
#include "instructions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    ProcessorStatusRegister p;
    init_psr(&p);
    instr_clc(&p);
    printf("%d\n", p.data.flags.C);
    return 0;
}

