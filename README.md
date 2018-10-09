![](https://raw.githubusercontent.com/hwoy/Ostoy32/master/res/Ostoy32.png?raw=true)

Port [Slider game](https://github.com/hwoy/slider) to Ostoy32 on QEMU

[Download](https://raw.githubusercontent.com/hwoy/Ostoy32/master/img/Ostoy32.img) Ostoy32 image for [QEMU](https://www.qemu.org)

# What is an Ostoy32
Ostoy32 is a simple and small 32 bits operating sysytem. 
It has been written in C99 and few Assembly code. 
It's originally designed for OS education. 
It may lacks of many features. 
I hope that you may enjoy with it. 
 
### Overview
- No special library
- No magic
- Raw image can be run on QEMU
- provides partial in-house libc interface for user mode. It means that you can port your simple ansi-C program to run on Ostoy32.
- Provides IRQ, Time-tick, keyboard, VGA
- No user mode , kernel mode only
- No memory management
- No process management
- No filesystem


```s
Host: Windows 64 bits(*) / unix-like os 
Target: i386-linux PC machine.

compiler:       gcc or clang
assembler:      as (GNU as)
linker:         ld (GNU front-end linker)
builder:        make (GNU make)

(*) == Implement for my project
```

### Tools for building Ostoy32

- Shell: git-bash from  Git for Windows(*) / Mingw32 / Msys2
- Toolchain: [mingw](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20NonWin/vityan/linux-ubuntu-natty_i686-bin_x86_64-mingw_20101218_vityan.7z/download) host=win64 target=i686-linux-elf(*)
- You can compile in easier way on linux
- Virtual machine: [QEMU](https://www.qemu.org)(*)
- (*) == Implement for my project

### Thanks
Inspired by

- Skelix by Xiaoming Mo (skelixos@gmail.com) (Mainly,  kernel initation)
- XINU (stdarg.h)

### Contact me. 
- Web: https://github.com/hwoy 
- Email: zaintcorp@yahoo.com 
- Facebook: http://www.facebook.com/dead-root 