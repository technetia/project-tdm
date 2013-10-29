#include "memory.h"
#include "registers.h"
#include "flag_instructions.h"
#include "register_instructions.h"
#include "misc_instructions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    init_registers();

    /* decrement register X by 1, should be -1 */
    printf(">> Begin 6502 emulation\n");
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_dex();
    printf("DEX\n");
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    instr_inx();
    printf("INX\n");
    printf("PSR Z: %d\n", reg_PSR.data.flags.Z);
    printf("PSR N: %d\n", reg_PSR.data.flags.N);
    return 0;
}

