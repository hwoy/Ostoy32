#include <stdint.h>
#include <kb.h>

extern volatile char last_char;

int get_char(void)
{
volatile int ch;
last_char=-1;

#ifdef _SYSCALL_
__asm__ volatile("sti");
#endif


while((ch=last_char)==-1);

#ifdef _SYSCALL_
__asm__ volatile("cli");
#endif

return ch;

}
