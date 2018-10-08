#include <stdio.h>

int puts(const char *str)
{
unsigned int i;

for(i=0;str[i];i++)
{
	putchar(str[i]);
}

putchar('\n');
return i;
}

