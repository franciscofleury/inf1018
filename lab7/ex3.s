.data
Sf: .string "%d\n"

.text
.globl main
main:

  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */

  movl    $1, %ebx
LOOP:
  cmpl    $11, %ebx
  je OUT

  movl    %ebx, %eax
  imull   %eax, %eax

/*************************************************************/
  /* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl    $0, %eax
  call    printf       /* chama a funcao da biblioteca */
/*************************************************************/

  inc     %ebx
  jmp     LOOP

OUT:
  movq    $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
