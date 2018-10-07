#include <Ostoy32.h>


unsigned int set_cur(unsigned int x,unsigned int y)
{
SREG32 reg;
reg.eax=sys_set_cur;
reg.ebx=x;
reg.ecx=y;

return scall(&reg);
}
