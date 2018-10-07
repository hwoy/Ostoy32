#ifndef __INIT_H__
#define __INIT_H__

/*
#define IDT_ADDR	0x80000
#define IDT_SIZE	(256*8)
#define GDT_ADDR	((IDT_ADDR)+IDT_SIZE)
#define CODE_SEL	0x08
*/


static void isr_entry(int index, uint64_t offset);
static void  idt_install(void);
static void sys_call_install(void);
static void pic_install(void);
static void setclr(void);
void init(uint8_t driveno);
void kb_install(void);
void timer_install(unsigned int hz);

	struct DESCR 
	{
		uint16_t length;
		uint32_t address;
	} __attribute__((packed));


uint64_t *idt = ((uint64_t *)IDT_ADDR);
uint64_t *gdt = ((uint64_t *)GDT_ADDR);
#endif
