.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  movl $10, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $10, (%eax)
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L1
.L2:
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L1:
  pushl -8(%ebp)
  movl -4(%ebp), %eax
  movl (%eax), %eax
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
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L5
.L6:
  movl -12(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L5:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L6
  popl %ebx
  movl $45, -16(%ebp)
  pushl -16(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
