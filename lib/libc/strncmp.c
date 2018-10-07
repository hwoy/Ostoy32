#include <string.h>
int strncmp(const char *str1,const char *str2,unsigned int n)
{
	unsigned int i;
	int d;
	
	
	for(i=0; i<n ; i++)
	{
		if((d=(str1[i]-str2[i])!=0)) {return d;}
	}
	return 0;
}
