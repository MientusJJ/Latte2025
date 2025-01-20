.data

.text

.globl main
.globl heapSort
.globl extractMax
.globl heapDown
.globl swap

swap:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  movl 16(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl 8(%ebp)
  movl 16(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
heapDown:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  jmp .L1
.L2:
  movl 12(%ebp), %eax
  imull $2, %eax
  pushl %eax
  addl $1, (%esp)
  popl %eax
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  addl $1, (%esp)
  popl %eax
  movl %eax, -8(%ebp)
  movl -4(%ebp), %eax
  movl %eax, -12(%ebp)
  pushl -8(%ebp)
  movl 16(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L6
  movl $-1, (%esp)
  jmp .L7
.L6:
  movl $0, (%esp)
.L7:
  popl %eax
  test %eax, %eax
  jz .L4
  pushl 8(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  cmpl %eax, (%esp)
  jle .L8
  movl $-1, (%esp)
  jmp .L9
.L8:
  movl $0, (%esp)
.L9:
  popl %eax
  test %eax, %eax
  jz .L4
  pushl $-1
  jmp .L5
.L4:
  pushl $0
.L5:
  popl %eax
  test %eax, %eax
  jz .L3
  leal -12(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
.L3:
  pushl 8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  cmpl %eax, (%esp)
  jle .L12
  movl $-1, (%esp)
  jmp .L13
.L12:
  movl $0, (%esp)
.L13:
  popl %eax
  test %eax, %eax
  jz .L10
  pushl 12(%ebp)
  pushl -12(%ebp)
  pushl 8(%ebp)
  call swap
  addl $12, %esp
  leal 12(%ebp), %eax
  pushl %eax
  movl -12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L11
.L10:
  leave
  ret
.L11:
.L1:
  movl 12(%ebp), %eax
  imull $2, %eax
  pushl %eax
  pushl 16(%ebp)
  subl $1, (%esp)
  popl %eax
  cmpl %eax, (%esp)
  jge .L14
  movl $-1, (%esp)
  jmp .L15
.L14:
  movl $0, (%esp)
.L15:
  popl %eax
  test %eax, %eax
  jnz .L2
  leave
  ret
extractMax:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl 8(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  movl $0, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  pushl 12(%ebp)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl 12(%ebp)
  subl $1, (%esp)
  pushl $0
  pushl 8(%ebp)
  call heapDown
  addl $12, %esp
  movl -4(%ebp), %eax
  leave
  ret
heapSort:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl 8(%ebp), %eax
  movl (%eax), %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  movl %eax, -4(%ebp)
  jmp .L16
.L17:
  movl 8(%ebp), %eax
  pushl (%eax)
  pushl -4(%ebp)
  pushl 8(%ebp)
  call heapDown
  addl $12, %esp
  leal -4(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L16:
  pushl -4(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jl .L18
  movl $-1, (%esp)
  jmp .L19
.L18:
  movl $0, (%esp)
.L19:
  popl %eax
  test %eax, %eax
  jnz .L17
  leal -4(%ebp), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl (%eax)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L20
.L21:
  pushl 8(%ebp)
  movl -4(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl -4(%ebp)
  addl $1, (%esp)
  pushl 8(%ebp)
  call extractMax
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L20:
  pushl -4(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jl .L22
  movl $-1, (%esp)
  jmp .L23
.L22:
  movl $0, (%esp)
.L23:
  popl %eax
  test %eax, %eax
  jnz .L21
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  call readInt
  movl %eax, -4(%ebp)
  movl -4(%ebp), %ecx
  leal 4(, %ecx, 4), %eax
  pushl %ecx
  pushl %eax
  call malloc
  addl $4, %esp
  popl %ecx
  movl %ecx, (%eax)
  movl %eax, -8(%ebp)
  movl $0, -12(%ebp)
  jmp .L24
.L25:
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  call readInt
  popl %ecx
  movl %eax, (%ecx)
  leal -12(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L24:
  pushl -12(%ebp)
  movl -4(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L26
  movl $-1, (%esp)
  jmp .L27
.L26:
  movl $0, (%esp)
.L27:
  popl %eax
  test %eax, %eax
  jnz .L25
  pushl -8(%ebp)
  call heapSort
  addl $4, %esp
  pushl %ebx
  movl -8(%ebp), %ebx
  movl %ebx, -16(%ebp)
  movl (%ebx), %ebx
  jmp .L28
.L29:
  pushl -16(%ebp)
  call printInt
  addl $4, %esp
  decl %ebx
.L28:
  addl $4, -16(%ebp)
  test %ebx, %ebx
  jnz .L29
  popl %ebx
  movl $0, %eax
  leave
  ret
