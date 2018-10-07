#include <stdio.h>
#include <stdarg.h>
#include "putnum.h"




int printf(const char *fmt, ...)
{
unsigned int i,count;
va_list args;
va_start(args, fmt);

	for(i=0,count=0;fmt[i];i++)
	{
		
			 if(!strncmp(&fmt[i],"%u",2))
		{
			count+=putnum((unsigned int)va_arg(args, unsigned int));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%d",2))
		{
			count+=putnumint((int)va_arg(args, int));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%x",2))
		{
			count+=putnumhex((unsigned int)va_arg(args, unsigned int),0);
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%X",2))
		{
			count+=putnumhex((unsigned int)va_arg(args, unsigned int),1);
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%s",2))
		{
			count+=printf((char *)va_arg(args, char *));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%c",2))
		{
			putchar((int)va_arg(args, int));
			count++;
			i++;
			continue;
		}
		
		
			count++;

		
		
			putchar(fmt[i]);
	
	}
	
	va_end(args);
	return count;
}

