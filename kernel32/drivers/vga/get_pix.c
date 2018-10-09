#include <vga.h>

unsigned short get_pix(unsigned int x,unsigned int y)
{
	return vidmem[x+y*COL];
}

