#include <vga.h>

void scrollup(unsigned int nrow)
{
	unsigned int i,j,m,n;
	unsigned short tmp;

	for(i=nrow,m=0;i<ROW;i++,m++)
	{
		for(j=0,n=0;j<COL;j++,n++)
		{
			tmp=get_pix(j,i);
			pix(n,m,(tmp&0xf000)>>12,(tmp&0x0f00)>>8,(tmp&0x00ff));
		}
	}


	for(i=(ROW-nrow);i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			tmp=get_pix(j,i);
			pix(j,i,(tmp&0xf000)>>12,(tmp&0x0f00)>>8,0);
		}
	}

}
