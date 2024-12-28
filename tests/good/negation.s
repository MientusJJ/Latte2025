.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $1
  call printInt
  addl $4, %esp
  movl $1, -4(%ebp)
  pushl -4(%ebp)
  negl (%esp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  negl (%esp)
  subl $2, (%esp)
  negl (%esp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
