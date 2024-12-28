.data

.text

.globl main
.globl run

main:
  pushl %ebp
  movl %esp, %ebp
  call run
  movl $0, %eax
  leave
  ret
run:
  pushl %ebp
  movl %esp, %ebp
  pushl $0
  call printInt
  addl $4, %esp
  leave
  ret
