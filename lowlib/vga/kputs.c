#include "vga.h"
#include "asm.h"


void kputs(const char *str,unsigned int x,unsigned int y)
{
  unsigned int i;
  for(i=0;str[i];i++)
  {
    vidmem[i+x+y*COL] = (vidmem[i+x+y*COL] & 0xff00)|str[i];
  }

}
