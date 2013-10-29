#include "memory.h"
#include "registers.h"
#include "flag_instructions.h"
#include "misc_instructions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init_registers();
    instr_nop();
    return 0;
}

