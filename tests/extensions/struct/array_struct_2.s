.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  pushl $8
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  leal 4(%eax), %eax
  movl $11, (%eax)
  movl $10, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $10, (%eax)
  pushl %ebx
  pushl %eax
  movl $10, %ebx
  jmp .L1
.L2:
  pushl $8
  call malloc
  addl $4, %esp
  popl %edx
  movl %eax, (%edx, %ebx, 4)
  pushl %edx
  decl %ebx
.L1:
  test %ebx, %ebx
  jnz .L2
  popl %eax
  popl %ebx
  movl %eax, -8(%ebp)
  pushl %ebx
  movl -8(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L3
.L4:
  movl -12(%ebp), %eax
  leal 0(%eax), %eax
  movl $10, (%eax)
  movl -12(%ebp), %eax
  leal 4(%eax), %eax
  movl $10, (%eax)
  decl %ebx
.L3:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L4
  popl %ebx
  pushl -8(%ebp)
  movl $5, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl %ebx
  movl -8(%ebp), %ebx
  movl %ebx, -16(%ebp)
  movl (%ebx), %ebx
  jmp .L5
.L6:
  movl -16(%ebp), %eax
  pushl 4(%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L5:
  addl $4, -16(%ebp)
  test %ebx, %ebx
  jnz .L6
  popl %ebx
  movl $0, %eax
  leave
  ret
