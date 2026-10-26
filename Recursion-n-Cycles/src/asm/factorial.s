.include "../../include/globals.inc"

.data
    factorial_iteraciones: .long 0

.globl factorial_iteraciones

.text
.globl factorial_iterativo

factorial_iterativo:
    mov dword ptr [factorial_iteraciones], 0
    mov RAX, 1

factorial_paso_base:
    cmp RDI, 1 # Compara N con 1
    je retorno # Retorna en caso de ser igual

    # En caso de ser menor
    mov RAX, 1
    jl retorno

    mov dword ptr [total], EDI # total = N
    jg factorial_pre_ciclo

factorial_pre_ciclo:
    mov RCX, 2 # Inicializa el contador en 2

factorial_ciclo:
    cmp ECX, dword ptr [total] # Compara el contador con N
    ja retorno

    imul RAX, RCX # RAX *= i

    inc RCX
    inc dword ptr [factorial_iteraciones]
    jmp factorial_ciclo

retorno:
    ret
