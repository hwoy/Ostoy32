#include <vga.h>
#include <stdio.h>


static void putnl(void);

int putchar(int ch)
{
		unsigned int x,y;
		
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

		if((x+HTAB)>=(COL-1))
		{
			x=COL-1;	
		}
		else
		{
			x+=HTAB;
		}
		set_cur(x,y);
		kputc(SPACEBAR,x,y);
		return (unsigned char)ch;  	

	}
	
	else if(ch=='\b')
	{	
		if(x==0)
		{
			if(y!=0)
			{
				y--;
				
				for(x=COL-1;x>0;x--)
				{
					if(get_pix(x,y)&0x00ff) 
					{x=((get_pix(x,y)&0x00ff)==SPACEBAR)||(x>=COL-1) ?  x    :   x+1    ;break;}
				}
			}
			
		}
		else
		{
			if( ((get_pix(x,y)&0x00ff)==SPACEBAR) || ((get_pix(x-1,y)&0x00ff)==0) )
			{
				kputc('\0',x,y);
				for(x=x-1;x>0;x--)
				{
					if(get_pix(x,y)&0x00ff) {break;}
				}
				
				
				if(((get_pix(x,y)&0x00ff)!=SPACEBAR) || ((get_pix(x+1,y)&0x00ff)!=0))
				{
				if( (get_pix(x,y)&0x00ff)!=0)
				x++;
				}
			}
			else
			{
				x--;
			}
			
		}
		kputc('\0',x,y);
		set_cur(x,y);
		return (unsigned char)ch;
	}
	
	
	kputc(ch,x,y);
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
