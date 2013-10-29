#ifndef __PROJECT_TDM__REGISTER_INSTRUCTIONS_H__
#define __PROJECT_TDM__REGISTER_INSTRUCTIONS_H__

/* ---
TAX

Transfers the contents of the accumulator register into register X.
--- */
void instr_tax(void);

/* ---
TAY

Transfers the contents of the accumulator register into register Y.
--- */
void instr_tay(void);

/* ---
TXA

Transfers the contents of register X into the accumulator register.
--- */
void instr_txa(void);

/* ---
TYA

Transfers the contents of register Y into the accumulator register.
--- */
void instr_tya(void);

/* ---
INX

Increments the value stored in register X by 1.
--- */
void instr_inx(void);

/* ---
INY

Increments the value stored in register Y by 1.
--- */
void instr_iny(void);

/* ---
DEX

Decrements the value stored in register X by 1.
--- */
void instr_dex(void);

/* ---
DEY

Decrements the value stored in register Y by 1.
--- */
void instr_dey(void);

#endif /* __PROJECT_TDM__REGISTER_INSTRUCTIONS_H__ */

