#include <string.h>

const char *strchr( const char *str, int ch )
{
  return memchr(str,ch,strlen(str));
}

