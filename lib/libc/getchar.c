
#include <stdio.h>

int getchar(void)
{
	char buff[64];
	gets(buff);
	
	return buff[0];	
}

