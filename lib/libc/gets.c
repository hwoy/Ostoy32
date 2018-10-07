#include <stdint.h>
#include <kb.h>
#include <stdio.h>

char *gets(char *s)
{
	unsigned int i=0;
	int ch;
	if(!s) return NULL;
	
	do
	{
		ch=get_char();
		if(ch!='\n')
		{
			if(ch=='\b')
			{
				if(i!=0)
				{
					i--;
				}
				else
				{
					continue;
				}
			}
			else
			{
				s[i++]=ch;
			}
		}
		else
		{
			s[i]=0;;
		}

		putchar(ch);
	}
	while(ch!='\n');
	
	return s;
	
}

