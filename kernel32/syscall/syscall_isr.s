

		.globl sys_call
		
		
		.macro	setup_syscall		nr
		.globl sys_\nr
		sys_\nr:
		pushl	%edi
		pushl	%esi
		pushl	%edx
		pushl	%ecx
		pushl	%ebx
		
		cli
		call \nr
		sti
		addl $5*4,%esp
		movl %eax,return
		ret
		.endm
		
		
		
		.text
	
	sys_call:
			cmpl	$12,		%eax
		jb		1f
		iret
1:
		pushal
		call	*sys_call_table(, %eax, 4)
		popal
		movl return,%eax
		iret	
		
		
     setup_syscall set_cur
     setup_syscall get_cur
	 setup_syscall disablecursor
	 setup_syscall kputs
	 setup_syscall kputc

     setup_syscall set_cursize
     setup_syscall pix
     setup_syscall get_pix
     setup_syscall get_char
     setup_syscall get_driveno
     
     setup_syscall delay
     setup_syscall get_timetick
		
	.bss	
.lcomm return,4
