#pragma once

#include <optional>

// Pila de caracteres con capacidad fija de 12 elementos,
// declarada desde cero (sin usar clases Stack del lenguaje).
// Solo contiene métodos y propiedades propios de una pila.
class Stack
{
    private:
        static const int MAX = 12;
        unsigned char data[MAX];
        int top;

    public:
        Stack();

        void push(unsigned char v);
        std::optional<unsigned char> pop();
        std::optional<unsigned char> peek() const;

        int size() const;
        bool is_empty() const;
        bool is_full() const;
};
