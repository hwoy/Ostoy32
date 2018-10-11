#ifndef __STDLIB_H__
#define __STDLIB_H__


#ifdef __cplusplus
extern "C" {
#endif

int abs(int num);
long int strtol(const char *nptr, char **endptr, int base);
int atoi(const char *str);
unsigned int rand(void);
void srand(unsigned int seed);

#ifdef __cplusplus
extern }
#endif

#define atol atoi

#ifndef NULL
#define NULL ((void *)0)
#endif

#endif
