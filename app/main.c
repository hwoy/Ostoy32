#ifndef RANDLOOP
#define RANDLOOP 1000
#endif

#include "slider.h"
#include "sliderio.h"
#include <stdio.h>
#include <string.h>

#ifndef SQUARE
#define SQUARE 5
#endif

#ifndef SQSTR
#define SQSTR "123456789"
#endif

#ifndef CMDSTR
#define CMDSTR "wsad"
#endif

#ifndef WxH
#define WxH 3
#endif

#ifndef INITSEED
#define INITSEED 1024
#endif

#define BSIZE 125

static const char cmdstr[] = CMDSTR;
static const char* const cmddes[] = { "UP", "DOWN", "LEFT", "RIGHT", NULL };

static const char* const gidstr[] = { "Normal", "Game Over!", NULL };

static const char sqstr[] = SQSTR;

static const char keycmd[] = "-+";
static const char* const keycmdstr[] = { "Quit", "Reset", NULL };

enum {
    kid_quit,
    kid_reset
};


static void showkey(const char* const key, const char* const keystr[])
{
    unsigned int i;

    for (i = 0; key[i]; ++i)
        printf(" %c(%s) ", key[i], keystr[i]);
}

static void initgame(unsigned int* const sq, unsigned int* seed, unsigned int index, unsigned int hw)
{
    initsq(sq, hw);
    randomsq(sq, index, hw, seed);
}

static void showcanmove(const unsigned int* const sq, unsigned int index, const char* const cmdstr, const char* const cmddes[], unsigned int hw)
{
    unsigned int d[4], i, j;

    j = extractcanmovesq(d, canmovesq(sq, index, hw));
    for (i = 0; i < j; ++i)
        printf("%c(%s) ", cmdstr[d[i]], cmddes[d[i]]);
}

static unsigned int getsqstrindex(const char* const sqstr, char ch)
{
    unsigned int i;
    for (i = 0; sqstr[i]; ++i)
        if (ch == sqstr[i])
            return i;

    return -1U;
}


int main()
{
    char ch;
    unsigned int key, move = 0;
    unsigned int sq[WxH * WxH];
    unsigned int gid = gid_normal;
    unsigned int seed, origseed, index;

    origseed = seed = INITSEED;
    index = getsqstrindex(sqstr, sqstr[strlen(sqstr) - 1]);

    initgame(sq, &seed, index, WxH);

    do {
        printf("Seed: %u\n", origseed);
        printf("Random Engine: %s\n\n", randomengine());
        showkey(cmdstr, cmddes);
        putchar('\n');
        showkey(keycmd, keycmdstr);
        printf("\n\n");
        printsq(sq, sqstr, SQUARE, index, WxH);
        printf("Can move: ");
        showcanmove(sq, index, cmdstr, cmddes, WxH);
        putchar('\n');
        printf("Press a key -> ");

        ch = getchar();

        if (ch == keycmd[kid_quit]) {
            break;
        } else if (ch == keycmd[kid_reset]) {
            seed = origseed;
            initgame(sq, &seed, index, WxH);
            move = 0;
            continue;
        }

        if ((key = mapcmd(cmdstr, ch)) != -1U) {
            if ((slide(sq, key, index, WxH)) != -1U)
                move++;
            printf("Move(s): %u\n", move);
            printf("Key ID: %u(%s)\n", key, cmddes[key]);
            gid = gameid(sq, WxH);
            printf("Game ID: %u(%s)\n\n", gid, gidstr[gid]);
        }
    } while (gid != gid_over);

    printsq(sq, sqstr, SQUARE, index, WxH);

    return 0;
}
