#ifndef __PROJECT_TDM__STACK_INSTRUCTIONS_H__
#define __PROJECT_TDM__STACK_INSTRUCTIONS_H__

/* ---
TSX

Transfers the contents of the stack pointer to register X.
--- */
void instr_tsx(void);

/* ---
TXS

Transfers the contents of register X to the stack pointer.
--- */
void instr_txs(void);

/* ---
PHA

Pushes a copy of the accumulator register contents onto the stack.
--- */
void instr_pha(void);

/* ---
PHP

Pushes a copy of the processor status register contents onto the stack.
--- */
void instr_php(void);

/* ---
PLA

Pops the top of the stack and loads the contents into the accumulator register.
--- */
void instr_pla(void);

/* ---
PLP

Pops the top of the stack and loads the contents into the processor status
register.
--- */
void instr_plp(void);

#endif /* __PROJECt_TDM__STACK_INSTRUCTIONS_H__ */

