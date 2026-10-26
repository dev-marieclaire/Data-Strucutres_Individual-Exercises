#include <algoritmos.h>
#include <stdio.h>

extern unsigned int fibonacci_iteraciones;
extern unsigned int factorial_iteraciones;
extern unsigned int mcd_iteraciones;

extern unsigned int fibonacci_iterativo(unsigned int n);
unsigned int fibonacci_get_iteraciones(void) { return fibonacci_iteraciones; }

fibonacci_t Fibonacci = {
    .iterativo = fibonacci_iterativo,
    .recursivo = NULL,
    .get_iteraciones = fibonacci_get_iteraciones
};

extern unsigned int factorial_iterativo(unsigned int n);
unsigned int factorial_get_iteraciones(void) { return factorial_iteraciones; }

factorial_t Factorial = {
    .iterativo = factorial_iterativo,
    .recursivo = NULL,
    .get_iteraciones = factorial_get_iteraciones
};

extern unsigned int mcd_iterativo(unsigned int a, unsigned int b);
unsigned int mcd_get_iteraciones(void) { return mcd_iteraciones; }

mcd_t MCD = {
    .iterativo = mcd_iterativo,
    .recursivo = NULL,
    .get_iteraciones = mcd_get_iteraciones
};
