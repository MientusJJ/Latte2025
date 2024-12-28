.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  leal -4(%ebp), %eax
  movl $45, (%eax)
  leal -8(%ebp), %eax
  movl $-36, (%eax)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
