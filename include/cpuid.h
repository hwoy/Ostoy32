#ifndef __CPUID_H__
#define __CPUID_H__

typedef struct _reg16
{
unsigned short ax,ax_hi;
unsigned short bx,bx_hi;
unsigned short cx,cx_hi;
unsigned short dx,dx_hi;
}REG16;

typedef struct _reg32
{
unsigned int eax;
unsigned int ebx;
unsigned int ecx;
unsigned int edx;
}REG32;


typedef union _reg
{
REG16 r16;
REG32 r32;
}REG;

typedef char cpuextstr[4*4*3+1];
typedef char cpustr[13];

#ifdef __cplusplus
extern "C" {
#endif

REG *cpuid(unsigned int mode , REG *reg);

char *getcpustr(cpustr strbuff);

char *getcpuextstr(cpuextstr strbuff);

#ifdef __cplusplus
extern }
#endif

#endif
