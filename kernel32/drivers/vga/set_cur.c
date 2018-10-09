#include <vga.h>
#include <asm.h>


unsigned int set_cur(unsigned int x,unsigned int y)
{
struct _xy_
  {
    unsigned char l;
    unsigned char h;
  }__attribute__((packed)) xy;
 *(unsigned short *)&xy=(unsigned short)(x+y*COL);
 
 #ifdef _INLINE_
  outb(0xe,0x3d4);
  outb(xy.h,0x3d5);
  outb(0xf,0x3d4);
  outb(xy.l,0x3d5);
  #else
  outportb(0xe,0x3d4);
  outportb(xy.h,0x3d5);
  outportb(0xf,0x3d4);
  outportb(xy.l,0x3d5);
  #endif
  
  return(*(unsigned short *)&xy);
}
