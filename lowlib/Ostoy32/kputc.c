#include <Ostoy32.h>


void kputc(char ch,unsigned int x,unsigned int y)
{
SREG32 reg;
reg.eax=sys_kputc;
reg.ebx=ch;
reg.ecx=x;
reg.edx=y;


scall(&reg);
}
