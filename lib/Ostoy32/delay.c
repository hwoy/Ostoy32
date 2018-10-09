#include <Ostoy32.h>

void delay(unsigned int interval)
{
SREG32 reg;
reg.eax=sys_delay;
reg.ebx=interval;
scall(&reg);
}
