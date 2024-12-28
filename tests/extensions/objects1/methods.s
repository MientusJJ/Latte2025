.data

loc_str_val$0: .string "\075\075"
.text

.globl B.printSum
.globl A.printValues
.globl main

A.printValues:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  movl 8(%ebp), %eax
  pushl 4(%eax)
  call printInt
  addl $4, %esp
  leave
  ret
B.printSum:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl 8(%ebp), %eax
  pushl 0(%eax)
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  addl %eax, (%esp)
  movl 8(%ebp), %eax
  movl 8(%eax), %eax
  addl %eax, (%esp)
  popl %eax
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  call A.printValues
  addl $4, %esp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  pushl -4(%ebp)
  call printInt
  addl $4, %esp
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl -4(%ebp), %eax
  leal 0(%eax), %eax
  movl $10, (%eax)
  movl -4(%ebp), %eax
  leal 4(%eax), %eax
  movl $11, (%eax)
  movl -4(%ebp), %eax
  leal 8(%eax), %eax
  movl $12, (%eax)
  pushl -4(%ebp)
  call B.printSum
  addl $4, %esp
  movl $0, %eax
  leave
  ret
