.data

loc_str_val$1: .string "6"
loc_str_val$0: .string "4"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
