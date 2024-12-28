.data

loc_str_val$3: .string ""
loc_str_val$2: .string "\057\052\040world"
loc_str_val$1: .string "hello\040\052\057"
loc_str_val$0: .string "\075"
.text

.globl ifac2f
.globl mfac
.globl rfac
.globl main
.globl repStr
.globl ifac
.globl nfac
.globl fac

main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  pushl $10
  call fac
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl $10
  call rfac
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl $10
  call mfac
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl $10
  call ifac
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, -4(%ebp)
  movl $10, -8(%ebp)
  movl $1, -12(%ebp)
  jmp .L1
.L2:
  leal -12(%ebp), %eax
  pushl %eax
  pushl -12(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L1:
  pushl -8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jle .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jnz .L2
  pushl -12(%ebp)
  call printInt
  addl $4, %esp
  pushl $60
  pushl $loc_str_val$0
  call repStr
  addl $8, %esp
  pushl %eax
  call printString
  addl $4, %esp
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
  movl $0, %eax
  leave
  ret
fac:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  leal -4(%ebp), %eax
  movl $1, (%eax)
  leal -8(%ebp), %eax
  pushl %eax
  movl 8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L5
.L6:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  movl -8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  subl $1, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
.L5:
  pushl -8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jle .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jnz .L6
  movl -4(%ebp), %eax
  leave
  ret
rfac:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jne .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  popl %eax
  test %eax, %eax
  jz .L9
  movl $1, %eax
  leave
  ret
.L9:
  pushl 8(%ebp)
  pushl 8(%ebp)
  subl $1, (%esp)
  call rfac
  addl $4, %esp
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  leave
  ret
mfac:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jne .L15
  movl $-1, (%esp)
  jmp .L16
.L15:
  movl $0, (%esp)
.L16:
  popl %eax
  test %eax, %eax
  jz .L13
  movl $1, %eax
  leave
  ret
.L13:
  pushl 8(%ebp)
  pushl 8(%ebp)
  subl $1, (%esp)
  call nfac
  addl $4, %esp
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  leave
  ret
nfac:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  je .L19
  movl $-1, (%esp)
  jmp .L20
.L19:
  movl $0, (%esp)
.L20:
  popl %eax
  test %eax, %eax
  jz .L17
  pushl 8(%ebp)
  subl $1, (%esp)
  call mfac
  addl $4, %esp
  pushl %eax
  movl 8(%ebp), %eax
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  leave
  ret
.L17:
  movl $1, %eax
  leave
  ret
ifac:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  pushl $1
  call ifac2f
  addl $8, %esp
  leave
  ret
ifac2f:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jne .L22
  movl $-1, (%esp)
  jmp .L23
.L22:
  movl $0, (%esp)
.L23:
  popl %eax
  test %eax, %eax
  jz .L21
  movl 8(%ebp), %eax
  leave
  ret
.L21:
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jle .L25
  movl $-1, (%esp)
  jmp .L26
.L25:
  movl $0, (%esp)
.L26:
  popl %eax
  test %eax, %eax
  jz .L24
  movl $1, %eax
  leave
  ret
.L24:
  movl $0, -4(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl 8(%ebp)
  movl 12(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  popl %ecx
  movl %eax, (%ecx)
  pushl -4(%ebp)
  pushl 8(%ebp)
  call ifac2f
  addl $8, %esp
  pushl %eax
  pushl 12(%ebp)
  pushl -4(%ebp)
  addl $1, (%esp)
  call ifac2f
  addl $8, %esp
  imull (%esp), %eax
  movl %eax, (%esp)
  popl %eax
  leave
  ret
repStr:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $loc_str_val$3, %eax
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  jmp .L27
.L28:
  leal -4(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  movl 8(%ebp), %eax
  popl %ecx
  pushl %eax
  pushl %ecx
  call _Latte.addStrings
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L27:
  pushl -8(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L29
  movl $-1, (%esp)
  jmp .L30
.L29:
  movl $0, (%esp)
.L30:
  popl %eax
  test %eax, %eax
  jnz .L28
  movl -4(%ebp), %eax
  leave
  ret
