.data

loc_str_val$3: .string "true"
loc_str_val$4: .string "false"
loc_str_val$2: .string "concatenation"
loc_str_val$1: .string "\040"
loc_str_val$0: .string "string"
.text

.globl printBool
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $56, -4(%ebp)
  movl $-23, -8(%ebp)
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  addl %eax, (%esp)
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
  pushl $22
  call printInt
  addl $4, %esp
  pushl $0
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  subl %eax, (%esp)
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  cmpl %eax, (%esp)
  jle .L1
  movl $-1, (%esp)
  jmp .L2
.L1:
  movl $0, (%esp)
.L2:
  call printBool
  addl $4, %esp
  pushl -4(%ebp)
  movl -8(%ebp), %ecx
  popl %eax
  cdq
  idivl %ecx
  pushl %eax
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  cmpl %eax, (%esp)
  jg .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$0
  movl $loc_str_val$1, %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  pushl %eax
  movl $loc_str_val$2, %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  pushl %eax
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
printBool:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  test %eax, %eax
  jz .L5
  pushl $loc_str_val$3
  call printString
  addl $4, %esp
  leave
  ret
.L5:
  pushl $loc_str_val$4
  call printString
  addl $4, %esp
  leave
  ret
.L6:
  leave
  ret
