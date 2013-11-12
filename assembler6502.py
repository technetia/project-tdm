#! /usr/bin/env python

from assembler6502_tokenizer import scan

def main():
    code = """
    ; sample code
    beginning:
    ADC ($44, X)
    """
    for line in code.split("\n"):
        for t in scan(line):
            print t

if __name__ == "__main__":
    main()

