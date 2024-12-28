.data

.text

.globl ev
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $17
  call ev
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
ev:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
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
  pushl 8(%ebp)
  subl $2, (%esp)
  call ev
  addl $4, %esp
  leave
  ret
.L1:
  pushl 8(%ebp)
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
  movl $0, %eax
  leave
  ret
.L5:
  movl $1, %eax
  leave
  ret
.L6:
