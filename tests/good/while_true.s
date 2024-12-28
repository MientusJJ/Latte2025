.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
.L1:
  movl $0, %eax
  leave
  ret
