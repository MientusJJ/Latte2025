.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $3, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $3, (%eax)
  pushl %ebx
  pushl %eax
  movl $3, %ebx
  jmp .L1
.L2:
  pushl $4
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
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl $5, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $5, (%eax)
  pushl %ebx
  pushl %eax
  movl $5, %ebx
  jmp .L3
.L4:
  pushl $8
  call malloc
  addl $4, %esp
  popl %edx
  movl %eax, (%edx, %ebx, 4)
  pushl %edx
  decl %ebx
.L3:
  test %ebx, %ebx
  jnz .L4
  popl %eax
  popl %ebx
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $3, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl $10, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $10, (%eax)
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $3, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $2, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  movl $5, (%eax)
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $3, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $2, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  movl %eax, %ecx
  incl (%ecx)
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $3, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl $2, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
