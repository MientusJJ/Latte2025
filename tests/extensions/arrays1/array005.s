.data

loc_str_val$6: .string "\040"
loc_str_val$4: .string "fifth"
loc_str_val$3: .string "fourth"
loc_str_val$2: .string "third"
loc_str_val$5: .string "Counting\072"
loc_str_val$1: .string "second"
loc_str_val$0: .string "first"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl $5, %eax
  leal 4(, %eax, 4), %eax
  pushl %eax
  call malloc
  addl $4, %esp
  movl $5, (%eax)
  movl %eax, -4(%ebp)
  pushl -4(%ebp)
  movl $0, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$0, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $1, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$1, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $2, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$2, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $3, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$3, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  movl $4, %eax
  popl %ecx
  leal 4(%ecx, %eax, 4), %eax
  pushl %eax
  movl $loc_str_val$4, %eax
  popl %ecx
  movl %eax, (%ecx)
  movl $loc_str_val$5, %eax
  movl %eax, -8(%ebp)
  pushl %ebx
  movl -4(%ebp), %ebx
  movl %ebx, -12(%ebp)
  movl (%ebx), %ebx
  jmp .L1
.L2:
  leal -8(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  movl $loc_str_val$6, %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  pushl %eax
  movl -12(%ebp), %eax
  movl (%eax), %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  decl %ebx
.L1:
  addl $4, -12(%ebp)
  test %ebx, %ebx
  jnz .L2
  popl %ebx
  pushl -8(%ebp)
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
