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
    if not tokens or len(tokens) > 1:
        raise ParseError("Incorrect # of arguments for JSR (expected 1, got {})".format(len(tokens)))
    if tokens[0].type != tokenizer.TOKEN_TYPES["LONGINT"]:
        raise ParseError("Expected LONGINT for JSR")
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
    if tokens:
        raise ParseError("Too many arguments for RTI")
    return ("40",)

def _parse_opcode_rts(tokens):
    """
    Opcode RTS.

    Returns from a subroutine invoked by JSR.
    """
    if tokens:
        raise ParseError("Too many arguments for RTS")
    return ("60",)

def _parse_opcode_sbc(tokens):
    return 0

def _parse_opcode_sta(tokens):
    return 0

def _parse_opcode_stx(tokens):
    return 0

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

