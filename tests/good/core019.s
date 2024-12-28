.data

loc_str_val$0: .string "foo"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  movl $78, -4(%ebp)
  movl $1, -8(%ebp)
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  jmp .L1
.L2:
  leal -4(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  addl $7, (%esp)
  popl %eax
  movl %eax, -12(%ebp)
  pushl -12(%ebp)
  call printInt
  addl $4, %esp
.L1:
  pushl -4(%ebp)
  movl $76, %eax
  cmpl %eax, (%esp)
  jle .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jnz .L2
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl $4, %eax
  cmpl %eax, (%esp)
  jle .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jz .L5
  movl $4, -16(%ebp)
  pushl -16(%ebp)
  call printInt
  addl $4, %esp
  jmp .L6
.L5:
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
.L6:
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
