.data

.text

.globl main
.globl Counter.incr
.globl Counter.value

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl $4
  call malloc
  addl $4, %esp
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  call Counter.incr
  addl $4, %esp
  pushl -4(%ebp)
  call Counter.incr
  addl $4, %esp
  pushl -4(%ebp)
  call Counter.incr
  addl $4, %esp
  pushl -4(%ebp)
  call Counter.value
  addl $4, %esp
  movl %eax, -8(%ebp)
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
Counter.incr:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  movl %eax, %ecx
  incl (%ecx)
  leave
  ret
Counter.value:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  leave
  ret
