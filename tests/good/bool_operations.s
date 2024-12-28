.data

loc_str_val$1: .string "false"
loc_str_val$0: .string "true"
.text

.globl b
.globl t
.globl main
.globl f

main:
  pushl %ebp
  movl %esp, %ebp
  pushl $1
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L1
  pushl $2
  call f
  addl $4, %esp
  test %eax, %eax
  jz .L1
  pushl $-1
  jmp .L2
.L1:
  pushl $0
.L2:
  call b
  addl $4, %esp
  pushl $3
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L3
  pushl $4
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L3
  pushl $-1
  jmp .L4
.L3:
  pushl $0
.L4:
  call b
  addl $4, %esp
  pushl $5
  call t
  addl $4, %esp
  test %eax, %eax
  jnz .L5
  pushl $6
  call t
  addl $4, %esp
  test %eax, %eax
  jnz .L5
  pushl $0
  jmp .L6
.L5:
  pushl $-1
.L6:
  call b
  addl $4, %esp
  pushl $7
  call f
  addl $4, %esp
  test %eax, %eax
  jz .L7
  pushl $8
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L7
  pushl $-1
  jmp .L8
.L7:
  pushl $0
.L8:
  call b
  addl $4, %esp
  pushl $9
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L9
  pushl $10
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L11
  pushl $11
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L11
  pushl $-1
  jmp .L12
.L11:
  pushl $0
.L12:
  popl %eax
  test %eax, %eax
  jz .L9
  pushl $-1
  jmp .L10
.L9:
  pushl $0
.L10:
  call b
  addl $4, %esp
  pushl $12
  call f
  addl $4, %esp
  test %eax, %eax
  jnz .L13
  pushl $13
  call f
  addl $4, %esp
  test %eax, %eax
  jz .L15
  pushl $14
  call t
  addl $4, %esp
  test %eax, %eax
  jz .L15
  pushl $-1
  jmp .L16
.L15:
  pushl $0
.L16:
  popl %eax
  test %eax, %eax
  jnz .L13
  pushl $0
  jmp .L14
.L13:
  pushl $-1
.L14:
  call b
  addl $4, %esp
  movl $0, %eax
  leave
  ret
f:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
t:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  call f
  addl $4, %esp
  pushl %eax
  notl (%esp)
  popl %eax
  leave
  ret
b:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  test %eax, %eax
  jz .L17
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  jmp .L18
.L17:
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
.L18:
  leave
  ret
