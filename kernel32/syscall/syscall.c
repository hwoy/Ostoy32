/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */
#include "syscall.h"

void (*sys_call_table[VALID_SYSCALL])(void) = { \

sys_set_cur,\
sys_get_cur,\
sys_disablecursor,\
sys_kputs,\
sys_kputc,\
sys_set_cursize,\
sys_pix,\
sys_get_pix,\
sys_get_char,\
sys_get_driveno,\
sys_delay,\
sys_get_timetick\

};

