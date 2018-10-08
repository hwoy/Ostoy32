#include <vga.h>


void kputs(const char *str,unsigned int x,unsigned int y)
{
  unsigned int i;
  for(i=0;str[i];i++)
  {
    kputc(str[i],x+i,y);
  }

}
