/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */
#include <asm.h>


volatile unsigned long timer_ticks = 0;



void timer_install(unsigned int hz) {
	unsigned int divisor = 1193180/hz;
	outportb(0x36, 0x43);
	outportb(divisor&0xff, 0x40);
	outportb(divisor>>8, 0x40);
	outportb(inportb(0x21)&0xfe, 0x21);
}


void do_timer(void) {
	++timer_ticks;
	outportb(0x20, 0x20);
}



