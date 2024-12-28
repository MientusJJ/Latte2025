.data

loc_str_val$4: .string "false"
loc_str_val$2: .string "lala"
loc_str_val$3: .string "true"
loc_str_val$1: .string "ma\040kota"
loc_str_val$0: .string "ala"
.text

.globl printBool
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $loc_str_val$0, %eax
  movl %eax, -4(%ebp)
  movl $loc_str_val$1, %eax
  movl %eax, -8(%ebp)
  pushl $loc_str_val$0
  pushl $loc_str_val$0
  call strcmp
  addl $4, %esp
  test %eax, %eax
  jne .L1
  movl $-1, (%esp)
  jmp .L2
.L1:
  movl $0, (%esp)
.L2:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$0
  pushl $loc_str_val$2
  call strcmp
  addl $4, %esp
  test %eax, %eax
  jne .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$0
  pushl $loc_str_val$0
  call strcmp
  addl $4, %esp
  test %eax, %eax
  je .L5
  movl $-1, (%esp)
  jmp .L6
.L5:
  movl $0, (%esp)
.L6:
  call printBool
  addl $4, %esp
  pushl $loc_str_val$0
  pushl $loc_str_val$2
  call strcmp
  addl $4, %esp
  test %eax, %eax
  je .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  call printBool
  addl $4, %esp
  pushl -4(%ebp)
  pushl $loc_str_val$0
  call strcmp
  addl $4, %esp
  test %eax, %eax
  jne .L9
  movl $-1, (%esp)
  jmp .L10
.L9:
  movl $0, (%esp)
.L10:
  call printBool
  addl $4, %esp
  pushl -4(%ebp)
  pushl $loc_str_val$0
  call strcmp
  addl $4, %esp
  test %eax, %eax
  je .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  call printBool
  addl $4, %esp
  pushl -4(%ebp)
  pushl -8(%ebp)
  call strcmp
  addl $4, %esp
  test %eax, %eax
  jne .L13
  movl $-1, (%esp)
  jmp .L14
.L13:
  movl $0, (%esp)
.L14:
  call printBool
  addl $4, %esp
  pushl -4(%ebp)
  pushl -8(%ebp)
  call strcmp
  addl $4, %esp
  test %eax, %eax
  je .L15
  movl $-1, (%esp)
  jmp .L16
.L15:
  movl $0, (%esp)
.L16:
  call printBool
  addl $4, %esp
  movl $0, %eax
  leave
  ret
printBool:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
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
