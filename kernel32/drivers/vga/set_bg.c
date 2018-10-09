#include <vga.h>

void set_bg(unsigned short color,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
	unsigned int j,i;
	unsigned short tmp;
	for(i=y1;i<=y2;i++)
	{
		for(j=x1;j<=x2;j++)
		{
			tmp=get_pix(j,i);
			pix(j,i,color,(tmp&0x0f00)>>8,tmp&0x00ff);
		}
	}
}
