#include <Ostoy32.h>

uint8_t get_driveno(void)
{
SREG32 reg;
reg.eax=sys_get_driveno;

return scall(&reg);
}
