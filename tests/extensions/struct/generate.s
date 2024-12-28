.data

.text

.globl main
.globl generate

generate:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl 8(%ebp), %eax
  movl %eax, %ecx
  pushl %ecx
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  popl %ecx
  movl %ecx, (%eax)
  pushl %ebx
  pushl %eax
  movl %ecx, %ebx
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
  movl $0, -8(%ebp)
  jmp .L3
.L4:
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  leal 4(%eax), %eax
  pushl %eax
  pushl -8(%ebp)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L3:
  pushl -8(%ebp)
  movl -4(%ebp), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L5
  movl $-1, (%esp)
  jmp .L6
.L5:
  movl $0, (%esp)
.L6:
  popl %eax
  test %eax, %eax
  jnz .L4
  movl -4(%ebp), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  pushl $10
  call generate
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -8(%ebp)
  movl (%ebx), %ebx
  jmp .L7
.L8:
  movl -8(%ebp), %eax
  movl (%eax), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L7:
  addl $4, -8(%ebp)
  test %ebx, %ebx
  jnz .L8
  pushl $5
  call generate
  addl $4, %esp
  movl %eax, %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L9
.L10:
  movl -12(%ebp), %eax
  movl (%eax), %eax
  pushl 4(%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L9:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L10
  popl %ebx
  movl $0, %eax
  leave
  ret
