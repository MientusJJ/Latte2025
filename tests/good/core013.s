.data

loc_str_val$4: .string "true"
loc_str_val$3: .string "false"
loc_str_val$2: .string "\041"
loc_str_val$1: .string "\174\174"
loc_str_val$0: .string "\046\046"
.text

.globl printBool
.globl main
.globl test

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  pushl $-1
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L1
  pushl $0
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L1
  pushl $-1
  jmp .L2
.L1:
  pushl $0
.L2:
  call printBool
  addl $4, %esp
  pushl $-2
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L3
  pushl $1
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L3
  pushl $-1
  jmp .L4
.L3:
  pushl $0
.L4:
  call printBool
  addl $4, %esp
  pushl $3
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L5
  pushl $-5
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L5
  pushl $-1
  jmp .L6
.L5:
  pushl $0
.L6:
  call printBool
  addl $4, %esp
  pushl $234234
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L7
  pushl $21321
  call test
  addl $4, %esp
  test %eax, %eax
  jz .L7
  pushl $-1
  jmp .L8
.L7:
  pushl $0
.L8:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  pushl $-1
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L9
  pushl $0
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L9
  pushl $0
  jmp .L10
.L9:
  pushl $-1
.L10:
  call printBool
  addl $4, %esp
  pushl $-2
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L11
  pushl $1
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L11
  pushl $0
  jmp .L12
.L11:
  pushl $-1
.L12:
  call printBool
  addl $4, %esp
  pushl $3
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L13
  pushl $-5
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L13
  pushl $0
  jmp .L14
.L13:
  pushl $-1
.L14:
  call printBool
  addl $4, %esp
  pushl $234234
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L15
  pushl $21321
  call test
  addl $4, %esp
  test %eax, %eax
  jnz .L15
  pushl $0
  jmp .L16
.L15:
  pushl $-1
.L16:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
  pushl $-1
  call printBool
  addl $4, %esp
  pushl $0
  call printBool
  addl $4, %esp
  movl $0, %eax
  leave
  ret
printBool:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  notl (%esp)
  popl %eax
  test %eax, %eax
  jz .L17
  pushl $loc_str_val$3
  call printString
  addl $4, %esp
  jmp .L18
.L17:
  pushl $loc_str_val$4
  call printString
  addl $4, %esp
.L18:
  leave
  ret
test:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  call printInt
  addl $4, %esp
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jle .L19
  movl $-1, (%esp)
  jmp .L20
.L19:
  movl $0, (%esp)
.L20:
  popl %eax
  leave
  ret
