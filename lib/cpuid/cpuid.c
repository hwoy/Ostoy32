#include <cpuid.h>
REG *cpuid(unsigned int mode , REG *reg)
{
	__asm__ volatile("cpuid":"=a"(reg->r32.eax),"=b"(reg->r32.ebx),"=c"(reg->r32.ecx),"=d"(reg->r32.edx):"a"(mode));
	return reg;
}
