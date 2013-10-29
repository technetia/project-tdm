#include "stack_instructions.h"
#include "registers.h"
#include "memory.h"

void instr_tsx(void) {
    reg_X.data = (signed char)reg_SP.data;
    /* set zero flag if appropriate */
    if (reg_X.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_X.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_txs(void) {
    reg_SP.data = (unsigned char)reg_X.data;
}

void instr_pha(void) {
    unsigned short stack_index = reg_SP.page_index << 8;
    stack_index += reg_SP.data;
    MEMORY_BLOCK[stack_index] = reg_A.data;
    reg_SP.data--;
}

void instr_php(void) {
    unsigned short stack_index = reg_SP.page_index << 8;
    stack_index += reg_SP.data;
    MEMORY_BLOCK[stack_index] = reg_PSR.data.reg;
    reg_SP.data--;
}

void instr_pla(void) {
    unsigned short stack_index = reg_SP.page_index << 8;
    reg_SP.data++;
    stack_index += reg_SP.data;
    reg_A.data = MEMORY_BLOCK[stack_index];
    /* set zero flag if appropriate */
    if (reg_A.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_A.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_plp(void) {
    unsigned short stack_index = reg_SP.page_index << 8;
    reg_SP.data++;
    stack_index += reg_SP.data;
    reg_PSR.data.reg = MEMORY_BLOCK[stack_index];
}

