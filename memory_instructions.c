#include "memory_instructions.h"
#include "registers.h"
#include "memory.h"

void instr_lda(long value, ADDR_MODE mode) {
    switch (mode) {
        case IMMEDIATE:
            reg_A.data = (signed char)value;
            break;
        case ZERO:
        case ABS:
            reg_A.data = (signed char)MEMORY_BLOCK[value];
            break;
        case ABS_X:
            reg_A.data = (signed char)MEMORY_BLOCK[value + (unsigned char)reg_X.data];
            break;
        case ABS_Y:
            reg_A.data = (signed char)MEMORY_BLOCK[value + (unsigned char)reg_Y.data];
            break;
        case ZERO_X:
            break;
        case ZERO_Y:
            break;
        case IDX_INDIRECT:
            break;
        case INDIRECT_IDX:
            break;
        default:
            break;
    }
    /* set zero flag if appropriate */
    if (reg_A.data == 0x00) {
        reg_PSR.data.flags.Z = 1;
    }
    /* set negative flag if appropriate */
    if (reg_A.data & 0x10) {
        reg_PSR.data.flags.N = 1;
    }
}

void instr_sta(long value, ADDR_MODE mode) {
    switch (mode) {
        case ZERO:
        case ABS:
            MEMORY_BLOCK[value] = (char)reg_A.data;
            break;
        default:
            break;
    }
}

