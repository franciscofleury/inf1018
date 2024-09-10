.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
/* prologo */
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp
    movq  %rbx, -8(%rbp)
    movq  %r12, -16(%rbp)

/* coloque seu codigo aqui */
    xor   %rbx, %rbx /* zera o rbx; i=0 */
    movq  $nums, %r12
loop:
    cmpl  $5, %ebx
    jge   out

    movl  (%r12), %edi
    movl  $1, %esi
    call  filtro

    movq  $s1, %rdi
    movl  %eax, %esi
    xor   %eax, %eax
    call  printf

    addq  $4, %r12
    inc   %ebx
    jmp   loop

out:
/* finalizacao */
    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    leave
    ret
