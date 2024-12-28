.data

loc_str_val$0: .string "abc"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
