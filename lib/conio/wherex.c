#include <conio.h>
#include <vga.h>

unsigned int          wherex( void )
{
	unsigned int x,y;
	get_cur(&x,&y);
	return x+1;
}
