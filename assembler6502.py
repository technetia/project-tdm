#! /usr/bin/env python

import sys
import assembler6502_tokenizer as tokenizer
import assembler6502_parser as parser

def output_byte(hexcode):
    sys.stdout.write(hexcode + "\n")
    #sys.stdout.write(chr(int(hexcode, 16)))

def get_labels(code_lines):
    labels = {}
    pc = 0
    for line in code_lines:
        tokens = tokenizer.scan(line)
        while tokens and tokens[0].type == tokenizer.TOKEN_TYPES["LABEL"]:
            new_label = tokens[0].lexeme.rstrip(":")
            if new_label not in labels:
                labels[new_label] = pc
            else:
                raise parser.ParseError("Duplicate label {}".format(new_label))
            del tokens[0]
            pc += 1
    return labels

def assemble(code_lines, labels):
    for line in code_lines:
        hexcodes = parser.parse_line(line)
        for hexcode in hexcodes:
            output_byte(hexcode)

def main():
    code = sys.stdin.read()
    code_lines = code.split("\n")
    # obtain labels
    #labels = get_labels(code_lines)
    labels = {}
    # assemble
    assemble(code_lines, labels)

if __name__ == "__main__":
    main()

