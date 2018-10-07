#include <kprintf.h>
#include <stdarg.h>
#include <conio.h>
#include "putnum.h"




int kprintf(enum KP_LEVEL kl, const char *fmt, ...)
{
unsigned int i,count;
	struct KPC_STRUCT {
		unsigned short fg;
		unsigned short bg;
	} KPL[] = {
		{LIGHTGRAY, BLACK},
		{YELLOW, RED},
	};
	
va_list args;
va_start(args, fmt);

	for(i=0,count=0;fmt[i];i++)
	{
		
			 if(!strncmp(&fmt[i],"%u",2))
		{
			count+=putnum(kl,(unsigned int)va_arg(args, unsigned int));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%d",2))
		{
			count+=putnumint(kl,(int)va_arg(args, int));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%x",2))
		{
			count+=putnumhex(kl,(unsigned int)va_arg(args, unsigned int),0);
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%X",2))
		{
			count+=putnumhex(kl,(unsigned int)va_arg(args, unsigned int),1);
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%s",2))
		{
			count+=kprintf(kl,(char *)va_arg(args, char *));
			i++;
			continue;
		}
		
		else if(!strncmp(&fmt[i],"%c",2))
		{
			kputchar((int)va_arg(args, int),KPL[kl].bg,KPL[kl].fg);
			count++;
			i++;
			continue;
		}
		
		
			count++;

		
		
			kputchar(fmt[i],KPL[kl].bg,KPL[kl].fg);
	
	}
	
	va_end(args);
	return count;
}

