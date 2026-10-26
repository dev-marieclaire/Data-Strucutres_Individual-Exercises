.intel_syntax noprefix

.data
    # Variables globales.
    total:          .long 0 # Esta variable guarda el total de iteraciones o llamadas
                            # pasado como argumento desde C.

    recursion:      .byte 0 # Este es la variable que indicara si se debe ejecutar
                            # el metodo recursivo o no.

.globl recursion
