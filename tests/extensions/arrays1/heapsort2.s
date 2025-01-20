.data

.text

.globl main
.globl maxHeapify

maxHeapify:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl 12(%ebp), %eax
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  movl -4(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl %eax, -8(%ebp)
  jmp .L1
.L2:
  movl -4(%ebp), %eax
  imull $2, %eax
  movl %eax, -12(%ebp)
  pushl -12(%ebp)
  movl 16(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L4
  movl $-1, (%esp)
  jmp .L5
.L4:
  movl $0, (%esp)
.L5:
  popl %eax
  test %eax, %eax
  jz .L3
  pushl 8(%ebp)
  pushl -12(%ebp)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  cmpl %eax, (%esp)
  jle .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jz .L6
  leal -12(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L6:
.L3:
  pushl -8(%ebp)
  pushl 8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  cmpl %eax, (%esp)
  jl .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  popl %eax
  test %eax, %eax
  jz .L9
  pushl 8(%ebp)
  movl -4(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  pushl 16(%ebp)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L10
.L9:
  pushl 8(%ebp)
  movl -4(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl 8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  movl -12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
.L10:
.L1:
  movl -4(%ebp), %eax
  imull $2, %eax
  pushl %eax
  movl 16(%ebp), %eax
  cmpl %eax, (%esp)
  jg .L13
  movl $-1, (%esp)
  jmp .L14
.L13:
  movl $0, (%esp)
.L14:
  popl %eax
  test %eax, %eax
  jnz .L2
  pushl -4(%ebp)
  movl 16(%ebp), %eax
  cmpl %eax, (%esp)
  jg .L16
  movl $-1, (%esp)
  jmp .L17
.L16:
  movl $0, (%esp)
.L17:
  popl %eax
  test %eax, %eax
  jz .L15
  pushl 8(%ebp)
  movl -4(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
.L15:
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $20, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  call readInt
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %ecx
  leal 4(, %ecx, 4), %eax
  pushl %ecx
  pushl %eax
  call malloc
  addl $4, %esp
  popl %ecx
  movl %ecx, (%eax)
  popl %ecx
  movl %eax, (%ecx)
  movl $0, -12(%ebp)
  jmp .L18
.L19:
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
.L18:
  pushl -12(%ebp)
  movl -8(%ebp), %eax
  movl (%eax), %eax
  cmpl %eax, (%esp)
  jge .L20
  movl $-1, (%esp)
  jmp .L21
.L20:
  movl $0, (%esp)
.L21:
  popl %eax
  test %eax, %eax
  jnz .L19
  leal -12(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  subl $1, (%esp)
  popl %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  popl %ecx
  movl %eax, (%ecx)
  jmp .L22
.L23:
  pushl -4(%ebp)
  subl $1, (%esp)
  pushl -12(%ebp)
  pushl -8(%ebp)
  call maxHeapify
  addl $12, %esp
  leal -12(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L22:
  pushl -12(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jl .L24
  movl $-1, (%esp)
  jmp .L25
.L24:
  movl $0, (%esp)
.L25:
  popl %eax
  test %eax, %eax
  jnz .L23
  leal -12(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L26
.L27:
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  movl %eax, -16(%ebp)
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl -8(%ebp)
  movl $0, %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -8(%ebp)
  movl $0, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl -16(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -12(%ebp)
  subl $1, (%esp)
  pushl $0
  pushl -8(%ebp)
  call maxHeapify
  addl $12, %esp
  leal -12(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L26:
  pushl -12(%ebp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jl .L28
  movl $-1, (%esp)
  jmp .L29
.L28:
  movl $0, (%esp)
.L29:
  popl %eax
  test %eax, %eax
  jnz .L27
  leal -12(%ebp), %eax
  movl $0, (%eax)
  jmp .L30
.L31:
  pushl -8(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl -8(%ebp)
  pushl -12(%ebp)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl 4(%ecx, %eax, 4), %eax
  cmpl %eax, (%esp)
  jle .L33
  movl $-1, (%esp)
  jmp .L34
.L33:
  movl $0, (%esp)
.L34:
  popl %eax
  test %eax, %eax
  jz .L32
  call error
.L32:
  leal -12(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L30:
  pushl -12(%ebp)
  pushl -4(%ebp)
  subl $1, (%esp)
  popl %eax
  cmpl %eax, (%esp)
  jge .L35
  movl $-1, (%esp)
  jmp .L36
.L35:
  movl $0, (%esp)
.L36:
  popl %eax
  test %eax, %eax
  jnz .L31
  pushl %ebx
  movl -8(%ebp), %ebx
  movl %ebx, -20(%ebp)
  movl (%ebx), %ebx
  jmp .L37
.L38:
  pushl -20(%ebp)
  call printInt
  addl $4, %esp
  decl %ebx
.L37:
  addl $4, -20(%ebp)
  test %ebx, %ebx
  jnz .L38
  popl %ebx
  movl $0, %eax
  leave
  ret
