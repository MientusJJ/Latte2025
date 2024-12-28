.data

loc_str_val$1: .string "b"
loc_str_val$0: .string "a"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  movl $loc_str_val$1, %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  pushl %eax
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
