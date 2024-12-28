.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $7, -8(%ebp)
  leal -4(%ebp), %eax
  movl $-1234234, (%eax)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
