#include "stack.h"

// Constructor.
Stack::Stack() : top(-1) {}

void Stack::push(unsigned char v)
{
    if (is_full()) return;
    data[++top] = v;
}

std::optional<unsigned char> Stack::pop()
{
    if (is_empty()) return std::nullopt;
    return data[top--];
}

// Retorna el valor alojado en el tope.
// Similar a get() en arreglos.
std::optional<unsigned char> Stack::peek() const
{
    if (is_empty()) return std::nullopt;
    return data[top];
}

int Stack::size() const { return top + 1; }
bool Stack::is_empty() const { return top < 0; }
bool Stack::is_full() const { return top >= MAX - 1; }
