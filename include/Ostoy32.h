#ifndef __OSTOY32_H__
#define __OSTOY32_H__

#include <stdint.h>
#include <vga.h>
#include <kb.h>
#include <boot.h>
#include <timer.h>

typedef struct sreg32
{
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int esi;
    unsigned int edi;
}SREG32;


enum syscall_function
{
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

#ifdef __cplusplus
extern "C" {
#endif

unsigned int scall(const SREG32 *reg);

#ifdef __cplusplus
}
#endif

#endif
