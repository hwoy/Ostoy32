#include "cpuid.h"

char *getcpuextstr(cpuextstr strbuff)
{
REG reg;
unsigned int i,j;
cpuid(0x80000000,&reg);
if(reg.r32.eax<0x80000004)
{
return (char *)0;
}
for(i=0x80000002,j=0;i<=0x80000004;i++,j+=4)
{
cpuid(i,&reg);
*((unsigned int *)strbuff+0+j)=reg.r32.eax;
*((unsigned int *)strbuff+1+j)=reg.r32.ebx;
*((unsigned int *)strbuff+2+j)=reg.r32.ecx;
*((unsigned int *)strbuff+3+j)=reg.r32.edx;
}

*((char *)strbuff+j*4)=0;

return strbuff;

}



