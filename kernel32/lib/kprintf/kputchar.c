#include <whitespace.h>
#include <vga.h>
#include <kprintf.h>


static void putnl(void);
static void box(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short bg,unsigned short fg);
int kputchar(int ch, unsigned short bg, unsigned short fg)
{
		unsigned int x,y,tmp;
		
		get_cur(&x,&y);
		
		 if(ch=='\n')
		{
			putnl();
			return (unsigned char)ch;
		}
		
	else if(ch=='\r')
	{	
		set_cur(0,y);
		return (unsigned char)ch;
	}
		
	else if(ch=='\t')
	{
		if(x>=COL-1)
		{
			return -1;
		}
		
		tmp=x;
		if((x+HTAB)>=(COL-1))
		{
			x=COL-1;	
		}
		else
		{
			x+=HTAB;
		}
		
		
		box(tmp,y,x-1,y,bg,fg);
		set_cur(x,y);
		kputc(SPACEBAR,x,y);
		return (unsigned char)ch;  	

	}
	
	
	
	pix(x,y,bg,fg,ch);
	if(x>=COL-1)
	{
		if(y>=ROW-1)
		{
			scrollup(1);
			y=ROW-1;
		}
		else
		{
			y++;
		}
		x=0;
		
	}
	else
	{
		x++;
	}
	
		set_cur(x,y);
		
		return (unsigned char)ch;
}

static void putnl(void)
{
unsigned int x,y;
get_cur(&x,&y);
if(y>=(ROW-1))
{
	scrollup(1);
	y=ROW-1;
}
else
{
	y++;
}
set_cur(0,y);
}

static void box(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned short bg,unsigned short fg)
{
	unsigned int x,y;
	
	for(y=y1;y<=y2;y++)
	{
		for(x=x1;x<=x2;x++)
		{
			pix(x,y,bg,fg,0);
		}
	}
}
