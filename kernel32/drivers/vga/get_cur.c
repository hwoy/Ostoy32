#include <vga.h>
#include <asm.h>


unsigned int get_cur(unsigned int *x,unsigned int *y) 
{
  struct _xy_
  {
    unsigned char l;
    unsigned char h;
  }__attribute__((packed)) xy;

  #ifdef _INLINE_
  outb(0xe,0x3d4);
  inb(0x3d5,xy.h);
  outb(0xf,0x3d4);
  inb(0x3d5,xy.l);
  #else
  outportb(0xe,0x3d4);
  xy.h=inportb(0x3d5);
  outportb(0xf,0x3d4);
  xy.l=inportb(0x3d5);
  #endif
  
  *y=(*(unsigned short *)&xy)/COL;
  *x=(*(unsigned short *)&xy)%COL;
  return(*(unsigned short *)&xy);
}
