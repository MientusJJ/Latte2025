.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $20, %esp
  movl $10, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $10, (%eax)
  movl %eax, -4(%ebp)
  movl $1, -8(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L1
.L2:
  leal -12(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  decl %ebx
.L1:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L2
  movl -4(%ebp), %ebx
  movl %ebx, -16(%ebp)
  movl (%ebx), %ebx
  jmp .L3
.L4:
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -20(%ebp)
  movl (%ebx), %ebx
  jmp .L5
.L6:
  pushl -16(%ebp)
  movl -20(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  call printInt
  addl $4, %esp
  decl %ebx
.L5:
  addl $4, -20(%ebp)
  test %ebx, %ebx
  jnz .L6
  popl %ebx
  decl %ebx
.L3:
  addl $4, -16(%ebp)
  test %ebx, %ebx
  jnz .L4
  popl %ebx
  movl $0, %eax
  leave
  ret
