#include "vga.h"
#include "asm.h"


void kputc(char ch,unsigned int x,unsigned int y)
{
vidmem[x+y*COL] = (vidmem[x+y*COL] & 0xff00)|ch;
}
