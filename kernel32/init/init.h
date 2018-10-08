#ifndef __INIT_H__
#define __INIT_H__

#include <kernel.h>


static void isr_entry(int index, uint64_t offset);
static void idt_install(void);
static void sys_call_install(void);
static void pic_install(void);
static void kb_install(void);
static void timer_install(unsigned int hz);
static void setclr(void);

void init(uint8_t driveno);


struct DESCR 
{
	uint16_t length;
	uint32_t address;
} __attribute__((packed));


uint64_t *idt = ((uint64_t *)IDT_ADDR);
uint64_t *gdt = ((uint64_t *)GDT_ADDR);
#endif
