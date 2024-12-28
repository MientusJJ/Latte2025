.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl $0, -4(%ebp)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $1, -8(%ebp)
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $2, -12(%ebp)
  pushl -12(%ebp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
