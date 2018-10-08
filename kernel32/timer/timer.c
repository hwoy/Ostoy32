/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */
#include <asm.h>


volatile unsigned long timer_ticks = 0;


void do_timer(void) {
	++timer_ticks;
	outportb(0x20, 0x20);
}

