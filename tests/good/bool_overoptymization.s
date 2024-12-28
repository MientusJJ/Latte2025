.data

loc_str_val$0: .string "ahoj"
.text

.globl print
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  call print
  test %eax, %eax
  jz .L1
  movl $0, %eax
  test %eax, %eax
  jz .L1
  pushl $-1
  jmp .L2
.L1:
  pushl $0
.L2:
  popl %eax
  movl $0, %eax
  leave
  ret
print:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl $-1, %eax
  leave
  ret
