.include "../../include/globals.inc"

.data
    mcd_iteraciones: .long 0

.globl mcd_iteraciones

.text
.globl mcd_iterativo

mcd_iterativo:
    push RBX
    mov dword ptr [mcd_iteraciones], 0
    mov EAX, EDI
    mov EBX, ESI
    xor EDI, EDI

    test EBX, EBX
    jz mcd_retorno

mcd_ciclo:
    xor EDX, EDX
    div EBX
    inc dword ptr [mcd_iteraciones]
    mov EAX, EBX
    mov EBX, EDX
    test EBX, EBX
    jnz mcd_ciclo

mcd_retorno:
    pop RBX
    ret
