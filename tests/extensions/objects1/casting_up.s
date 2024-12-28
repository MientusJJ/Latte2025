.data

.text

.globl A.getA
.globl main

A.getA:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  leal 0(%eax), %eax
  movl $10, (%eax)
  pushl -4(%ebp)
  call A.getA
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
