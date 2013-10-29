#ifndef __PROJECT_TDM__FLAG_INSTRUCTIONS_H__
#define __PROJECT_TDM__FLAG_INSTRUCTIONS_H__

/* ---
CLC

Clears the carry bit flag in the PSR.
--- */
void instr_clc(void);

/* ---
SEC

Sets the carry bit flag in the PSR.
--- */
void instr_sec(void);

/* ---
CLI

Clears the interrupt bit flag in the PSR.
--- */
void instr_cli(void);

/* ---
SEI

Sets the interrupt bit flag in the PSR.
--- */
void instr_sei(void);

/* ---
CLV

Clears the overflow bit flag in the PSR.
--- */
void instr_clv(void);

/* ---
CLD

Clears the decimal bit flag in the PSR.
--- */
void instr_cld(void);

/* ---
SED

Sets the decimal bit flag in the PSR.
--- */
void instr_sed(void);

#endif /* __PROJECT_TDM__INSTRUCTIONS_H__ */

