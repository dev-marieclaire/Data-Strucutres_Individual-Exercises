#pragma once
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef struct fibonacci_t
{
    unsigned int (*iterativo)(unsigned int n);
    unsigned int (*recursivo)(unsigned int n);
    unsigned int (*get_iteraciones)(void);
} fibonacci_t;

typedef struct factorial_t
{
    unsigned int (*iterativo)(unsigned int n);
    unsigned int (*recursivo)(unsigned int n);
    unsigned int (*get_iteraciones)(void);
} factorial_t;

typedef struct mcd_t
{
    unsigned int (*iterativo)(unsigned int a, unsigned int b);
    unsigned int (*recursivo)(unsigned int a, unsigned int b);
    unsigned int (*get_iteraciones)(void);
} mcd_t;

extern fibonacci_t Fibonacci;
extern factorial_t Factorial;
extern mcd_t MCD;

#endif // Final de ALGORITMOS_H
