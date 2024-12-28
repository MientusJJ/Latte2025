.data

loc_str_val$0: .string "jeszcze\040raz"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
.L1:
  movl $0, -4(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  call readInt
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jne .L4
  movl $-1, (%esp)
  jmp .L5
.L4:
  movl $0, (%esp)
.L5:
  popl %eax
  test %eax, %eax
  jz .L2
  movl $0, %eax
  leave
  ret
.L2:
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
.L3:
  jmp .L1
