#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <vga.h>
#include <timer.h>

template <typename Tint>
bool isprime(Tint num)
{
    if(num<2) return false;

    for(Tint i=2;i*i<=num;++i)
    if(!(num%i)) return false;

    return true;
}

struct Rec
{
    unsigned short color;
    unsigned int x,y,w,h;
    explicit Rec(unsigned short color,unsigned int x,unsigned int y,unsigned int w,unsigned int h):color(color),x(x),y(y),w(w),h(h)
    {
        set();
    }

    void set() const
    {
        set_bg(color,x,y,x+w,y+h);
        set_fg(color,x,y,x+w,y+h);
    }
};

extern "C"
int main()
{
    std::srand(1024*2);
    disablecursor(1);
    for(unsigned int x=0,y=0;x<COL;x+=5)
    {
        Rec(std::rand()%7,x,y,4,ROW-1);
        delay(100);
    }

    for(unsigned int i=0;i<1024;++i)
    {
        pix(std::rand()%COL,std::rand()%ROW,std::rand()%7,std::rand()%16,std::rand()%26+'A');
        delay(100);
    }

    for(unsigned int y=0,i=0;y<ROW;++y,i=(i+1)%2)
        if(!i) for(unsigned int x=0;x<COL;++x)
        {
            set_bg(BGC_BLACK,x,y,x,y);
            delay(10);
        }
        else for(unsigned int x=COL;x>0;)
        {
            --x;
            set_bg(BGC_BLACK,x,y,x,y);
            delay(10);
        }

    return 0;
}
