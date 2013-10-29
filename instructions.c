#include "instructions.h"

void instr_clc(ProcessorStatusRegister *psr) {
    psr->data.flags.C = 0;
}

