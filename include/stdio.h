#ifndef __STDIO_H__
#define __STDIO_H__

int puts(const char *str);

int putchar(int ch);

int printf(const char *fmt, ...);

char *gets(char *s);

int getchar(void);

#ifndef NULL
#define NULL ((void *)0)
#endif


#endif
