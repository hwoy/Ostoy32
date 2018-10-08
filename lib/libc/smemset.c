#include <string.h>
void  *smemset(void *des,char ch,unsigned int count)
{
  unsigned char *cdes;
  cdes=(unsigned char *)des;

    while(count--)
    *cdes++=ch;
    
  return des;
}
