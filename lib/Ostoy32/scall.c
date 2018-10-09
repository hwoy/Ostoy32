#include <Ostoy32.h>
unsigned int scall(const SREG32 *reg)
{
	unsigned int tmp;
__asm__ volatile("int $0x80 \n\t movl %%eax,%0":"=m"(tmp):"a"(reg->eax),"b"(reg->ebx),"c"(reg->ecx),"d"(reg->edx),"S"(reg->esi),"D"(reg->edi));

	return tmp;
}

