.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  movl $0, %eax
  leave
  ret
