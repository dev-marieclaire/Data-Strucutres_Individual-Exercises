#include "ip_operations.h"
#include "stack.h"

#include <iostream>
#include <string>
#include <limits>

void credits()
{
    std::cout << "Materia: Estructuras de Datos\n"
              << "María Clara Isabel Jaime Benítez - 25620048\n";
}

int main()
{
    std::string ultimaInfija;
    std::string ultimaPosfija;
    char option = '$';

    do
    {
        std::cout << "\nIntroduce una opción:\n"
                  << "0) Salir\n"
                  << "1) Introducir expresión\n"
                  << "2) Mostrar\n"
                  << "3) Créditos\n"
                  << ">> ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option)
        {
            case '0':
                std::cout << "Fin del programa.\n";
                exit(0);
                break;

            case '1':
            {
                std::cout << "Introduce la expresión infija: ";
                std::string expr;
                std::getline(std::cin, expr);

                if (expr.empty()) std::cout << "La expresión debe contener algo.\n";
                else if (expr.size() > 50) std::cout << "La expresión supera el tamaño permitido (50).\n";
                else
                {
                    std::string posfija = convert_infix_to_postfix(expr);
                    if (!posfija.empty())
                    {
                        ultimaInfija  = expr;
                        ultimaPosfija = posfija;
                        std::cout << "Resultado posfijo: " << ultimaPosfija << "\n";
                    }
                    // Si la conversión falla, no se actualiza lo guardado
                    // y se regresa al menú de inicio.
                }
                break;
            }

            case '2':
                if (ultimaInfija.empty()) std::cout << "No hay expresión capturada.\n";
                else std::cout << "Infija:  " << ultimaInfija  << "\n" << "Posfija: " << ultimaPosfija << "\n";
                break;

            case '3':
                credits();
                break;

            default:
                std::cout << "Opción inválida.\n";
        }
    } while (option != '0');

    return 0;
}
