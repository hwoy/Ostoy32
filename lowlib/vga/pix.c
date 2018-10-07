#include "vga.h"
#include "asm.h"


void pix(unsigned int x,unsigned int y,unsigned short bg,unsigned short fg,char ch)
{

		vidmem[x+y*COL]=(vidmem[x+y*COL]&0x8fff)|(bg<<12);
	    vidmem[x+y*COL]=(vidmem[x+y*COL]&0xf0ff)|(fg<<8) ;
	    vidmem[x+y*COL]=(vidmem[x+y*COL]&0xff00)|ch;
}

