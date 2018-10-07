#include <string.h>
void *memcpy(void *des,const void *src,unsigned int count)
{
  void *tmp;
  char *cdes,*csrc;
  cdes=(char *)des;
  csrc=(char *)src;
  tmp=des;
	while(count--)
	{
		*cdes++=*csrc++;
	}
  return(tmp);
}
