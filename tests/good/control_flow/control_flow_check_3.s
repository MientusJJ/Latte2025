.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $0, -4(%ebp)
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
  jz .L1
  movl $1, %eax
  leave
  ret
.L1:
  movl $2, %eax
  leave
  ret
.L2:
  pushl $6
  call printInt
  addl $4, %esp
