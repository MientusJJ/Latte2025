.data

.text

.globl Stack.pop
.globl main
.globl Node.getElem
.globl Stack.top
.globl Node.setElem
.globl Node.setNext
.globl Stack.isEmpty
.globl Node.getNext
.globl Stack.push

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
Stack.push:
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
  movl 8(%ebp), %eax
  pushl 0(%eax)
  pushl -4(%ebp)
  call Node.setNext
  addl $8, %esp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Stack.isEmpty:
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
Stack.top:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  pushl 0(%eax)
  call Node.getElem
  addl $4, %esp
  leave
  ret
Stack.pop:
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
main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  pushl $4
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L3
.L4:
  pushl -8(%ebp)
  pushl -4(%ebp)
  call Stack.push
  addl $8, %esp
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L3:
  pushl -8(%ebp)
  movl $10, %eax
  cmpl %eax, (%esp)
  jge .L5
  movl $-1, (%esp)
  jmp .L6
.L5:
  movl $0, (%esp)
.L6:
  popl %eax
  test %eax, %eax
  jnz .L4
  jmp .L7
.L8:
  pushl -4(%ebp)
  call Stack.top
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call Stack.pop
  addl $4, %esp
.L7:
  pushl -4(%ebp)
  call Stack.isEmpty
  addl $4, %esp
  pushl %eax
  notl (%esp)
  popl %eax
  test %eax, %eax
  jnz .L8
  movl $0, %eax
  leave
  ret
