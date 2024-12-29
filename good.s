.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $3, -8(%ebp)
  pushl -8(%ebp)
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
  pushl -8(%ebp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jg .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jz .L5
  pushl -8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jg .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  popl %eax
  test %eax, %eax
  jz .L9
  leal -4(%ebp), %eax
  movl $1, (%eax)
  jmp .L10
.L9:
  leal -4(%ebp), %eax
  movl $2, (%eax)
.L10:
  jmp .L6
.L5:
  leal -4(%ebp), %eax
  movl $3, (%eax)
.L6:
  jmp .L2
.L1:
  leal -4(%ebp), %eax
  movl $4, (%eax)
.L2:
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
