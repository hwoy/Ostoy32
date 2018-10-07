#include <putnum.h>
#include <stdio.h>

void putnumbin(unsigned int num)
{
  char buff[40];
  printf(parsenum(buff,num,2,"01"));
}

