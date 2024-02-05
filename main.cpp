#include <iostream>
#include "Matriz.hpp"


int main()
{
    try{
        Matriz v(3, 3), w(3, 3), resultante;

        std::cout << "Introduzca los n elementos de la primera matriz v" << '\n';
        std::cin >> v;
        /*
        std::cout << "Introduzca los n elementos de la segunda matriz w" << '\n';
        std::cin >> w;

        resultante = v + w;

        std::cout << v << " + " << w << " = " << resultante  << '\n';

        resultante = v - w;

        std::cout << v << " - " << w << " = " << resultante  << '\n';

        resultante = v*5;

        std::cout << v << " * " << '5' << " = " << resultante  << '\n';

        resultante = v*w;

        std::cout << v << " * " << w << " = " << resultante  << '\n';

        resultante = v.Trasponer();

        std::cout << v << " traspuesta " << " = " << resultante << '\n';

        resultante.Redimensionar(5, 5);
        */

        std::cout << v << '\n';

        resultante = v.SubMatriz(0, 0);

        std::cout << resultante << "Separacion" << '\n';

        resultante = v.SubMatriz(1, 2);

        std::cout << resultante << "Separacion" << '\n';

        resultante = v.SubMatriz(2, 0);

        std::cout << resultante << "Separacion" << '\n';

        resultante = v.SubMatriz(3, 3);

        std::cout << resultante << "Separacion" << '\n';

        resultante = v.SubMatriz(7, 3);

        std::cout << resultante << "Separacion" << '\n';

    }catch(const char *msn){
        std::cerr << "Error: " << msn << '\n';
    }catch(...){
        std::cerr << "Ocurrio un error inesperado" << '\n';
    }

    return 0;
}
