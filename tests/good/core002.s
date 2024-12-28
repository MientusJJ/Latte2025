.data

loc_str_val$0: .string "foo"
.text

.globl foo
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  call foo
  movl $0, %eax
  leave
  ret
foo:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  leave
  ret
