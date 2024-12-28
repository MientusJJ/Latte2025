.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  movl $-1, %eax
  test %eax, %eax
  jnz .L2
  movl $0, %eax
  test %eax, %eax
  jnz .L2
  pushl $0
  jmp .L3
.L2:
  pushl $-1
.L3:
  popl %eax
  test %eax, %eax
  jz .L1
.L1:
  movl $0, %eax
  leave
  ret
