#ifndef __STRING_H__
#define __STRING_H__

unsigned int  strlen(const char *str) ;

void *memcpy(void *des,const void *src,unsigned int count);

void  *smemset(void *des,char ch,unsigned int count);

int strcmp(const char *str1,const char *str2);

int strncmp(const char *str1,const char *str2,unsigned int n);


#ifndef NULL
#define NULL ((void *)0)
#endif


#endif

