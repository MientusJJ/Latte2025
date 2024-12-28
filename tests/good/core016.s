.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $17, -4(%ebp)
  jmp .L1
.L2:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  subl $2, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
.L1:
  pushl -4(%ebp)
  movl $0, %eax
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
  movl $0, %eax
  cmpl %eax, (%esp)
  jge .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jz .L5
  pushl $0
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
.L5:
  pushl $1
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
