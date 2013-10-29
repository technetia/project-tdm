#include "registers.h"

/* ---
Function definitions.
--- */

void init_psr(ProcessorStatusRegister *psr) {
    psr->data.reg = 0x00;
}

