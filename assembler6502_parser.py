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
    assert len(tokens) == 0
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
    """
    Opcode STA.

    Stores a value from memory into the accumulator.
    """
    assert len(tokens) in (1, 3, 5)

    if len(tokens) == 1:
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"] \
                or tokens[0].type == tokenizer.TOKEN_TYPES["LONGINT"]
        
        sta_int = tokens[0].lexeme.lstrip("$")
        if tokens[0].type == tokenizer.TOKEN_TYPES["INT"]:
            # zero page
            return ("85", sta_int)
        else:
            # absolute
            return ("8D", sta_int[:2], sta_int[2:])
    elif len(tokens) == 3:
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"] \
                or tokens[0].type == tokenizer.TOKEN_TYPES["LONGINT"]
        assert tokens[1].type == tokenizer.TOKEN_TYPES["COMMA"]
        assert tokens[2].type == tokenizer.TOKEN_TYPES["IDENT"]
        if tokens[0].type == tokenizer.TOKEN_TYPES["INT"]:
            assert tokens[2].lexeme.upper() == "X"
        else:
            assert tokens[2].lexeme.upper() == "X" or tokens[2].lexeme.upper() == "Y"

        sta_int = tokens[0].lexeme.lstrip("$")
        if tokens[0].type == tokenizer.TOKEN_TYPES["INT"]:
            # zero page X
            return ("95", sta_int)
        else:
            if tokens[2].lexeme.upper() == "X":
                # absolute X
                return ("9D", sta_int[:2], sta_int[2:])
            else:
                # absolute Y
                return ("99", sta_int[:2], sta_int[2:])
    else:
        assert tokens[0].type == tokenizer.TOKEN_TYPES["LPAREN"]
        assert tokens[1].type == tokenizer.TOKEN_TYPES["INT"]
        assert tokens[2].type == tokenizer.TOKEN_TYPES["COMMA"] \
                or tokens[2].type == tokenizer.TOKEN_TYPES["RPAREN"]
        if tokens[2].type == tokenizer.TOKEN_TYPES["COMMA"]:
            assert tokens[3].type == tokenizer.TOKEN_TYPES["IDENT"]
            assert tokens[3].lexeme.upper() == "X"
            assert tokens[4].type == tokenizer.TOKEN_TYPES["RPAREN"]
        else:
            assert tokens[3].type == tokenizer.TOKEN_TYPES["COMMA"]
            assert tokens[4].type == tokenizer.TOKEN_TYPES["IDENT"]
            assert tokens[4].lexeme.upper() == "Y"

        if tokens[2].type == tokenizer.TOKEN_TYPES["COMMA"]:
            # indirect X
            return ("81", tokens[1].lexeme.lstrip("$"))
        else:
            # indirect Y
            return ("91", tokens[1].lexeme.lstrip("$"))

def _parse_opcode_stx(tokens):
    """
    Opcode STX.

    Stores a value from memory into the X register.
    """
    assert len(tokens) in (1, 3)

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
        assert tokens[2].lexeme.upper() == "Y"
        return ("96", stx_int)

def _parse_opcode_sty(tokens):
    """
    Opcode STY.

    Stores a value from memory into the Y register.
    """
    assert len(tokens) == 1 or len(tokens) == 3

    sty_int = tokens[0].lexeme.lstrip("$")
    if len(tokens) == 1:
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"] \
                or tokens[0].type == tokenizer.TOKEN_TYPES["LONGINT"]

        if tokens[0].type == tokenizer.TOKEN_TYPES["INT"]:
            # zero page
            return ("84", sty_int)
        else:
            # absolute
            return ("8C", sty_int[:2], sty_int[2:])
    else:
        # zero page X
        assert tokens[0].type == tokenizer.TOKEN_TYPES["INT"]
        assert tokens[1].type == tokenizer.TOKEN_TYPES["COMMA"]
        assert tokens[2].type == tokenizer.TOKEN_TYPES["IDENT"]
        assert tokens[2].lexeme.upper() == "X"
        return ("94", sty_int)

def _parse_opcode_tsx(tokens):
    """
    Opcode TSX.

    Transfers contents of stack pointer to X.
    """
    assert len(tokens) == 0
    return ("BA",)

def _parse_opcode_txs(tokens):
    """
    Opcode TXS.

    Transfers contents of X to stack pointer.
    """
    assert len(tokens) == 0
    return ("9A",)

def _parse_opcode(tokens):
    op_token = tokens[0]
    try:
        # look up appropriate opcode function and retrieve hexcodes
        hexcodes = globals()[
                "_parse_opcode_{}".format(op_token.lexeme.lower())](tokens[1:])
    except(KeyError):
        # opcode doesn't exist, syntax error
        raise ParseError("Invalid opcode {}".format(op_token.lexeme))
    else:
        return hexcodes

def parse_line(line):
    # tokenize line of code
    tokens = tokenizer.scan(line)
    # if not a blank line
    if tokens:
        start_token = tokens[0]
        # if the initial token(s) is/are label(s)
        while start_token.type == tokenizer.TOKEN_TYPES["LABEL"]:
            try:
                # see if there's anything after
                start_token = tokens[1]
            except(IndexError):
                # line with label(s) only, done processing
                return tuple()
            else:
                # otherwise line is basically equivalent without label
                del tokens[0]

        # if the first (second) token is an identifier (opcode)
        if start_token.type == tokenizer.TOKEN_TYPES["IDENT"]:
            # obtain the hexcodes from parsing the opcode
            hexcodes = _parse_opcode(tokens)
        else:
            # otherwise the line is syntactically invalid
            raise ParseError("Invalid starting token {}".format(start_token.lexeme))

        return hexcodes

    return tuple()

