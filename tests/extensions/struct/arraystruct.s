.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
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
  movl %eax, -4(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -8(%ebp)
  movl (%ebx), %ebx
  jmp .L3
.L4:
  movl -8(%ebp), %eax
  movl (%eax), %eax
  leal 0(%eax), %eax
  movl $10, (%eax)
  movl -8(%ebp), %eax
  movl (%eax), %eax
  leal 4(%eax), %eax
  movl $11, (%eax)
  decl %ebx
.L3:
  addl $4, -8(%ebp)
  test %ebx, %ebx
  jnz .L4
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L5
.L6:
  movl -12(%ebp), %eax
  movl (%eax), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  movl -12(%ebp), %eax
  movl (%eax), %eax
  pushl 4(%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L5:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L6
  popl %ebx
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  leal 0(%eax), %eax
  movl $5, (%eax)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
