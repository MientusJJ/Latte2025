.data

.text

.globl main
.globl scalProd
.globl shiftLeft
.globl doubleArray

doubleArray:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl 8(%ebp), %eax
  movl (%eax), %ecx
  leal 4(, %ecx, 4), %eax
  pushl %ecx
  pushl %eax
  call malloc
  addl $4, %esp
  popl %ecx
  movl %ecx, (%eax)
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  pushl %ebx
  movl 8(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L1
.L2:
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -12(%ebp), %eax
  movl (%eax), %eax
  imull $2, %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  decl %ebx
.L1:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L2
  popl %ebx
  movl -4(%ebp), %eax
  leave
  ret
shiftLeft:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  pushl 8(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L3
.L4:
  pushl 8(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  pushl -8(%ebp)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L3:
  pushl -8(%ebp)
  movl 8(%ebp), %eax
  pushl (%eax)
  subl $1, (%esp)
  popl %eax
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
  pushl 8(%ebp)
  movl 8(%ebp), %eax
  pushl (%eax)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
scalProd:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L7
.L8:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  pushl 8(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 12(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L7:
  pushl -8(%ebp)
  movl 8(%ebp), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L9
  movl $-1, (%esp)
  jmp .L10
.L9:
  movl $0, (%esp)
.L10:
  popl %eax
  test %eax, %eax
  jnz .L8
  movl -4(%ebp), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $20, %esp
  movl $5, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $5, (%eax)
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L11
.L12:
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L11:
  pushl -8(%ebp)
  movl -4(%ebp), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L13
  movl $-1, (%esp)
  jmp .L14
.L13:
  movl $0, (%esp)
.L14:
  popl %eax
  test %eax, %eax
  jnz .L12
  pushl -4(%ebp)
  call shiftLeft
  addl $4, %esp
  pushl -4(%ebp)
  call doubleArray
  addl $4, %esp
  movl %eax, -12(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -16(%ebp)
  movl (%ebx), %ebx
  jmp .L15
.L16:
  movl -16(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L15:
  addl $4, -16(%ebp)
  test %ebx, %ebx
  jnz .L16
  movl -12(%ebp), %ebx
  movl %ebx, -20(%ebp)
  movl (%ebx), %ebx
  jmp .L17
.L18:
  movl -20(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L17:
  addl $4, -20(%ebp)
  test %ebx, %ebx
  jnz .L18
  popl %ebx
  pushl -12(%ebp)
  pushl -4(%ebp)
  call scalProd
  addl $8, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
