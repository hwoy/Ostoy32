#include <conio.h>
#include <stdint.h>
#include <stdio.h>
#include <kb.h>

int 		getche(void)
{
	int ch;
	putchar(ch=get_char());
	return ch;
}
