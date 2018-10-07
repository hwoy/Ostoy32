.code16
#include <config.h>
.globl _start
.text 
_start:
jmp 3f
str_err: .asciz  "Error sectors can't be loaded\r\n"
3:
cli
xorw %ax,%ax
movw %ax,%ds
movw %ax,%ss
movw %ax,%es
	movw $SP,%ax
	movw %ax,%sp	
sti
cld
movw $begin_vbr,%si
movw $VBR_ADDR,%di
movw $(end_vbr-begin_vbr+1),%cx
rep;movsb
ljmp $0x0000,$VBR_ADDR 

begin_vbr:
	movw $KERN,%bx
	
	
	xorb %dh,%dh
	pushw %dx # save a drive number
	
	movw $MBR_NSECT+1,%cx
	movw $(0x0200+SETUP_NSECT),%ax
	int $0x13
	jnc 0f

movw  $str_err,%si
call print_text
_loop:
hlt
jmp _loop
	
0:
popw %dx

ljmp $0x0000,$KERN

print_text:
cld
1:
lodsb
testb %al,%al
jnz 2f
ret
2:
movb $0xe,%ah
int $0x10
jmp 1b

end_vbr:

.space 510-(.-_start),0

.byte 0x55,0xaa
