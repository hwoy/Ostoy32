#include <conio.h>
#include <vga.h>

void         textcolor( unsigned short __newcolor )
{
	
	set_fg(__newcolor,0,0,COL-1,ROW-1);

}
