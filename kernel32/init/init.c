#include <kernel.h>
#include <asm.h>
#include <vga.h>
#include "../isr/isr.h"
#include "init.h"
#include "../syscall/syscall.h"

volatile uint8_t drive_no;

void init(uint8_t driveno) 
{
	
	drive_no=driveno;
	
	idt_install();
	sys_call_install();
	pic_install();
	timer_install(HZ);
	kb_install();
	
	
	setclr();

	set_bg(BGC_GREEN,0,0,COL-1,ROW-1);
	set_fg(C_BLACK,0,0,COL-1,ROW-1);

	__asm__ volatile("sti");
}


static void  idt_install(void) {
	unsigned int i = 0;
	struct DESCR idt_descr = {256*8-1, IDT_ADDR};

	for (i=0; i<VALID_ISR; ++i)
		isr_entry(i, (unsigned int)(isr[(i<<1)+1]));
	for (++i; i<256; ++i)
		isr_entry(i, (unsigned int)default_isr);
	
	__asm__ volatile("lidt	%0\n\t"::"m"(idt_descr));
}



static void isr_entry(int index, uint64_t offset) {
	uint64_t idt_entry = 0x00008e0000000000ULL |
			((uint64_t)CODE_SEL<<16);
	idt_entry |= (offset<<32) & 0xffff000000000000ULL;
	idt_entry |= (offset) & 0xffff;
	idt[index] = idt_entry;
}

static void pic_install(void) {
	outportb(0x11, 0x20);
	outportb(0x11, 0xa0);
	outportb(0x20, 0x21);
	outportb(0x28, 0xa1);
	outportb(0x04, 0x21);
	outportb(0x02, 0xa1);
	outportb(0x01, 0x21);
	outportb(0x01, 0xa1);
	outportb(0xff, 0x21);
	outportb(0xff, 0xa1);
}


static void sys_call_install(void) 
{
	uint64_t sys_call_entry = 0x0000ef0000080000ULL |
			((uint64_t)CODE_SEL<<16);
	sys_call_entry |= ((uint64_t)((uint32_t)sys_call)<<32) & 
		0xffff000000000000ULL;
	sys_call_entry |= ((uint64_t)((uint32_t)sys_call)) & 0xffff;
	idt[SYS_CALL] = sys_call_entry;
}

static void timer_install(unsigned int hz) {
	unsigned int divisor = 1193180/hz;
	outportb(0x36, 0x43);
	outportb(divisor&0xff, 0x40);
	outportb(divisor>>8, 0x40);
	outportb(inportb(0x21)&0xfe, 0x21);
}

static void kb_install(void) {
	outportb(inportb(0x21)&0xfd, 0x21);
}

static void setclr(void)
{
	unsigned int x,y;
		for(y=0;y<ROW;y++)
	{
		for(x=0;x<COL;x++)
		{
			kputc(0,x,y);
		}
	}
	
	set_cur(0,0);
}
