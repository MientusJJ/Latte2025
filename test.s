.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $3, -4(%ebp)
  movl $0, %eax
  leave
  ret
