/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */

#ifndef __KPRINTF_H__
#define __KPRINTF_H__

enum KP_LEVEL {KPL_DUMP, KPL_PANIC};

int kprintf(enum KP_LEVEL, const char *fmt, ...);
int kputchar(int ch, unsigned short fg, unsigned short bg);

#endif
