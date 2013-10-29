#ifndef __PROJECT_TDM__REGISTERS_H__
#define __PROJECT_TDM__REGISTERS_H__

/* ---
Structure declarations.
--- */

/*
General-purpose registers.

The 6502 has three of these.
*/
typedef struct GeneralRegister {
    unsigned char data;
} GeneralRegister;

/*
Special-purpose registers.

The 6502 has two of these.
*/
typedef struct SpecialRegister {
    unsigned char data;
} SpecialRegister;

/*
Processor status register.

Not directly accessible by any 6502 instruction.

However, each bit is a flag that can be tested by the 6502 instructions.
*/
typedef struct ProcessorStatusRegister {
    union {
        unsigned char reg;
        struct {
#if defined( _BIG_ENDIAN ) || BYTE_ORDER == BIG_ENDIAN
            /*
            BIT 0
            C - carry
            1 if last add produced carry/last subtract produced borrow;
            also holds bits after logical shift
            */
            unsigned char C : 1;
            /*
            BIT 1
            Z - zero
            1 if result of last operation was 0
            */
            unsigned char Z : 1;
            /*
            BIT 2
            I - IRQ disable
            1 if maskable interrupts are disabled
            */
            unsigned char I : 1;
            /*
            BIT 3
            D - decimal mode
            1 if decimal mode active
            */
            unsigned char D : 1;
            /*
            BIT 4
            B - BRK command
            1 if interrupt caused by a BRK command
            reset when caused by external interrupt
            */
            unsigned char B : 1;
            /*
            BIT 5
            X - unused
            */
            unsigned char X : 1;
            /*
            BIT 6
            V - overflow
            1 if adding two like-signed numbers or
            subtracting two unlike-signed numbers results
            in a number < -128, or > 127
            */
            unsigned char V : 1;
            /*
            BIT 7
            N - negative
            - 1 if bit 7 of accumulator is set
            */
            unsigned char N : 1;
#else /* little endian architecture */
            unsigned char N : 1;
            unsigned char V : 1;
            unsigned char X : 1;
            unsigned char B : 1;
            unsigned char D : 1;
            unsigned char I : 1;
            unsigned char Z : 1;
            unsigned char C : 1;
#endif
        } flags;
    } data;
} ProcessorStatusRegister;

/* ---
Function declarations.
---*/

void init_psr(ProcessorStatusRegister *);

#endif /* __PROJECT_TDM__REGISTERS_H__ */

