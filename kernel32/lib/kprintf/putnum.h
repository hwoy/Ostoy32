#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static char * parsenum(char *buff,unsigned int num,unsigned int base,const char *numlist);
static unsigned int putnum(enum KP_LEVEL kl,unsigned int num);
static unsigned int putnumhex(enum KP_LEVEL kl,unsigned int num,int isbig);
static unsigned int putnumint(enum KP_LEVEL kl,int num);
static char *upperstr(char *str);
static char *lowerstr(char *str);

static char * parsenum(char *buff,unsigned int num,unsigned int base,const char *numlist)
{
  unsigned int i,j,k,l;
  char buff2[40];
  buff2[39]=0;
  i=38;
  k=num;
  
  do
  {
    l=k%base;
    k=k/base;
    buff2[i--]=numlist[l];
  }while(k);
  
  i++;
  j=0;
  
 do
 {
   buff[j++]=buff2[i++];
 }while(buff[j-1]);
 
 
  return(buff);
}

static unsigned int putnum(enum KP_LEVEL kl,unsigned int num)
{
  char buff[20];
  unsigned int i;
	
  i=strlen(parsenum(buff,num,10,"0123456789"));
  kprintf(kl,buff);
  return i;
}

static unsigned int putnumhex(enum KP_LEVEL kl,unsigned int num,int isbig)
{
  char buff[20];
  unsigned int i;
	
  static char pr[]="0123456789abcdef";
  
  if(isbig)
  {
	  upperstr(pr);	  
  }
  else
  {
	  lowerstr(pr);
  }
  
  i=strlen(parsenum(buff,num,16,pr));
  kprintf(kl,buff);
  return i;
}


static unsigned int putnumint(enum KP_LEVEL kl,int num)
{
  char buff[20];
  unsigned int i,j=0;
  if(num<0)
  {
	  buff[j++]='-';
	  num=abs(num);
  }
  parsenum(buff+j,num,10,"0123456789");
  i=strlen(buff);
  kprintf(kl,buff);
  return i;
}

static char *upperstr(char *str)
{
	unsigned int i;
	for(i=0;str[i];i++)
	{
		str[i]=toupper(str[i]);
	}
	
	return str;
}

static char *lowerstr(char *str)
{
	unsigned int i;
	for(i=0;str[i];i++)
	{
		str[i]=tolower(str[i]);
	}
	
	return str;
}





