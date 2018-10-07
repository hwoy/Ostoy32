#include <stdlib.h>
#include <string.h>

static unsigned int pow2a(unsigned int num,int base);
static long int st2l(const char *nptr,char **endptr,int base,const char *pl);


long int strtol(const char *nptr, char **endptr, int base)
{
	long int result;
	
	
	switch(base)
	{
		case 2: result=st2l(nptr,endptr,2,"01");break;
		case 8: result=st2l(nptr,endptr,8,"01234567");break;
		case 10: result=st2l(nptr,endptr,10,"0123456789");break;
		case 16: result=st2l(nptr,endptr,16,"0123456789abcdef");break;
		default: result=st2l(nptr,endptr,10,"0123456789");
	}
	

	return result;
	
}

static long int st2l(const char *nptr,char **endptr,int base,const char *pl)
{
	long int minus=1,i=0,j,k,result;
	
		if(nptr[i]=='-')
	{
		minus=-1;
		i++;
	}
	else if(nptr[i]=='+')
	{
		minus=1;
		i++;
	}
	
	if((!strncmp(&nptr[i],"0x",2)) && (base==16))
	{
		
		i+=2;
	}
	
	
	for(j=i;nptr[j];j++)
	{
		
		for(k=0;pl[k];k++)
	{
		if(nptr[j]==pl[k]){break;}
	}
	
	if(!pl[k])
	{
		{break;}
	}
		
	}
	
	
	
	for(result=0;i<j;i++)
	{
		for(k=0;pl[k];k++)
	{
		if(nptr[i]==pl[k])
		{
			result+=k*pow2a(j-i-1,base); break;
		}
	}
	
	}
	
	if((endptr!=NULL))
	{
		*endptr=(char *)nptr+j;
	}



	
	return minus*result;
	
	
}

static unsigned int pow2a(unsigned int num,int base)
{
	unsigned int i,result=1;
	
	for(i=0;i<num;i++)
	{
		result*=base;
	}
	
	return result;
}

