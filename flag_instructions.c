#include "flag_instructions.h"
#include "registers.h"

void instr_clc() {
    reg_PSR.data.flags.C = 0;
}

void instr_sec() {
    reg_PSR.data.flags.C = 1;
}

void instr_cli() {
    reg_PSR.data.flags.I = 0;
}

void instr_sei() {
    reg_PSR.data.flags.I = 1;
}

void instr_clv() {
    reg_PSR.data.flags.V = 0;
}

void instr_cld() {
    reg_PSR.data.flags.D = 0;
}

void instr_sed() {
    reg_PSR.data.flags.D = 1;
}

