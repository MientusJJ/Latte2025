.data

loc_str_val$0: .string "\075\075"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $36, %esp
  movl $5, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $5, (%eax)
  pushl %ebx
  pushl %eax
  movl $5, %ebx
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
  movl $0, -8(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L3
.L4:
  movl -12(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl $5, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $5, (%eax)
  popl %ecx
  movl %eax, (%ecx)
  pushl %ebx
  movl -12(%ebp), %eax
  movl 0(%eax), %ebx
  movl %ebx, -16(%ebp)
  movl (%ebx), %ebx
  jmp .L5
.L6:
  leal -16(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  addl $10, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  decl %ebx
.L5:
  addl $4, -16(%ebp)
  test %ebx, %ebx
  jnz .L6
  popl %ebx
  decl %ebx
.L3:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L4
  popl %ebx
  movl -4(%ebp), %eax
  movl %eax, -20(%ebp)
  pushl %ebx
  movl -20(%ebp), %ebx
  movl %ebx, -24(%ebp)
  movl (%ebx), %ebx
  jmp .L7
.L8:
  pushl %ebx
  movl -24(%ebp), %eax
  movl 0(%eax), %ebx
  movl %ebx, -28(%ebp)
  movl (%ebx), %ebx
  jmp .L9
.L10:
  pushl -28(%ebp)
  call printInt
  addl $4, %esp
  decl %ebx
.L9:
  addl $4, -28(%ebp)
  test %ebx, %ebx
  jnz .L10
  popl %ebx
  decl %ebx
.L7:
  addl $4, -24(%ebp)
  test %ebx, %ebx
  jnz .L8
  popl %ebx
  movl $0, -32(%ebp)
  movl $0, -36(%ebp)
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  jmp .L11
.L12:
  leal -36(%ebp), %eax
  movl $0, (%eax)
  jmp .L13
.L14:
  pushl -20(%ebp)
  movl -32(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl 0(%eax)
  movl -36(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  call printInt
  addl $4, %esp
  leal -36(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L13:
  pushl -36(%ebp)
  pushl -20(%ebp)
  movl -32(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl 0(%eax), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L15
  movl $-1, (%esp)
  jmp .L16
.L15:
  movl $0, (%esp)
.L16:
  popl %eax
  test %eax, %eax
  jnz .L14
  leal -32(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L11:
  pushl -32(%ebp)
  movl -20(%ebp), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L17
  movl $-1, (%esp)
  jmp .L18
.L17:
  movl $0, (%esp)
.L18:
  popl %eax
  test %eax, %eax
  jnz .L12
  movl $0, %eax
  leave
  ret
