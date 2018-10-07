/* Skelix by Xiaoming Mo (skelixos@gmail.com)
 * Licence: GPLv2 */


#define VALID_SYSCALL 12
#define SYS_CALL	0x80

extern void (*system_call_table[VALID_SYSCALL])(void);
extern void sys_call(void);


extern void sys_set_cur(void);
extern void sys_get_cur(void);
extern void sys_disablecursor(void);
extern void sys_kputs(void);
extern void sys_kputc(void);


extern void sys_set_cursize(void);
extern void sys_pix(void);
extern void sys_get_pix(void);
extern void sys_get_char(void);
extern void sys_get_driveno(void);

extern void sys_delay(void);
extern void sys_get_timetick(void);



