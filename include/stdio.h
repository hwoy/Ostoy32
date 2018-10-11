#ifndef __STDIO_H__
#define __STDIO_H__

#ifdef __cplusplus
extern "C" {
#endif

int puts(const char *str);

int putchar(int ch);

int printf(const char *fmt, ...);

char *gets(char *s);

int getchar(void);

#ifdef __cplusplus
extern }
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif


#endif
