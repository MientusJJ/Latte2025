.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $56, -8(%ebp)
  pushl -8(%ebp)
  addl $45, (%esp)
  movl $2, %eax
  cmpl %eax, (%esp)
  jg .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jz .L1
  leal -4(%ebp), %eax
  movl $1, (%eax)
  jmp .L2
.L1:
  leal -4(%ebp), %eax
  movl $2, (%eax)
.L2:
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
