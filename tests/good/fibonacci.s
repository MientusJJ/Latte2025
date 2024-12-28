.data

loc_str_val$0: .string "Expected\040a\040non\055negative\040integer\054\040but\040got\072"
.text

.globl main
.globl fibonacci

fibonacci:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  pushl 8(%ebp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jg .L2
  movl $-1, (%esp)
  jmp .L3
.L2:
  movl $0, (%esp)
.L3:
  popl %eax
  test %eax, %eax
  jz .L1
  movl 8(%ebp), %eax
  leave
  ret
.L1:
  movl $0, -4(%ebp)
  movl $1, -8(%ebp)
  movl $0, -12(%ebp)
  movl $2, -16(%ebp)
  jmp .L4
.L5:
  leal -12(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  movl -4(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  movl -12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -16(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L4:
  pushl -16(%ebp)
  movl 8(%ebp), %eax
  cmpl %eax, (%esp)
  jg .L6
  movl $-1, (%esp)
  jmp .L7
.L6:
  movl $0, (%esp)
.L7:
  popl %eax
  test %eax, %eax
  jnz .L5
  movl -8(%ebp), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  call readInt
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jl .L10
  movl $-1, (%esp)
  jmp .L11
.L10:
  movl $0, (%esp)
.L11:
  popl %eax
  test %eax, %eax
  jz .L8
  pushl -4(%ebp)
  call fibonacci
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
.L8:
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  movl $1, %eax
  leave
  ret
