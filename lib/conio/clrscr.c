#include <conio.h>
#include <vga.h>

void         clrscr( void )
{
	unsigned int x,y;
	for(y=0;y<ROW;y++)
	{
		for(x=0;x<COL;x++)
		{
			pix(x,y,BLACK,LIGHTGRAY,0);
		}
	}
	gotoxy(1,1);
}
