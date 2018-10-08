#include <string.h>
const void* memchr( const void* ptr, int ch, unsigned int count )
{
	unsigned int i;
	for(i=0;i<count && ((unsigned char*)ptr)[i];++i)
		if(((unsigned char*)ptr)[i] == ch) return ptr+i;

	return NULL;
}
