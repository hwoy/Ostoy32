#ifndef __ISR_H__
#define __ISR_H__

/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */


void default_isr(void);

#define VALID_ISR	(32+2)

extern void (*isr[(VALID_ISR)<<1])(void);

#endif
