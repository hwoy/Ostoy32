#include <timer.h>

extern volatile unsigned long timer_ticks;

void delay(unsigned int interval)
{
volatile unsigned int tmp,tmp2;
tmp=timer_ticks+interval;

#ifdef _SYSCALL_
__asm__ volatile("sti");
#endif


while((tmp2=timer_ticks)<=tmp);

#ifdef _SYSCALL_
__asm__ volatile("cli");
#endif


}
