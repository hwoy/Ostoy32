# What is an Ostoy32
Ostoy32 is a simple and small 32 bits operating sysytem. 
It has been written in C99 and few Assembly code. 
It's originally designed for OS education. 
It may lacks of many features. 
I hope that you may enjoy with it. 
 
### Overview
- No special library
- No magic
- Raw image can be run on qenu
- provides partial in-house libc io interface for user mode. It means that you can port your simple program to run on Ostoy32.
- Provides IRQ, Time-tick, keyboard, VGA
- No user mode , kernel mode only
- No memory management
- No process management
- No filesystem


```s
Host: unix-like os 
Target: i386 32 bits PC machine.

compiler:       gcc or clang
assembler:      as (GNU as)
linker:         ld (GNU front-end linker)
builder:        make (GNU make)

```

### Thanks
Inspired by

- Skelix by Xiaoming Mo (skelixos@gmail.com) (Mainly,  kernel initation)
- XINU (stdarg.h)

### Contact me. 
- Web: https://github.com/hwoy 
- Email: zaintcorp@yahoo.com 
- Facebook: http://www.facebook.com/dead-root 