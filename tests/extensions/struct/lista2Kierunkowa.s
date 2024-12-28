.data

loc_str_val$6: .string "\137\137\137\137\137\137\137\137\137\137"
loc_str_val$5: .string "wygenerowal\040liste\0402kierunkowa\040dlugosci\040\072"
loc_str_val$4: .string "Krotki\040test\040listy\072"
loc_str_val$3: .string "wracamy\040na\040poczatek\040listy\072\040"
loc_str_val$2: .string "idziemy\040na\040koniec\040listy\072\040"
loc_str_val$1: .string "po\040spacerku\040wartosc\040drugiego\040elementu\072"
loc_str_val$0: .string "po\040spacerku\040wartosc\040pierwszego\040elementu\072"
.text

.globl zwrocListeDlugosci
.globl wrocNaPoczatekIWypisuj
.globl przejdzSieNaKoniecIWypisuj
.globl listaTest
.globl main

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $30, -4(%ebp)
  pushl -4(%ebp)
  call listaTest
  addl $4, %esp
  movl $0, %eax
  leave
  ret
listaTest:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  pushl 8(%ebp)
  call zwrocListeDlugosci
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  pushl -4(%ebp)
  call przejdzSieNaKoniecIWypisuj
  addl $8, %esp
  movl %eax, -8(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl 8(%ebp)
  pushl -8(%ebp)
  call wrocNaPoczatekIWypisuj
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl -4(%ebp), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
  pushl 8(%ebp)
  movl $5, %eax
  cmpl %eax, (%esp)
  jl .L3
  movl $-1, (%esp)
  jmp .L4
.L3:
  movl $0, (%esp)
.L4:
  popl %eax
  test %eax, %eax
  jz .L1
  movl -4(%ebp), %eax
  movl 4(%eax), %eax
  movl %eax, -12(%ebp)
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
  movl -4(%ebp), %eax
  movl 4(%eax), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
  jmp .L2
.L1:
  leave
  ret
.L2:
  leave
  ret
przejdzSieNaKoniecIWypisuj:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl 8(%ebp), %eax
  movl %eax, -4(%ebp)
  movl 8(%ebp), %eax
  movl %eax, -8(%ebp)
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
  movl $0, -12(%ebp)
  jmp .L5
.L6:
  movl -4(%ebp), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
  leal -8(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  movl 4(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -12(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L5:
  pushl -12(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L7
  movl $-1, (%esp)
  jmp .L8
.L7:
  movl $0, (%esp)
.L8:
  popl %eax
  test %eax, %eax
  jnz .L6
  movl -8(%ebp), %eax
  leave
  ret
wrocNaPoczatekIWypisuj:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  movl 8(%ebp), %eax
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  pushl $loc_str_val$3
  call printString
  addl $4, %esp
  movl 12(%ebp), %eax
  movl %eax, -12(%ebp)
  jmp .L9
.L10:
  movl -4(%ebp), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
  leal -8(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  movl 0(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -12(%ebp), %eax
  movl %eax, %ecx
  decl (%ecx)
.L9:
  pushl -12(%ebp)
  movl $0, %eax
  cmpl %eax, (%esp)
  jle .L11
  movl $-1, (%esp)
  jmp .L12
.L11:
  movl $0, (%esp)
.L12:
  popl %eax
  test %eax, %eax
  jnz .L10
  movl -8(%ebp), %eax
  leave
  ret
zwrocListeDlugosci:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  pushl $loc_str_val$4
  call printString
  addl $4, %esp
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  movl $0, -8(%ebp)
  movl $0, -12(%ebp)
  leal -8(%ebp), %eax
  pushl %eax
  movl -4(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl $1, -16(%ebp)
  movl -4(%ebp), %eax
  leal 8(%eax), %eax
  movl $0, (%eax)
  jmp .L13
.L14:
  movl -4(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl $0, %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  pushl $12
  call malloc
  addl $4, %esp
  popl %ecx
  movl %eax, (%ecx)
  leal -12(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  movl 4(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -8(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  movl -16(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl -8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -16(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L13:
  pushl -16(%ebp)
  movl 8(%ebp), %eax
  cmpl %eax, (%esp)
  je .L15
  movl $-1, (%esp)
  jmp .L16
.L15:
  movl $0, (%esp)
.L16:
  popl %eax
  test %eax, %eax
  jnz .L14
  movl -8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl $0, %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl $loc_str_val$5
  call printString
  addl $4, %esp
  pushl 8(%ebp)
  call printInt
  addl $4, %esp
  pushl $loc_str_val$6
  call printString
  addl $4, %esp
  movl -4(%ebp), %eax
  leave
  ret
