.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $4
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  leal 0(%eax), %eax
  movl $10, (%eax)
  movl -4(%ebp), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
