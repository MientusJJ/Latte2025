.data

.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  call readInt
  movl %eax, -4(%ebp)
  call readString
  movl %eax, -8(%ebp)
  call readString
  movl %eax, -12(%ebp)
  pushl -4(%ebp)
  subl $5, (%esp)
  call printInt
  addl $4, %esp
  pushl -8(%ebp)
  movl -12(%ebp), %eax
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
