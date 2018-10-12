#include <vga.h>
#include <asm.h>


void disablecursor(int _bool)
{
	unsigned char tmp;
	
	outportb(0xa,0x3d4);
	tmp=inportb(0x3d5);
	if(_bool)
	{
		tmp|=(1<<5);
	}
	else
	{
		tmp&=(~(1<<5));
	}
	outportb(0xa,0x3d4);
	outportb(tmp,0x3d5);
}
