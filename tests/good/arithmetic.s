.data

loc_str_val$3: .string "\052\052\052"
loc_str_val$2: .string "\137\137\137"
loc_str_val$1: .string "\055\055\055"
loc_str_val$0: .string "\075\075\075"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $12, -4(%ebp)
  movl $3, -8(%ebp)
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  subl %eax, (%esp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %ecx
  popl %eax
  cdq
  idivl %ecx
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %ecx
  popl %eax
  cdq
  idivl %ecx
  pushl %edx
  call printInt
  addl $4, %esp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl -4(%ebp), %eax
  imull $3, %eax
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  subl $3, (%esp)
  call printInt
  addl $4, %esp
  movl -4(%ebp), %eax
  imull $3, %eax
  pushl %eax
  call printInt
  addl $4, %esp
  movl -4(%ebp), %eax
  cdq
  movl $3, %ecx
  idivl %ecx
  pushl %eax
  call printInt
  addl $4, %esp
  movl -4(%ebp), %eax
  cdq
  movl $3, %ecx
  idivl %ecx
  pushl %edx
  call printInt
  addl $4, %esp
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  movl -8(%ebp), %eax
  imull $12, %eax
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -8(%ebp)
  subl $12, (%esp)
  negl (%esp)
  call printInt
  addl $4, %esp
  movl -8(%ebp), %eax
  imull $12, %eax
  pushl %eax
  call printInt
  addl $4, %esp
  movl -8(%ebp), %ecx
  movl $12, %eax
  cdq
  idivl %ecx
  pushl %eax
  call printInt
  addl $4, %esp
  movl -8(%ebp), %ecx
  movl $12, %eax
  cdq
  idivl %ecx
  pushl %edx
  call printInt
  addl $4, %esp
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
  pushl $36
  call printInt
  addl $4, %esp
  pushl $9
  call printInt
  addl $4, %esp
  pushl $36
  call printInt
  addl $4, %esp
  pushl $4
  call printInt
  addl $4, %esp
  pushl $0
  call printInt
  addl $4, %esp
  pushl $loc_str_val$3
  call printString
  addl $4, %esp
  pushl -4(%ebp)
  negl (%esp)
  call printInt
  addl $4, %esp
  pushl $-8
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  addl %eax, (%esp)
  negl (%esp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
