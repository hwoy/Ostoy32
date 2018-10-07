#include <Ostoy32.h>

unsigned short get_pix(unsigned int x,unsigned int y)
{
SREG32 reg;
reg.eax=sys_get_pix;
reg.ebx=x;
reg.ecx=y;

return scall(&reg);
}

