.globl outportb
.globl inportb

.text
outportb:
enter $0,$0
movb 8(%ebp),%al
movw 12(%ebp),%dx
outb %al,%dx
leave
ret

inportb:
enter $0,$0
movw 8(%ebp),%dx
inb %dx,%al
leave
ret
