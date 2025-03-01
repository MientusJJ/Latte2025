.data
format_string: .string "%s\n"
format: .string "%d\n"
scanf_int: .string "%d%*c"
scanf_str: .string "%255[^\n]%*c"
error_str: .string "runtime error"
input_buffer: .space 128

.text
.globl printString
.globl printInt
.globl error
.globl readInt
.globl readString
.globl _Latte.addStrings

printString:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  pushl $format_string
  call printf
  leave
  ret

printInt:
  pushl %ebp
  movl %esp, %ebp
  pushl 8(%ebp)
  pushl $format
  call printf
  leave
  ret

error:
  pushl %ebp
  movl %esp, %ebp
  pushl $error_str
  call printString
  addl $4, %esp
  pushl stdout
  call fflush
  addl $4, %esp
  movl $1, %eax
  movl $0, %ebx
  int $0x80

readString:
	pushl	%ebp
	movl	%esp, %ebp
	subl $8, %esp
	movl $128, -4(%ebp)
	pushl -4(%ebp)
	call malloc
	addl $4, %esp
	movl %eax, -8(%ebp)
	pushl -8(%ebp)
	pushl $format_string
	call scanf
	addl $8, %esp
	movl -8(%ebp), %eax
	leave
	ret

readInt:
	pushl	%ebp
	movl	%esp, %ebp
	subl $4, %esp
	leal -4(%ebp), %eax
	pushl %eax
	pushl $scanf_int
	call scanf
	addl $8, %esp
	movl -4(%ebp), %eax
	leave
	ret

_Latte.addStrings:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	subl	$12, %esp
	pushl	8(%ebp)
	call	strlen
	addl	$16, %esp
	movl	%eax, %esi
	subl	$12, %esp
	pushl	12(%ebp)
	call	strlen
	addl	$16, %esp
	addl	%esi, %eax
	addl	$1, %eax
	subl	$12, %esp
	pushl	%eax
	call	malloc
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	subl	$8, %esp
	pushl	8(%ebp)
	pushl	-12(%ebp)
	call	strcpy
	addl	$16, %esp
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	-12(%ebp)
	call	strcat
	addl	$16, %esp
	movl	-12(%ebp), %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret

