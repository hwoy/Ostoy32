#include <string.h>
int memcmp(const void*str1,const void*str2,unsigned int n)
{
	unsigned int i;
	int d;
	
	
	for(i=0; i<n ; i++)
	{
		if((d=(((unsigned char*)str1)[i]-((unsigned char*)str2)[i])!=0)) {return d;}
	}
	return 0;
}
