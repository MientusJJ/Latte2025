.data

loc_str_val$0: .string "abc"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $1, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $1, (%eax)
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$0, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
