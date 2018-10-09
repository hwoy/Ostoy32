#include <timer.h>

extern volatile unsigned long timer_ticks;

unsigned int get_timetick(void)
{
volatile unsigned int tmp;

#ifdef _SYSCALL_
__asm__ volatile("sti");
#endif


tmp=timer_ticks;

#ifdef _SYSCALL_
__asm__ volatile("cli");
#endif

return tmp;
}
