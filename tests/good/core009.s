.data

.text

.globl foo
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  call foo
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
foo:
  pushl %ebp
  movl %esp, %ebp
  movl $10, %eax
  leave
  ret
