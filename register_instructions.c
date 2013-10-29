#include "register_instructions.h"
#include "registers.h"

void instr_tax(void) {
    reg_X.data = reg_A.data;
    /* set zero flag if appropriate */
    if (reg_X.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_X.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_tay(void) {
    reg_Y.data = reg_A.data;
    /* set zero flag if appropriate */
    if (reg_Y.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_Y.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_txa(void) {
    reg_A.data = reg_X.data;
    /* set zero flag if appropriate */
    if (reg_A.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_A.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_tya(void) {
    reg_A.data = reg_Y.data;
    /* set zero flag if appropriate */
    if (reg_A.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_A.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_inx(void) {
    reg_X.data++;
    /* set zero flag if appropriate */
    if (reg_X.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_X.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_iny(void) {
    reg_Y.data++;
    /* set zero flag if appropriate */
    if (reg_Y.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_Y.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_dex(void) {
    reg_X.data--;
    /* set zero flag if appropriate */
    if (reg_X.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_X.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_dey(void) {
    reg_Y.data--;
    /* set zero flag if appropriate */
    if (reg_Y.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_Y.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

