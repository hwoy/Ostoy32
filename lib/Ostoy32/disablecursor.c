#include <Ostoy32.h>


void disablecursor(int bool)
{
SREG32 reg;
reg.eax=sys_disablecursor;
reg.ebx=bool;
scall(&reg);
}
