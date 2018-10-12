#ifndef __CONFIG_H__
#define __CONFIG_H__

	#define FLOPPY 0x00
	#define HARDDISK 0x80
	#define SS 0x7fff
	#define SP 0x0e
	#define KERN 0x7c00
	#define VBR_ADDR 0x500

	#define STACK_ADDR 0x200000
	#define INIT_ADDR 0x300000
	#define APP_ADDR 0x400000
	
	#define APP_NSECT 16
	#define SETUP_NSECT 1
	#define INIT_NSECT 16
	#define MBR_NSECT 1
	
	#define ALL_NSECT (MBR_NSECT+SETUP_NSECT+INIT_NSECT+APP_NSECT)
	
	#define IDT_ADDR 0x80000
	#define IDT_SIZE (256*8)
	#define GDT_ADDR (IDT_ADDR+IDT_SIZE)
	#define GDT_ENTRIES 5
	#define GDT_SIZE (8*GDT_ENTRIES)
	#define DATA_SEL 0x10
	#define CODE_SEL 0x08

	#endif
