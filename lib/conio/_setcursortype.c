#include <conio.h>
#include <vga.h>

void         _setcursortype( int __cur_t )
{
	switch(__cur_t)
	{
		case _NOCURSOR:							disablecursor(1);break;
		case _SOLIDCURSOR:						disablecursor(0);set_cursize(2,13);break;
		case _NORMALCURSOR:						disablecursor(0);set_cursize(0xe,0xf);break;
	}
}
