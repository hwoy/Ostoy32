#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <vga.h>
#include <timer.h>

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

static void randomclear(unsigned short color,unsigned int interval)
{
    unsigned short point[ROW*COL];
    for(unsigned short i=0;i<(ROW*COL);++i)
    {
        point[i]=i;
    }

    for(unsigned int i=0;i<1024;++i)
    {
        unsigned int index1=std::rand()%(ROW*COL);
        unsigned int index2=std::rand()%(ROW*COL);

        const auto tmp=point[index1];
        point[index1]=point[index2];
        point[index2]=tmp;
    }

    for(unsigned int i=0;i<(ROW*COL);++i)
    {
        unsigned int y=point[i]/COL;
        unsigned int x=point[i]%COL;

        Rec(color,x,y,0,0);
        delay(interval);
    }
}

static void runningclear(unsigned short color,unsigned int interval)
{
    for(unsigned int y=0,i=0;y<ROW;++y,i=(i+1)%2)
        if(!i) for(unsigned int x=0;x<COL;++x)
        {
            Rec(color,x,y,0,0);
            delay(interval);
        }
        else for(unsigned int x=COL;x>0;)
        {
            Rec(color,--x,y,0,0);
            delay(interval);
        }
}

static void randompix(unsigned int interval,unsigned int loop=1024)
{
    for(unsigned int i=0;i<loop;++i)
    {
        pix(std::rand()%COL,std::rand()%ROW,std::rand()%7,std::rand()%16,std::rand()%26+'A');
        delay(interval);
    }
}

static void randombar(unsigned int interval)
{
    for(unsigned int x=0,y=0;x<COL;x+=5)
    {
        Rec(std::rand()%7,x,y,4,ROW-1);
        delay(interval);
    }   
}

extern "C"
int main()
{
    std::srand(1024*2);
    disablecursor(1);

    randombar(100);

    randompix(10);

    runningclear(BGC_RED,10);

    for(unsigned short color=0;color<8;color=(color+1)%8)
        randomclear(color,1);

    return 0;
}
