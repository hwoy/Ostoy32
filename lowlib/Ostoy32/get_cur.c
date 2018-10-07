#include <Ostoy32.h>



unsigned int get_cur(unsigned int *x,unsigned int *y) 
{
SREG32 reg;
reg.eax=sys_get_cur;
reg.ebx=(unsigned int)x;
reg.ecx=(unsigned int)y;

return scall(&reg);
}
