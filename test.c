#include "memory.h"
#include "registers.h"
#include "instructions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init_registers();
    init_memory();

    printf(">> Begin 6502 emulation\n");
    printf("SP: 0x%X\n", get_full_SP());
    printf("Execute instruction DEX\n");
    instr_dex();
    printf("X: %d\n", reg_X.data);
    printf("A: %d\n", reg_A.data);
    printf("Execute instruction TXA\n");
    instr_txa();
    printf("X: %d\n", reg_X.data);
    printf("A: %d\n", reg_A.data);
    printf("Execute instruction LDA #$42\n");
    instr_lda(42, IMMEDIATE);
    printf("X: %d\n", reg_X.data);
    printf("A: %d\n", reg_A.data);
    return 0;
}

