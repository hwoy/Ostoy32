#include <conio.h>
#include <vga.h>

void  gotoxy( unsigned int __x, unsigned int __y )
{
	set_cur(__x-1,__y-1);
}
