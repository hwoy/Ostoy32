#ifndef __STRING_H__
#define __STRING_H__

#ifdef __cplusplus
extern "C" {
#endif

const void* memchr( const void* ptr, int ch, unsigned int count );

void *memset( void *dest, int ch, unsigned int count);

void *memcpy(void *des,const void *src,unsigned int count);

int memcmp(const void*str1,const void*str2,unsigned int n);

void  *smemset(void *des,char ch,unsigned int count);



unsigned int  strlen(const char *str) ;

int strcmp(const char *str1,const char *str2);

char *strcpy( char *dest, const char *src );

int strncmp(const char *str1,const char *str2,unsigned int n);

const char *strchr( const char *str, int ch );

#ifdef __cplusplus
extern }
#endif


#ifndef NULL
#define NULL ((void *)0)
#endif


#endif

