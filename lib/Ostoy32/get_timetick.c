#include <Ostoy32.h>

extern volatile unsigned long timer_ticks;

unsigned int get_timetick(void)
{
SREG32 reg;
reg.eax=sys_get_timetick;
return scall(&reg);
}
