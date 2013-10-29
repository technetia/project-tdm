#include "memory.h"
#include "registers.h"
#include "flag_instructions.h"
#include "register_instructions.h"
#include "stack_instructions.h"
#include "misc_instructions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init_registers();
    init_memory();

    printf(">> Begin 6502 emulation\n");
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_inx();
    printf("Execute instruction INX\n");
    printf("X: %d\n", reg_X.data);
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_txa();
    printf("Execute instruction TXA\n");
    printf("A: %d\n", reg_A.data);
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_php();
    printf("Execute instruction PHP\n");
    printf("SP: %d\n", reg_SP.data);
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_pla();
    printf("Execute instruction PLA\n");
    printf("SP: %d\n", reg_SP.data);
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    return 0;
}

