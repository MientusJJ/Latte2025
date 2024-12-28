.data

loc_str_val$0: .string "false"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $28, %esp
  movl $0, -4(%ebp)
  movl $5, -8(%ebp)
  movl $2, -12(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  addl %eax, (%esp)
  popl %ecx
  leal 4(, %ecx, 4), %eax
  pushl %ecx
  pushl %eax
  call malloc
  addl $4, %esp
  popl %ecx
  movl %ecx, (%eax)
  popl %ecx
  movl %eax, (%ecx)
  movl -4(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  movl $0, -16(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -20(%ebp)
  movl (%ebx), %ebx
  jmp .L1
.L2:
  movl -16(%ebp), %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  pushl %edx
  movl $0, %eax
  cmpl %eax, (%esp)
  jne .L5
  movl $-1, (%esp)
  jmp .L6
.L5:
  movl $0, (%esp)
.L6:
  popl %eax
  test %eax, %eax
  jz .L3
  movl -20(%ebp), %eax
  movl $-1, (%eax)
  jmp .L4
.L3:
  movl -20(%ebp), %eax
  movl $0, (%eax)
.L4:
  leal -16(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  decl %ebx
.L1:
  addl $4, -20(%ebp)
  test %ebx, %ebx
  jnz .L2
  movl -4(%ebp), %ebx
  movl %ebx, -24(%ebp)
  movl (%ebx), %ebx
  jmp .L7
.L8:
  movl -24(%ebp), %eax
  movl (%eax), %eax
  test %eax, %eax
  jz .L9
  pushl $1
  call printInt
  addl $4, %esp
  jmp .L10
.L9:
  pushl $0
  call printInt
  addl $4, %esp
.L10:
  decl %ebx
.L7:
  addl $4, -24(%ebp)
  test %ebx, %ebx
  jnz .L8
  popl %ebx
  movl $2, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $2, (%eax)
  movl %eax, -28(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  movl -28(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  movl $0, (%eax)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $-1, %eax
  cmpl %eax, (%esp)
  je .L12
  movl $-1, (%esp)
  jmp .L13
.L12:
  movl $0, (%esp)
.L13:
  popl %eax
  test %eax, %eax
  jz .L11
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
.L11:
  movl -4(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
