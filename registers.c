#include "registers.h"

void init_registers(void) {
    reg_A.data = 0x00;
    reg_X.data = 0x00;
    reg_Y.data = 0x00;
    reg_PSR.data.reg = 0x00;
    reg_PC.data = 0x00;

    /* stack pointer starts from 0x01FF and goes down */
    reg_SP.data = 0xFF;
    reg_SP.page_index = 0x01;
}

