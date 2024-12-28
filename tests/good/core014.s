.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  movl $0, -12(%ebp)
  leal -4(%ebp), %eax
  movl $1, (%eax)
  leal -8(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -12(%ebp), %eax
  movl $5000000, (%eax)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  jmp .L1
.L2:
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  leal -8(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  movl -4(%ebp), %eax
  subl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
.L1:
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jnz .L2
  movl $0, %eax
  leave
  ret
