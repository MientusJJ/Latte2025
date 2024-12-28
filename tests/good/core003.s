.data

.text

.globl main
.globl p
.globl f
.globl g

f:
  pushl %ebp
  movl %esp, %ebp
  movl $0, %eax
  leave
  ret
g:
  pushl %ebp
  movl %esp, %ebp
  movl $0, %eax
  leave
  ret
p:
  pushl %ebp
  movl %esp, %ebp
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  call p
  movl $0, %eax
  leave
  ret
