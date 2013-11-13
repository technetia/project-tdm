#! /usr/bin/env python

import sys
import assembler6502_tokenizer as tokenizer
import assembler6502_parser as parser

def output_byte(hexcode):
    sys.stdout.write(hexcode)
    #sys.stdout.write(chr(int(hexcode, 16)))

def main():
    code = """
; sample code
beginning: jsr $5597
second:
    rts
    """
    for line in code.split("\n"):
        hexcodes = parser.parse_line(line)
        for hexcode in hexcodes:
            output_byte(hexcode)
    print

if __name__ == "__main__":
    main()

