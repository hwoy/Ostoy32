#include <putnum.h>
#include <stdio.h>

void putnum(unsigned int num)
{
  char buff[20];
  printf(parsenum(buff,num,10,"0123456789"));
}

