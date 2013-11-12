#ifndef __PROJECT_TDM__ADDRESSING_MODES_H__
#define __PROJECT_TDM__ADDRESSING_MODES_H__

typedef enum ADDR_MODE {
    /* ---
    implicit - when the processor needs no address info for
    this particular instruction, e.g. TXA
    */
    IMPLICIT,
    /* ---
    accumulator - operates directly on the accumulator register
    --- */
    ACCUM,
    /* ---
    immediate - directly specify an 8-bit constant
    --- */
    IMMEDIATE,
    /* ---
    zero page - like absolute, but high-order byte is taken as 0
    --- */
    ZERO,
    /* ---
    zero page X - like zero, but adds contents of register X to result
    (any result > 0xFF will be truncated to last byte)
    --- */
    ZERO_X,
    /* ---
    zero page Y - like zero X, except with register Y
    --- */
    ZERO_Y,
    /* ---
    relative - signed 8-bit relative offset added to PC for
    branching instructions (though since PC itself is incremented
    by 2 the effective range of jump is -126 to +129)
    --- */
    RELATIVE,
    /* ---
    absolute - two bytes specifying absolute address in memory
    --- */
    ABS,
    /* ---
    absolute X - like absolute, but adds contents of register X to result
    --- */
    ABS_X,
    /* ---
    absolute Y - like absolute X, except with register Y
    --- */
    ABS_Y,
    /* ---
    indirect - used only by JMP, indicates that the two bytes
    stored at the given address should be used (like a pointer)
    --- */
    INDIRECT,
    /* ---
    index indirect - address from instruction adds contents of X register,
    then uses the result (high-order byte truncated) as the least significant
    byte of the target address
    --- */
    IDX_INDIRECT,
    /* ---
    indirect index - gets least significant byte of 16-bit address stored
    in zero page location specified from instruction, then adds contents
    of Y register
    --- */
    INDIRECT_IDX
} ADDR_MODE;

#endif /* __PROJECT_TDM__ADDRESSING_MODES_H__ */

