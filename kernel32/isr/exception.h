#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */
 
#define cli() __asm__ ("cli\n\t")
#define sti() __asm__ ("sti\n\t")

#define halt() __asm__ ("cli;hlt\n\t");
#define idle() __asm__ ("jmp .\n\t");


void divide_error(void); 

void debug_exception(void) ;

void breakpoint(void); 


void nmi(void) ;

void overflow(void) ;

void bounds_check(void) ;

void invalid_opcode(void) ;

void cop_not_avalid(void) ;

void double_fault(void) ;

void overrun(void) ;

void invalid_tss(void) ;

void seg_not_present(void) ;

void stack_exception(void) ;

void general_protection(void) ;

void page_fault(void) ;

void reversed(void) ;

void coprocessor_error(void);

void
info(enum KP_LEVEL kl, 
	 unsigned int ret_ip, unsigned int ss, unsigned int gs, unsigned int fs, 
	 unsigned int es, unsigned int ds, unsigned int edi, unsigned int esi, 
	 unsigned int ebp, unsigned int esp, unsigned int ebx, unsigned int edx, 
	 unsigned int ecx, unsigned int eax, unsigned int isr_nr, unsigned int err,
	 unsigned int eip, unsigned int cs, unsigned int eflags,
	 unsigned int old_esp, unsigned int old_ss);

#endif
