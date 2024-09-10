.data
Sf: .string "max: %d\n"
.text
.globl main
main:  
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)

  movl    $0, %ebx /* int i = 0 */ 
  movl    $0, %eax /* int max = 0 */
  movq    $dados, %r12 /* St *p = dados */
loop:
  cmpb    $0, (%r12)
  je      next
  cmpl    4(%r12), %eax
  jge     next
  movl    4(%r12), %eax

next:
  addq    $8, %r12
  inc     %ebx
  cmpl    $3, %ebx
  jl      loop

out:
  movq    $Sf, %rdi
  movl    %eax, %esi
  movl    $0, %eax
  call printf

  movq    $0, %rax
  movq    -16(%rbp), %r12
  movq    -8(%rbp), %rbx
  leave
  ret

