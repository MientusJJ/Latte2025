.data

loc_str_val$0: .string "\042\012pop\012powrot\072\012getstatic\040java\057lang\057System\057out\040Ljava\057io\057PrintStream\073\012ldc\040\042zle\040\042\012invokevirtual\040java\057io\057PrintStream\057print\050Ljava\057lang\057String\073\051V\012goto\040powrot\012ldc\040\042"
.text

.globl main
.globl f

f:
  pushl %ebp
  movl %esp, %ebp
  subl $4, %esp
  pushl 8(%ebp)
  movl 8(%ebp), %eax
  imull $2, %eax
  addl %eax, (%esp)
  popl %eax
  movl %eax, -4(%ebp)
  pushl $loc_str_val$0
  call printString
  addl $4, %esp
  movl -4(%ebp), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  pushl $1
  call f
  addl $4, %esp
  pushl %eax
  subl $3, (%esp)
  popl %eax
  leave
  ret
