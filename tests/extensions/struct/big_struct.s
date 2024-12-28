.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
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
  pushl $104
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
  leal 96(%eax), %eax
  movl $10, (%eax)
  decl %ebx
.L3:
  addl $4, -8(%ebp)
  test %ebx, %ebx
  jnz .L4
  popl %ebx
  pushl -4(%ebp)
  movl $5, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 96(%eax)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
