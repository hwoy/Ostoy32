#include <config.h>
.text
.globl _start

_start:
.incbin "init32.bin"

.space 512*INIT_NSECT-(.-_start),0

