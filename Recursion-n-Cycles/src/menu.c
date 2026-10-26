#include <menu.h>

#include <algoritmos.h>

#include <stdio.h>
#include <stdlib.h>

void prompt(char *texto) { printf("%s\n>> ", texto); }

unsigned int prompt_uint(char *texto)
{
    long int n;
    do
    {
        printf("%s\n>> ", texto);
        scanf("%ld", &n);

        if (n < 0) printf("El número introducido debe ser un número natural o 0.");
    } while (n < 0);
    return n;
}

static void pausa(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Presione Enter para continuar...");
    fflush(stdout);
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void submenu_fibonacci(void)
{
    extern char recursion;
    int r = 0;
    do
    {
        prompt("Serie de Fibonacci.\nIgrese una opción:\n0) Volver.\n1) Versión iterativa.\n2) Versión recursiva.");
        scanf(" %c", &recursion);

        unsigned int n = prompt_uint("Ingrese la cantidad de cálculos a realizar:");
        switch (recursion)
        {
            case '0':
                return;
            case '1':
                r = Fibonacci.iterativo(n);
                break;
            // case '2':
            //     r = AlgoritmosRecursivos.fibonacci(n);
            //     break;
            default:
                printf("!! Opción inválida. Intente de nuevo. !!\n");
                break;
        }
    } while(recursion != '0' && recursion != '1');

    printf("Resultado del cálculo: %d\n", r);
    printf("Total de iteraciones: %d\n", Fibonacci.get_iteraciones());

    pausa();
}

void submenu_factorial(void)
{
    extern char recursion;
    int r = 0;
    do
    {
        prompt("Factorial de un Número.\nIgrese una opción:\n0) Volver.\n1) Versión iterativa.\n2) Versión recursiva.");
        scanf(" %c", &recursion);

        unsigned int n = prompt_uint("Ingrese el número del cual se calculará el factorial:");

        switch (recursion)
        {
            case '0':
                return;
            case '1':
                r = Factorial.iterativo(n);
                break;
            // case '2':
            //     r = AlgoritmosRecursivos.factorial(n);
            //     break;
            default:
                printf("!! Opción inválida. Intente de nuevo. !!\n");
                break;
        }
    } while(recursion != '0' && recursion != '1');

    printf("Resultado del cálculo: %d\n", r);
    printf("Total de iteraciones: %d\n", Factorial.get_iteraciones());

    pausa();
}

void submenu_mcd(void)
{
    extern char recursion;
    int r = 0;
    do
    {
        prompt("Mínimo Común Denominador.\nIgrese una opción:\n0) Volver.\n1) Versión iterativa.\n2) Versión recursiva.");
        scanf(" %c", &recursion);

        unsigned int a = prompt_uint("Ingrese el primer operador para el MCD:");
        unsigned int b = prompt_uint("Ingrese el segundo operador para el MCD:");

        switch (recursion)
        {
            case '0':
                return;
            case '1':
                r = MCD.iterativo(a, b);
                break;
            // case '2':
            //     r = AlgoritmosRecursivos.mcd(n);
            //     break;
            default:
                printf("!! Opción inválida. Intente de nuevo. !!\n");
                break;
        }
    } while(recursion != '0' && recursion != '1');

    printf("Resultado del cálculo: %d\n", r);
    printf("Total de iteraciones: %d\n", MCD.get_iteraciones());

    pausa();
}

void menu_show(void)
{
    char option;

    do
    {
        printf("Estructura de Datos, Unidad II.\n");
        prompt("Elige una opción:\n0) Salir.\n1) Fibonacci.\n2) Factorial de un número.\n3) Mínimo común denominador.");
        scanf(" %c", &option);

        switch(option)
        {
            case '0':
                printf("¡Hasta luego!\n");
                exit(EXIT_SUCCESS);

            case '1':
                submenu_fibonacci();
                break;

            case '2':
                submenu_factorial();
                break;

            case '3':
                submenu_mcd();
                break;
        }
    } while (option != '0');
}
