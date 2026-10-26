#include "ip_operations.h"
#include "stack.h"
#include <iostream>

int check_hierarchy(char op)
{
    switch (op)
    {
        case '(':           return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^':           return 3;
        default:            return -1;
    }
}

bool is_operator(char c)
{ return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }

bool is_operand(char c)
{
    return  (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') ||
            c == '.';
}

// Conversión de infija a posfija usando la pila propia de 12 elementos.
// Devuelve cadena vacía si la expresión es inválida.
std::string convert_infix_to_postfix(const std::string& in) {
    Stack pila;
    std::string out;

    for (char c : in)
    {
        if (c == ' ')
        { continue; }

        // 1) Paréntesis izquierdo: se apila
        if (c == '(')
        {
            if (pila.is_full())
            {
                std::cout << "Error: la expresión excede la capacidad de la pila (12).\n";
                return {};
            }
            pila.push(c);
            continue;
        }

        // 2) Paréntesis derecho: desapila hasta encontrar '('
        if (c == ')')
        {
            while (!pila.is_empty() && pila.peek().value() != '(')
            { out += pila.pop().value(); }

            if (pila.is_empty())
            {
                std::cout << "Error: paréntesis desbalanceados.\n";
                return {};
            }

            pila.pop(); // descarta '('
            continue;
        }

        // 3) Operador: desapila los de mayor o igual jerarquía y se apila
        if (is_operator(c))
        {
            while (!pila.is_empty() && pila.peek().value() != '(')
            {
                char tope = pila.peek().value();
                int jt = check_hierarchy(tope);
                int jc = check_hierarchy(c);

                bool mayor     = jt > jc;
                bool igual_izq = (jt == jc) && (c != '^'); // ^ asocia a la derecha

                if (mayor || igual_izq)
                {
                    out += pila.pop().value();
                    out += ' ';
                }
                else break;
            }

            if (pila.is_full())
            {
                std::cout << "Error: la expresión excede la capacidad de la pila (12).\n";
                return {};
            }

            pila.push(c);
            continue;
        }

        // 4) Letra o dígito: se agrega directo a la salida
        if (is_operand(c))
        {
            out += c;
            out += ' ';
            continue;
        }

        std::cout << "Error: carácter inválido '" << c << "'.\n";
        return {};
    }

    // 5) Vaciar lo que quede en la pila
    while (!pila.is_empty())
    {
        auto op = pila.pop();

        if (op && *op == '(')
        {
            std::cout << "Error: paréntesis desbalanceados.\n";
            return {};
        }
        
        if (op)
        {
            out += *op;
            out += ' ';
        }
    }

    if (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}
