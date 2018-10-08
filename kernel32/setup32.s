.code16
#include <config.h>
.globl _start
_start:
jmp 0f
str_err: .asciz "Can't load api and app sectors\r\n" 
driveno: .byte 0
gdt:   
		.quad	0x0000000000000000 ;# null descriptor
		.quad	0x00cf9a000000ffff ;# cs
		.quad	0x00cf92000000ffff ;# ds
		.quad	0x0000000000000000 ;# reserved for further use
		.quad	0x0000000000000000 ;# reserved for further use
gdt_48:
		.word	.-gdt-1
		.long	GDT_ADDR
		
		
0:
	movb %dl,driveno
	xorb %dh,%dh
	movw $KERN+(SETUP_NSECT*512),%bx
	movw $MBR_NSECT+SETUP_NSECT+1,%cx
	movw $(0x0200+INIT_NSECT+APP_NSECT),%ax
	int $0x13
	jnc 1f
	movw  $str_err,%si
	call print_text
	
	
	
_loop:
		hlt
jmp _loop



	1:
	cli
	xorw %ax,%ax
	movw %ax,%ds
	movw $GDT_ADDR>>4,%ax
	movw %ax,%es
	xorw %di,%di
	mov $gdt,%si
	movw $GDT_SIZE,%cx
	cld
	rep
	movsb

enable_a20:
	inb $0x64,%al
	testb $0x02,%al
	jnz enable_a20
	movb $0xdf,%al
	outb %al,$0x64


	lgdt gdt_48

	movl %cr0,%eax
	orl $0x00000001,%eax
	movl %eax,%cr0
	ljmp $CODE_SEL,$int_step_2


.code32
int_step_2:
	movl $DATA_SEL,%eax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	movw %ax,%ss
	movl $STACK_ADDR,%esp
	
	movl $KERN+(SETUP_NSECT)*512,%esi
	movl $INIT_ADDR,%edi
	movl $INIT_NSECT*512/4,%ecx
	cld
	rep;movsl
		
	movl $KERN+(SETUP_NSECT+INIT_NSECT)*512,%esi
	movl $APP_ADDR,%edi
	movl $APP_NSECT*512/4,%ecx
	cld
	rep;movsl
	
	
	
	
	xorl %eax,%eax
	movb driveno,%al
	pushl %eax
	call INIT_ADDR
	
	call APP_ADDR
	
	2:
hlt
	jmp 2b
	
	
	

print_text:
cld
3:
lodsb
testb %al,%al
jnz 4f
ret
4:
movb $0xe,%ah
int $0x10
jmp 3b

.space 512*SETUP_NSECT-(.-_start),0

