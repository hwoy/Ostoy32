#include <string.h>
void *memcpy(void *des,const void *src,unsigned int count)
{

  unsigned char *cdes,*csrc;
  cdes=(unsigned char *)des;
  csrc=(unsigned char *)src;

	while(count--)
	{
		*cdes++=*csrc++;
	}
  return des;
}
