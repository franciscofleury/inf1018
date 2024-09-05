.data
Sf: .string "soma=%d\n"
nums: .int 65, -105, 111, 34

.text
.globl main
main:
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $32, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
  movq    %r13, -24(%rbp)  /* guarda r13 */

  movq    $nums, %r12
  movq    $0, %rbx
  movl    $0, %eax

LOOP:
  cmpl    $4, %ebx
  je      OUT

  movq    %rbx, %r13
  imulq   $4, %r13 /* times sizeof int */
  addq    %r12, %r13
  addl    (%r13), %eax

  inc     %rbx
  jmp LOOP

OUT:
/*************************************************************/
  /* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl    $0, %eax
  call    printf       /* chama a funcao da biblioteca */
/*************************************************************/

  movq    $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -24(%rbp), %r13 /* recupera r13 */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret  
  
