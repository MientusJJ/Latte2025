.data

loc_str_val$3: .string ""
loc_str_val$4: .string "costam\012"
loc_str_val$2: .string "\012"
loc_str_val$1: .string "b"
loc_str_val$0: .string "a"
.text

.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
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
  movl $loc_str_val$3, %eax
  movl %eax, -4(%ebp)
  movl $loc_str_val$4, %eax
  movl %eax, -8(%ebp)
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  movl %eax, -12(%ebp)
  pushl -12(%ebp)
  movl -12(%ebp), %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  pushl %eax
  call printString
  addl $4, %esp
  pushl -12(%ebp)
  movl -12(%ebp), %eax
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
