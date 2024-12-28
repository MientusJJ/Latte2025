.data

loc_str_val$0: .string "done\041"
.text

.globl A.getObject
.globl main
.globl ParentB.set

A.getObject:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl $8
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl 12(%ebp)
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  addl %eax, (%esp)
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  addl %eax, (%esp)
  movl 8(%ebp), %eax
  movl 8(%eax), %eax
  addl %eax, (%esp)
  pushl -4(%ebp)
  call ParentB.set
  addl $8, %esp
  pushl 12(%ebp)
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  addl %eax, (%esp)
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  addl %eax, (%esp)
  movl 8(%ebp), %eax
  movl 8(%eax), %eax
  addl %eax, (%esp)
  call printInt
  addl $4, %esp
  movl -4(%ebp), %eax
  leave
  ret
ParentB.set:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl 12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl $10, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $10, (%eax)
  pushl %ebx
  pushl %eax
  movl $10, %ebx
  jmp .L1
.L2:
  pushl $4
  call malloc
  addl $4, %esp
  popl %edx
  movl %eax, (%edx, %ebx, 4)
  pushl %edx
  decl %ebx
.L1:
  test %ebx, %ebx
  jnz .L2
  popl %eax
  popl %ebx
  movl %eax, -4(%ebp)
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -8(%ebp)
  movl -8(%ebp), %eax
  leal 8(%eax), %eax
  movl $1, (%eax)
  movl -8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl -8(%ebp), %eax
  pushl 8(%eax)
  addl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -8(%ebp), %eax
  movl 4(%eax), %eax
  imull $2, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $4, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  pushl $2
  pushl -8(%ebp)
  call A.getObject
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L3
.L4:
  movl -12(%ebp), %eax
  movl (%eax), %eax
  pushl 0(%eax)
  call printInt
  addl $4, %esp
  decl %ebx
.L3:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L4
  popl %ebx
  movl $0, %eax
  leave
  ret
