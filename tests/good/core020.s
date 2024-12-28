.data

.text

.globl p
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  call p
  pushl $1
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
p:
  pushl %ebp
  movl %esp, %ebp
  leave
  ret
