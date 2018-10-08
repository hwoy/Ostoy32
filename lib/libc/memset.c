#include <string.h>
void *memset( void *dest, int ch, unsigned int count)
{
  return smemset(dest,ch,count);
}
