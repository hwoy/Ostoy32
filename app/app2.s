#include <config.h>
.code32
.globl start
.text
start:
.incbin "app.bin"
.space APP_NSECT*512-(.-start),0

