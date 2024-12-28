.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $1, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $1, (%eax)
  movl %eax, -4(%ebp)
  movl $0, %eax
  leave
  ret
