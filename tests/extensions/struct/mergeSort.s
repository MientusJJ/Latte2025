.data

loc_str_val$3: .string "idziemy\040na\040koniec\040listy\040\050ma\040byc\040nierosnaco\051\072\040"
loc_str_val$2: .string "\137\137\137\137\137\137\137\137\137\137"
loc_str_val$1: .string "wygenerowal\040liste\0402kierunkowa\040dziwna\040dlugosci\040\072"
loc_str_val$0: .string "robimy\040liste\040do\040mergeSorta\072"
.text

.globl ladujWartosc
.globl pokazWartosc
.globl scalaj
.globl mergeSort
.globl przejdzSieNaKoniecIWypisuj
.globl main
.globl generujTablicoListeDoSortowaniaMerge13co7Malejaco
.globl testMergeSort

main:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  movl $30, -4(%ebp)
  pushl -4(%ebp)
  call testMergeSort
  addl $4, %esp
  movl $0, %eax
  leave
  ret
testMergeSort:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  pushl $-1
  pushl 8(%ebp)
  call generujTablicoListeDoSortowaniaMerge13co7Malejaco
  addl $8, %esp
  movl %eax, -4(%ebp)
  pushl 8(%ebp)
  pushl $0
  pushl -4(%ebp)
  call mergeSort
  addl $12, %esp
  movl %eax, -8(%ebp)
  pushl 8(%ebp)
  pushl -8(%ebp)
  call przejdzSieNaKoniecIWypisuj
  addl $8, %esp
  leave
  ret
mergeSort:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  pushl 16(%ebp)
  movl 12(%ebp), %eax
  subl %eax, (%esp)
  movl $1, %eax
  cmpl %eax, (%esp)
  jle .L2
  movl $-1, (%esp)
  jmp .L3
.L2:
  movl $0, (%esp)
.L3:
  popl %eax
  test %eax, %eax
  jz .L1
  pushl 16(%ebp)
  movl 12(%ebp), %eax
  subl %eax, (%esp)
  popl %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  pushl %eax
  movl 12(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  movl %eax, -12(%ebp)
  leal -4(%ebp), %eax
  pushl %eax
  pushl -12(%ebp)
  pushl 12(%ebp)
  pushl 8(%ebp)
  call mergeSort
  addl $12, %esp
  popl %ecx
  movl %eax, (%ecx)
  leal -8(%ebp), %eax
  pushl %eax
  pushl 16(%ebp)
  pushl -12(%ebp)
  pushl 8(%ebp)
  call mergeSort
  addl $12, %esp
  popl %ecx
  movl %eax, (%ecx)
  pushl 16(%ebp)
  movl -12(%ebp), %eax
  subl %eax, (%esp)
  pushl -8(%ebp)
  pushl -12(%ebp)
  movl 12(%ebp), %eax
  subl %eax, (%esp)
  pushl -4(%ebp)
  call scalaj
  addl $16, %esp
  leave
  ret
.L1:
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -16(%ebp)
  movl -16(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  pushl 12(%ebp)
  pushl 8(%ebp)
  call pokazWartosc
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
  movl -16(%ebp), %eax
  leave
  ret
scalaj:
  pushl %ebp
  movl %esp, %ebp
  subl $24, %esp
  movl $0, -4(%ebp)
  movl $0, -8(%ebp)
  movl $0, -12(%ebp)
  pushl $0
  pushl 12(%ebp)
  movl 20(%ebp), %eax
  addl %eax, (%esp)
  call generujTablicoListeDoSortowaniaMerge13co7Malejaco
  addl $8, %esp
  movl %eax, -16(%ebp)
  pushl -4(%ebp)
  pushl 8(%ebp)
  call pokazWartosc
  addl $8, %esp
  movl %eax, -20(%ebp)
  pushl -8(%ebp)
  pushl 16(%ebp)
  call pokazWartosc
  addl $8, %esp
  movl %eax, -24(%ebp)
  jmp .L4
.L5:
  pushl -4(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jne .L8
  movl $-1, (%esp)
  jmp .L9
.L8:
  movl $0, (%esp)
.L9:
  popl %eax
  test %eax, %eax
  jz .L6
  leal -20(%ebp), %eax
  movl $-1, (%eax)
  jmp .L7
.L6:
  leal -20(%ebp), %eax
  pushl %eax
  pushl -4(%ebp)
  pushl 8(%ebp)
  call pokazWartosc
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
.L7:
  pushl -8(%ebp)
  movl 20(%ebp), %eax
  cmpl %eax, (%esp)
  jne .L12
  movl $-1, (%esp)
  jmp .L13
.L12:
  movl $0, (%esp)
.L13:
  popl %eax
  test %eax, %eax
  jz .L10
  leal -24(%ebp), %eax
  movl $-1, (%eax)
  jmp .L11
.L10:
  leal -24(%ebp), %eax
  pushl %eax
  pushl -8(%ebp)
  pushl 16(%ebp)
  call pokazWartosc
  addl $8, %esp
  popl %ecx
  movl %eax, (%ecx)
.L11:
  pushl -24(%ebp)
  movl -20(%ebp), %eax
  cmpl %eax, (%esp)
  jle .L16
  movl $-1, (%esp)
  jmp .L17
.L16:
  movl $0, (%esp)
.L17:
  popl %eax
  test %eax, %eax
  jz .L14
  leal -8(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  pushl -24(%ebp)
  pushl -12(%ebp)
  pushl -16(%ebp)
  call ladujWartosc
  addl $12, %esp
  jmp .L15
.L14:
  leal -4(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
  pushl -20(%ebp)
  pushl -12(%ebp)
  pushl -16(%ebp)
  call ladujWartosc
  addl $12, %esp
.L15:
  leal -12(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L4:
  pushl -12(%ebp)
  pushl 12(%ebp)
  movl 20(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  cmpl %eax, (%esp)
  jge .L18
  movl $-1, (%esp)
  jmp .L19
.L18:
  movl $0, (%esp)
.L19:
  popl %eax
  test %eax, %eax
  jnz .L5
  movl -16(%ebp), %eax
  leave
  ret
pokazWartosc:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl 8(%ebp), %eax
  movl %eax, -8(%ebp)
  jmp .L20
.L21:
  leal -8(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  movl 4(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L20:
  pushl -4(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  je .L22
  movl $-1, (%esp)
  jmp .L23
.L22:
  movl $0, (%esp)
.L23:
  popl %eax
  test %eax, %eax
  jnz .L21
  movl -8(%ebp), %eax
  movl 8(%eax), %eax
  leave
  ret
ladujWartosc:
  pushl %ebp
  movl %esp, %ebp
  subl $8, %esp
  movl $0, -4(%ebp)
  movl 8(%ebp), %eax
  movl %eax, -8(%ebp)
  jmp .L24
.L25:
  leal -8(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  movl 4(%eax), %eax
  popl %ecx
  movl %eax, (%ecx)
  leal -4(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L24:
  pushl -4(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  je .L26
  movl $-1, (%esp)
  jmp .L27
.L26:
  movl $0, (%esp)
.L27:
  popl %eax
  test %eax, %eax
  jnz .L25
  movl -8(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  movl 16(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
generujTablicoListeDoSortowaniaMerge13co7Malejaco:
  pushl %ebp
  movl %esp, %ebp
  subl $16, %esp
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L28
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
.L28:
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
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L29
  movl -4(%ebp), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
.L29:
  jmp .L30
.L31:
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
  movl -16(%ebp), %eax
  cdq
  movl $5, %ecx
  idivl %ecx
  pushl %edx
  movl $3, %eax
  cmpl %eax, (%esp)
  jne .L34
  movl $-1, (%esp)
  jmp .L35
.L34:
  movl $0, (%esp)
.L35:
  popl %eax
  test %eax, %eax
  jz .L32
  movl -8(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  pushl 8(%ebp)
  movl -16(%ebp), %eax
  cdq
  movl $2, %ecx
  idivl %ecx
  subl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  jmp .L33
.L32:
  movl -8(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  movl -16(%ebp), %eax
  cdq
  movl $13, %ecx
  idivl %ecx
  movl %edx, %eax
  popl %ecx
  movl %eax, (%ecx)
.L33:
  movl -8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl -12(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L36
  movl -8(%ebp), %eax
  pushl 8(%eax)
  call printInt
  addl $4, %esp
.L36:
  leal -16(%ebp), %eax
  movl %eax, %ecx
  incl (%ecx)
.L30:
  pushl -16(%ebp)
  movl 8(%ebp), %eax
  cmpl %eax, (%esp)
  je .L37
  movl $-1, (%esp)
  jmp .L38
.L37:
  movl $0, (%esp)
.L38:
  popl %eax
  test %eax, %eax
  jnz .L31
  movl -8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl $0, %eax
  popl %ecx
  movl %eax, (%ecx)
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L39
  pushl $loc_str_val$1
  call printString
  addl $4, %esp
.L39:
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L40
  pushl 8(%ebp)
  call printInt
  addl $4, %esp
.L40:
  movl 12(%ebp), %eax
  test %eax, %eax
  jz .L41
  pushl $loc_str_val$2
  call printString
  addl $4, %esp
.L41:
  movl -4(%ebp), %eax
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
  pushl $loc_str_val$3
  call printString
  addl $4, %esp
  movl $0, -12(%ebp)
  jmp .L42
.L43:
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
.L42:
  pushl -12(%ebp)
  movl 12(%ebp), %eax
  cmpl %eax, (%esp)
  jge .L44
  movl $-1, (%esp)
  jmp .L45
.L44:
  movl $0, (%esp)
.L45:
  popl %eax
  test %eax, %eax
  jnz .L43
  movl -8(%ebp), %eax
  leave
  ret
