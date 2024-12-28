.data

.text

.globl main
.globl f

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  movl $0, -12(%ebp)
  movl $0, %eax
  leave
  ret
f:
  pushl %ebp
  movl %esp, %ebp
  leave
  ret
