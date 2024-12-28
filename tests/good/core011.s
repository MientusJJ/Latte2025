.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $-1
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
