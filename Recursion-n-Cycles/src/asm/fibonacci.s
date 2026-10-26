.include "../../include/globals.inc"

.data
    # Variables de uso multiple.
    fibonacci_iteraciones:  .long 0

.globl fibonacci_iteraciones

.text
.globl fibonacci_iterativo

fibonacci_iterativo:
    # Inicializa la variable de iteraciones en 0.
    mov dword ptr [fibonacci_iteraciones], 0

    # En ensamblador, los argumentos son pasados a los registros *di y *si
    cmp EDI, 1  # Compara el argumento con 1
    jle fibonacci_halt  # En caso de que sea menor o igual a 1, retorna.

    mov EBX, 0
    mov EAX, 1

    # total = N
    xor EDX, EDX
    mov EDX, EDI

    mov ECX, 2 # Le asigna 2 al registro contador.

    # No hizo falta guardar los valores en memoria,
    # pues el resultado se puede retornar directamente.

fibonacci_ciclo:
    cmp ECX, EDI # Compara el valor de ECX con la cantidad de iteraciones que se deben hacer.
    jg fibonacci_retorno

    mov EDX, EBX # EDX = S0
    add EDX, EAX # EDX = S0 + S1
    mov EBX, EAX # S0 = S1
    mov EAX, EDX # S1 = EDX

    inc dword ptr [fibonacci_iteraciones]
    inc ECX     # Incrementa ECX
    jmp fibonacci_ciclo # Repite el bloque.

fibonacci_halt:
    mov EAX, EDI
    ret

fibonacci_retorno:
    ret
