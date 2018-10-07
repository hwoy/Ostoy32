#ifndef __ASM_H__
#define __ASM_H__

#include <stdint.h>
uint8_t inportb(uint16_t port);
void outportb(uint8_t data,uint16_t port);

	
#endif
