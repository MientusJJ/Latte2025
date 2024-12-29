.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $3, -4(%ebp)
  pushl -4(%ebp)
  addl $1, (%esp)
  popl %eax
  pushl -4(%ebp)
  addl $1, (%esp)
  movl $0, %eax
  leave
  ret
