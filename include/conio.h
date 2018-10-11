#ifndef __CONIO_H__
#define __CONIO_H__

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

#ifdef __cplusplus
extern "C" {
#endif

unsigned int          wherex( void );
unsigned int          wherey( void );

void         clrscr( void );
void         gotoxy( unsigned int __x, unsigned int __y );

void         textbackground( unsigned short __newcolor );
void         textcolor( unsigned short __newcolor );

void         _setcursortype( int __cur_t );

int 		getch(void);
int 		getche(void); /*requirs putchar in libc*/

#ifdef __cplusplus
extern }
#endif

#endif
