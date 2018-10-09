#include <Ostoy32.h>


void set_fg(unsigned short color,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
	unsigned int j,i;
	unsigned short tmp;
	for(i=y1;i<=y2;i++)
	{
		for(j=x1;j<=x2;j++)
		{
			tmp=get_pix(j,i);
			pix(j,i,(tmp&0xf000)>>12,color,tmp&0x00ff);
		}
	}
}
