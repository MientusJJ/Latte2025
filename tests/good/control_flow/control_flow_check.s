.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $0, -4(%ebp)
  pushl -4(%ebp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jne .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jz .L1
  pushl -4(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jge .L6
  movl $-1, (%esp)
  jmp .L7
.L6:
  movl $0, (%esp)
.L7:
  popl %eax
  test %eax, %eax
  jz .L5
  movl $2, %eax
  leave
  ret
.L5:
  movl $1, %eax
  leave
  ret
.L1:
  movl $5, %eax
  leave
  ret
