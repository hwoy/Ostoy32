#include <Ostoy32.h>


void pix(unsigned int x,unsigned int y,unsigned short bg,unsigned short fg,char ch)
{
SREG32 reg;
reg.eax=sys_pix;
reg.ebx=x;
reg.ecx=y;
reg.edx=bg;
reg.esi=fg;
reg.edi=ch;

scall(&reg);
}

