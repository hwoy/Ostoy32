#include <string.h>
void  *smemset(void *des,char ch,unsigned int count)
{
  void *tmp;
  char *cdes;
  cdes=(char *)des;
  tmp=des;
    while(count--)
  {
    *cdes++=ch;
  }
  return(tmp);
}
