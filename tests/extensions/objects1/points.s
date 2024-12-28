.data

.text

.globl Point4.getW
.globl Point2.getY
.globl Point2.getX
.globl Point3.getZ
.globl Point2.move
.globl main
.globl Point3.moveZ
.globl Point4.moveW

Point2.move:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 0(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl 0(%eax)
  movl 12(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  movl 8(%ebp), %eax
  leal 4(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl 4(%eax)
  movl 16(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Point2.getX:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 0(%eax), %eax
  leave
  ret
Point2.getY:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 4(%eax), %eax
  leave
  ret
Point3.moveZ:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 8(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl 8(%eax)
  movl 12(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Point3.getZ:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 8(%eax), %eax
  leave
  ret
Point4.moveW:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  leal 12(%eax), %eax
  pushl %eax
  movl 8(%ebp), %eax
  pushl 12(%eax)
  movl 12(%ebp), %eax
  addl %eax, (%esp)
  popl %eax
  popl %ecx
  movl %eax, (%ecx)
  leave
  ret
Point4.getW:
  pushl %ebp
  movl %esp, %ebp
  movl 8(%ebp), %eax
  movl 12(%eax), %eax
  leave
  ret
main:
  pushl %ebp
  movl %esp, %ebp
  subl $12, %esp
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -4(%ebp)
  pushl $12
  call malloc
  addl $4, %esp
  movl %eax, -8(%ebp)
  pushl $16
  call malloc
  addl $4, %esp
  movl %eax, -12(%ebp)
  pushl $4
  pushl $2
  pushl -8(%ebp)
  call Point2.move
  addl $12, %esp
  pushl $7
  pushl -8(%ebp)
  call Point3.moveZ
  addl $8, %esp
  leal -4(%ebp), %eax
  pushl %eax
  movl -8(%ebp), %eax
  popl %ecx
  movl %eax, (%ecx)
  pushl $5
  pushl $3
  pushl -4(%ebp)
  call Point2.move
  addl $12, %esp
  pushl $3
  pushl $1
  pushl -12(%ebp)
  call Point2.move
  addl $12, %esp
  pushl $6
  pushl -12(%ebp)
  call Point3.moveZ
  addl $8, %esp
  pushl $2
  pushl -12(%ebp)
  call Point4.moveW
  addl $8, %esp
  pushl -4(%ebp)
  call Point2.getX
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -4(%ebp)
  call Point2.getY
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -8(%ebp)
  call Point3.getZ
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  pushl -12(%ebp)
  call Point4.getW
  addl $4, %esp
  pushl %eax
  call printInt
  addl $4, %esp
  movl $0, %eax
  leave
  ret
