.data

.text

.globl fromTo
.globl length2
.globl head
.globl length
.globl main
.globl cons

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $50
  pushl $1
  call fromTo
  addl $8, %esp
  pushl %eax
  call length
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl $100
  pushl $1
  call fromTo
  addl $8, %esp
  pushl %eax
  call length2
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
head:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  leave
  ret
cons:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $0, -4(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl $8
  call malloc
  addl $4, %esp
  popl %ecx
  movl %eax, (%ecx)
  movl -4(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -4(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl 12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -4(%ebp), %eax
  leave
  ret
length:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jne .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jz .L1
  movl $0, %eax
  leave
  ret
.L1:
  movl 8(%ebp), %eax
  pushl 4(%eax)
  call length
  addl $4, %esp
  pushl %eax
  addl $1, (%esp)
  popl %eax
  leave
  ret
fromTo:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jle .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jz .L5
  movl $0, %eax
  leave
  ret
.L5:
  pushl 12(%ebp)
  pushl 8(%ebp)
  addl $1, (%esp)
  call fromTo
  addl $8, %esp
  pushl %eax
  pushl 8(%ebp)
  call cons
  addl $8, %esp
  leave
  ret
length2:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $0, -4(%ebp)
  jmp .L9
.L10:
  leal -4(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  leal 8(%ebp), %eax
  pushl %eax
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
.L9:
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  je .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  popl %eax
  test %eax, %eax
  jnz .L10
  movl -4(%ebp), %eax
  leave
  ret
