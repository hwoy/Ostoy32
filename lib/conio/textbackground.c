#include <conio.h>
#include <vga.h>

void textbackground( unsigned short __newcolor )
{
	
	set_bg(__newcolor,0,0,COL-1,ROW-1);

}
