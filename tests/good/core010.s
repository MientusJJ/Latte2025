.data

.text

.globl main
.globl fac

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $5
  call fac
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
fac:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  leal -4(%ebp), %eax
  movl $1, (%eax)
  leal -8(%ebp), %eax
  pushl %eax
  movl 8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L1
.L2:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
.L1:
  pushl -8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jle .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jnz .L2
  movl -4(%ebp), %eax
  leave
  ret
