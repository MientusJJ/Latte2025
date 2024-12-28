.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $0, -4(%ebp)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
