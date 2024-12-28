.data

loc_str_val$2: .string "false"
loc_str_val$1: .string "true"
loc_str_val$0: .string "apa"
.text

.globl implies
.globl printBool
.globl dontCallMe
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $4, -4(%ebp)
  pushl $3
  movl -4(%ebp), %eax
  cmpl %eax, (%esp)
  jg .L5
  movl $-1, (%esp)
  jmp .L6
.L5:
  movl $0, (%esp)
.L6:
  popl %eax
  test %eax, %eax
  jz .L3
  movl $-1, %eax
  test %eax, %eax
  jz .L3
  pushl $-1
  jmp .L4
.L3:
  pushl $0
.L4:
  popl %eax
  test %eax, %eax
  jz .L1
  pushl $-1
  call printBool
  addl $4, %esp
  jmp .L2
.L1:
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
.L2:
  movl $-1, %eax
  test %eax, %eax
  jnz .L7
  pushl $1
  call dontCallMe
  addl $4, %esp
  test %eax, %eax
  jnz .L7
  pushl $0
  jmp .L8
.L7:
  pushl $-1
.L8:
  call printBool
  addl $4, %esp
  movl $0, %eax
  test %eax, %eax
  jz .L9
  pushl $2
  call dontCallMe
  addl $4, %esp
  test %eax, %eax
  jz .L9
  pushl $-1
  jmp .L10
.L9:
  pushl $0
.L10:
  call printBool
  addl $4, %esp
  pushl $4
  movl -4(%ebp), %eax
  cmpl %eax, (%esp)
  jne .L13
  movl $-1, (%esp)
  jmp .L14
.L13:
  movl $0, (%esp)
.L14:
  popl %eax
  test %eax, %eax
  jz .L11
  movl $-1, %eax
  test %eax, %eax
  jz .L11
  pushl $-1
  jmp .L12
.L11:
  pushl $0
.L12:
  call printBool
  addl $4, %esp
  pushl $0
  pushl $0
  call implies
  addl $8, %esp
  pushl %eax
  call printBool
  addl $4, %esp
  pushl $-1
  pushl $0
  call implies
  addl $8, %esp
  pushl %eax
  call printBool
  addl $4, %esp
  pushl $0
  pushl $-1
  call implies
  addl $8, %esp
  pushl %eax
  call printBool
  addl $4, %esp
  pushl $-1
  pushl $-1
  call implies
  addl $8, %esp
  pushl %eax
  call printBool
  addl $4, %esp
  movl $0, %eax
  leave
  ret
dontCallMe:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  call printInt
  addl $4, %esp
  movl $-1, %eax
  leave
  ret
printBool:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  test %eax, %eax
  jz .L15
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  jmp .L16
.L15:
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
.L16:
  leave
  ret
implies:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  notl (%esp)
  popl %eax
  test %eax, %eax
  jnz .L17
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jne .L19
  movl $-1, (%esp)
  jmp .L20
.L19:
  movl $0, (%esp)
.L20:
  popl %eax
  test %eax, %eax
  jnz .L17
  pushl $0
  jmp .L18
.L17:
  pushl $-1
.L18:
  popl %eax
  leave
  ret
