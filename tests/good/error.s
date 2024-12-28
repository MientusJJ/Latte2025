.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  call error
  pushl $5
  call printInt
  addl $4, %esp
