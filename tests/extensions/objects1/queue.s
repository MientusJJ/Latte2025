.data

.text

.globl IntQueue.first
.globl IntQueue.size
.globl f
.globl IntQueue.rmFirst
.globl main
.globl Node.getElem
.globl IntQueue.insert
.globl Node.setElem
.globl Node.setNext
.globl Node.getNext
.globl IntQueue.isEmpty

Node.setElem:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl 12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Node.setNext:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl 12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Node.getElem:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  leave
  ret
Node.getNext:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  leave
  ret
IntQueue.isEmpty:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  pushl 0(%eax)
  movl $0, %eax
  cmpl %eax, (%esp)
  jne .L1
  movl $-1, (%esp)
  jmp .L2
.L1:
  movl $0, (%esp)
.L2:
  popl %eax
  leave
  ret
IntQueue.insert:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $8
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl 12(%ebp)
  pushl -4(%ebp)
  call Node.setElem
  addl $8, %esp
  pushl 8(%ebp)
  call IntQueue.isEmpty
  addl $4, %esp
  test %eax, %eax
  jz .L3
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L4
.L3:
  pushl -4(%ebp)
  movl 8(%ebp), %eax
  pushl 4(%eax)
  call Node.setNext
  addl $8, %esp
.L4:
  movl 8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
IntQueue.first:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  pushl 0(%eax)
  call Node.getElem
  addl $4, %esp
  leave
  ret
IntQueue.rmFirst:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl 0(%eax)
  call Node.getNext
  addl $4, %esp
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
IntQueue.size:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L5
.L6:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  call Node.getNext
  addl $4, %esp
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L5:
  pushl -4(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  je .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jnz .L6
  movl -8(%ebp), %eax
  leave
  ret
f:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl 8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  addl $3, (%esp)
  popl %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $8
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl $3
  call f
  addl $4, %esp
  pushl %eax
  pushl -4(%ebp)
  call IntQueue.insert
  addl $8, %esp
  pushl $5
  pushl -4(%ebp)
  call IntQueue.insert
  addl $8, %esp
  pushl $7
  pushl -4(%ebp)
  call IntQueue.insert
  addl $8, %esp
  pushl -4(%ebp)
  call IntQueue.first
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call IntQueue.rmFirst
  addl $4, %esp
  pushl -4(%ebp)
  call IntQueue.size
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
