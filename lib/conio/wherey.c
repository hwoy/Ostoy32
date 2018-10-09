#include <conio.h>
#include <vga.h>

unsigned int wherey( void )
{
	unsigned int x,y;
	get_cur(&x,&y);
	return y+1;
}
