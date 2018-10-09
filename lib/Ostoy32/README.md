# syscall function

For Ostoy32
  
```s
set mode = eax
Paramers list
1st =     ebx
2nd =     edx
3rd	=     ecx
4th	=     esi
5th	=     edi

int 0x80

return = eax

example:

movl $0,%eax         # set mode 0 (set cursor)
movl $0,ebx          # first param
movl $24,%edx        # secound param

int $0x80            # call interrupt number 0x80

```