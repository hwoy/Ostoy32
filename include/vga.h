#ifndef __VGA_H__
#define __VGA_H__

#ifdef __cplusplus
extern "C" {
#endif

unsigned int set_cur(unsigned int x,unsigned int y);

unsigned int get_cur(unsigned int *x,unsigned int *y) ;

void pix(unsigned int x,unsigned int y,unsigned short bg,unsigned short fg,char ch);

void scrollup(unsigned int nrow);

void disablecursor(int bool);


void kputs(const char *str,unsigned int x,unsigned int y);


void kputc(char ch,unsigned int x,unsigned int y);


void set_bg(unsigned short color,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);


void set_fg(unsigned short color,unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);

void set_cursize(unsigned char begin,unsigned char end);

unsigned short get_pix(unsigned int x,unsigned int y);

#ifdef __cplusplus
}
#endif


#define ROW 25
#define COL 80

#define vidmem ((volatile unsigned short *)0xb8000) /*for kernel mode access only*/

/*
#define outb(val,port) __asm__ ("outb %%al,%%dx\n\t"::"a"(val),"d"(port))
#define inb(port,val) __asm__ ("inb %%dx,%%al\n\t":"=a"(val):"d"(port))
*/


enum VGACOLORS
{
    C_BLACK,
    C_BLUE,
    C_GREEN,
    C_CYAN,
    C_RED,
    C_MAGENTA,
    C_BROWN,
    C_LIGHTGRAY,
    C_DARKGRAY,
    C_LIGHTBLUE,
    C_LIGHTGREEN,
    C_LIGHTCYAN,
    C_LIGHTRED,
    C_LIGHTMAGENTA,
    C_YELLOW,
    C_WHITE
};

#define BLINK (1<<7)

#endif


