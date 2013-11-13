#! /usr/bin/env python

import assembler6502_tokenizer as tokenizer

class ParseError(Exception):
    pass


def _parse_opcode_adc(tokens):
    return 0

def _parse_opcode_and(tokens):
    return 0

def _parse_opcode_asl(tokens):
    return 0

def _parse_opcode_bit(tokens):
    return 0

def _parse_opcode_brk(tokens):
    return 0

def _parse_opcode_cmp(tokens):
    return 0

def _parse_opcode_cpx(tokens):
    return 0

def _parse_opcode_cpy(tokens):
    return 0

def _parse_opcode_dec(tokens):
    return 0

def _parse_opcode_eor(tokens):
    return 0

def _parse_opcode_inc(tokens):
    return 0

def _parse_opcode_jmp(tokens):
    return 0

def _parse_opcode_jsr(tokens):
    """
    Opcode JSR.

    Pushes the next instruction's address-1 onto the stack,
    then moves program control to argument.
    """
    assert len(tokens) == 1
    assert tokens[0].type == tokenizer.TOKEN_TYPES["LONGINT"]
    jsr_addr = tokens[0].lexeme.lstrip("$")
    return ("20", jsr_addr[:2], jsr_addr[2:])

def _parse_opcode_lda(tokens):
    return 0

def _parse_opcode_ldx(tokens):
    return 0

def _parse_opcode_ldy(tokens):
    return 0

def _parse_opcode_lsr(tokens):
    return 0

def _parse_opcode_nop(tokens):
    """
    Opcode NOP.

    Null instruction.
    """
    if tokens:
        raise ParseError("Too many arguments for NOP")
    return ("EA",)

def _parse_opcode_ora(tokens):
    return 0

def _parse_opcode_pha(tokens):
    return 0

def _parse_opcode_php(tokens):
    return 0

def _parse_opcode_pla(tokens):
    return 0

def _parse_opcode_plp(tokens):
    return 0

def _parse_opcode_rol(tokens):
    return 0

def _parse_opcode_ror(tokens):
    return 0

def _parse_opcode_rti(tokens):
    """
    Opcode RTI.

    Returns from an interrupt.
    """
    assert len(tokens) == 0
    return ("40",)

def _parse_opcode_rts(tokens):
    """
    Opcode RTS.

    Returns from a subroutine invoked by JSR.
    """
    assert len(tokens) == 0
    return ("60",)

def _parse_opcode_sbc(tokens):
    return 0

def _parse_opcode_sta(tokens):
    return 0

def _parse_opcode_stx(tokens):
    """
    Opcode STX.

    Stores a value from memory into the X register.
    """
    assert len(tokens) == 1 or len(tokens) == 3

    stx_int = tokens[0].lexeme.lstrip("$")
    if len(tokens) == 1:
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"] \
                or tokens[0].type == tokenizer.TOKEN_TYPES["LONGINT"]

        if tokens[0].type == tokenizer.TOKEN_TYPES["INT"]:
            # zero page
            return ("86", stx_int)
        else:
            # absolute
            return ("8E", stx_int[:2], stx_int[2:])
    else:
        # zero page Y
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"]
        assert tokens[1].type == tokenizer.TOKEN_TYPES["COMMA"]
        assert tokens[2].type == tokenizer.TOKEN_TYPES["IDENT"]
        assert tokens[2].lexeme == "Y"
        return ("96", stx_int)

def _parse_opcode_sty(tokens):
    return 0

def _parse_opcode_tsx(tokens):
    return 0

def _parse_opcode_txs(tokens):
    return 0

def _parse_opcode(tokens):
    op_token = tokens[0]
    try:
        hexcodes = globals()[
                "_parse_opcode_{}".format(op_token.lexeme.lower())](tokens[1:])
    except(KeyError):
        raise ParseError("Invalid opcode {}".format(op_token.lexeme))
    else:
        return hexcodes

def parse_line(line):
    tokens = tokenizer.scan(line)
    if tokens:
        start_token = tokens[0]
        if start_token.type == tokenizer.TOKEN_TYPES["LABEL"]:
            try:
                start_token = tokens[1]
            except(IndexError):
                # line with label only, done processing
                return tuple()
            else:
                del tokens[0]

        if start_token.type == tokenizer.TOKEN_TYPES["IDENT"]:
            hexcodes = _parse_opcode(tokens)
        else:
            raise ParseError("Invalid starting token {}".format(start_token.lexeme))

        return hexcodes

    return tuple()

