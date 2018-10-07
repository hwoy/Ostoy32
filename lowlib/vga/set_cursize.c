#include <vga.h>
#include <asm.h>
void set_cursize(unsigned char begin,unsigned char end)
{
	unsigned char tmp;
outportb(0xa,0x3d4);
tmp=inportb(0x3d5);

tmp=(tmp&224)|begin;
outportb(0xa,0x3d4);
outportb(tmp,0x3d5);



outportb(0xb,0x3d4);
tmp=inportb(0x3d5);

tmp=(tmp&224)|end;
outportb(0xb,0x3d4);
outportb(tmp,0x3d5);
}
