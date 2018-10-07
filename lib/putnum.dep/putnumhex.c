#include <putnum.h>
#include <stdio.h>

void putnumhex(unsigned int num)
{
  char buff[20];
  printf(parsenum(buff,num,16,"0123456789ABCDEF"));
}

