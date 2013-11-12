#ifndef __PROJECT_TDM__MEMORY_INSTRUCTIONS_H__
#define __PROJECT_TDM__MEMORY_INSTRUCTIONS_H__

#include "addressing_modes.h"

/* ---
LDA

Loads the accumulator with a particular byte of memory.
--- */
void instr_lda(long, ADDR_MODE);

/* ---
LDX

Loads the X register with a particular byte of memory.
--- */
void instr_ldx(long, ADDR_MODE);

/* ---
LDY

Loads the Y register with a particular byte of memory.
--- */
void instr_ldy(long, ADDR_MODE);

/* ---
STA

Stores the contents of the accumulator into a byte of memory.
--- */
void instr_sta(long, ADDR_MODE);

/* ---
STX

Stores the contents of the X register into a byte of memory.
--- */
void instr_stx(long, ADDR_MODE);

/* ---
STY

Stores the contents of the Y register into a byte of memory.
--- */
void instr_sty(long, ADDR_MODE);

#endif /* __PROJECT_TDM__MEMORY_INSTRUCTIONS_H__ */

