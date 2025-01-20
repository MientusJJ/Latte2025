.data

loc_str_val$0: .string "\075\075"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $0, (%eax)
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  pushl (%eax)
  call printInt
  addl $4, %esp
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -8(%ebp)
  movl (%ebx), %ebx
  jmp .L1
.L2:
  pushl -8(%ebp)
  call printInt
  addl $4, %esp
  decl %ebx
.L1:
  addl $4, -8(%ebp)
  test %ebx, %ebx
  jnz .L2
  popl %ebx
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
