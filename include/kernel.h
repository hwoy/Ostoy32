/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */
#ifndef __KERNEL_H__
#define __KERNEL_H__


/* code selector in gdt */
#define CODE_SEL	0x08

/* data and stack selecter in gdt */
#define DATA_SEL	0x10

/* code selector in ldt */
#define USER_CODE_SEL	0x07

/* data and stack selector in ldt */
#define USER_DATA_SEL	0x0f

/* IDT_ADDR and GDT_ADDR must align to 16 */
#define IDT_ADDR	0x80000
#define IDT_SIZE	(256*8)
#define GDT_ADDR	((IDT_ADDR)+IDT_SIZE)
#define GDT_ENTRIES	5
#define GDT_SIZE	(8*GDT_ENTRIES)
/* 
   NULL				0	0
   CODE_SEL			8	1
   DATA_SEL			10	2
   CURR_TASK_TSS	18	3
   CURR_TASK_LDT	20	4
 */
#define HD0_ADDR	(GDT_ADDR+GDT_SIZE)
#define HD0_SIZE	(4*8)

#define PAGE_DIR	(IDT_ADDR+(((HD0_ADDR+HD0_SIZE-IDT_ADDR)-1)/PAGE_SIZE+1)*PAGE_SIZE)

#define PAGE_SIZE	(4*1024)
#define PAGE_TABLE	(PAGE_DIR+PAGE_SIZE)
#define MEMORY_RANGE (4*1024*1024)

#define CURR_TASK_TSS 	3
#define	CURR_TASK_LDT	4

#define TSS_SEL		0x18
#define	LDT_SEL		0x20

#define TSS_SEL_STR	"0x18"
#define LDT_SEL_STR	"0x20"

#define HZ		1000
/*
extern unsigned long long *gdt;
extern unsigned long long *ldt;
*/

#endif
