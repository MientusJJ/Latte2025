.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  movl $1, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $1, (%eax)
  pushl (%eax)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
