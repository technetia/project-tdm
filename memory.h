#ifndef __PROJECT_TDM__MEMORY_H__
#define __PROJECT_TDM__MEMORY_H__

/* ---
The 6502 can address 64KB (65536 bytes) of memory, so we will allocate
exactly that.

The 6502 divides memory into 256 pages of 256 bytes each. Some of these
pages are special.

Page 0 (0x0000-0x00FF)
- in 64K of memory, addressing requires 2 bytes; omitting the high-order
byte will make the 6502 assume you mean this page of memory, so this page
gets used a lot

Page 1 (0x0100-0x01FF)
- reserved for stack

Page 255 (0xFF00-0xFFFF)
- to be figured out
*/

char MEMORY_BLOCK[65536];

#endif /* __PROJECT_TDM__MEMORY_H__ */

