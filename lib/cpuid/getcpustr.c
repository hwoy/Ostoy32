#include "cpuid.h"

char *getcpustr(cpustr strbuff)
{
REG reg;
cpuid(0,&reg);
*((unsigned int *)strbuff+0)=reg.r32.ebx;
*((unsigned int *)strbuff+1)=reg.r32.edx;
*((unsigned int *)strbuff+2)=reg.r32.ecx;

*((char *)strbuff+12)=0;

return strbuff;

}



