.data

loc_str_val$0: .string "COS\012"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $loc_str_val$0, %eax
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
