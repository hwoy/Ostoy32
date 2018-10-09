#include <Ostoy32.h>
int get_char(void)
{
SREG32 reg;
reg.eax=sys_get_char;


return scall(&reg);
}
