#include <Ostoy32.h>
void set_cursize(unsigned char begin,unsigned char end)
{
SREG32 reg;
reg.eax=sys_set_cursize;
reg.ebx=begin;
reg.ecx=end;

scall(&reg);
}
