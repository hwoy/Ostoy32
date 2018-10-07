#include <string.h>
int strcmp(const char *str1,const char *str2)
{
	unsigned int i;
	int d;
	
	for(i=0; str1[i] || str2[i] ; i++)
	{
		if((d=(str1[i]-str2[i])!=0)) {return d;}
	}
	return 0;
}
