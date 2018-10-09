#include <Ostoy32.h>


void kputs(const char *str,unsigned int x,unsigned int y)
{
SREG32 reg;
reg.eax=sys_kputs;
reg.ebx=(unsigned int)str;
reg.ecx=x;
reg.edx=y;


scall(&reg);

}
