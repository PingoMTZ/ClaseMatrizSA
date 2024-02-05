#include "Matriz.hpp"

//*CONSTRUCTOR*
Matriz::Matriz(unsigned int filas, unsigned int columnas){
    if(filas < 1 || columnas < 1) throw "Dimensiones fuera de rango";
    this->filas = filas;
    this->columnas = columnas;

    try{
        arreglo = new double*[filas];
        arreglo[0] = new double[filas*columnas];
        for(unsigned int i = 1; i < filas; ++i){
            arreglo[i] = arreglo[i-1] + columnas;
        }
    }catch(std::bad_alloc &){
        throw "No es posible construir la matriz";
    }

    for(unsigned int i = 0; i < filas; ++i){
        for(unsigned int j = 0; j < columnas; ++j){
            arreglo[i][j] = 0;
        }
    }
}
//*CONSTRUCTOR DE COPIAS*
Matriz::Matriz(const Matriz &m) : filas(0), columnas(0), arreglo(nullptr){
    *this = m;
}
//*SOBRECARGA DE OPERADOR IGUAL*
Matriz & Matriz::operator=(const Matriz &m){
    if(this == &m) return *this;
    try{
        delete[] arreglo[0];
        delete[] arreglo;
        filas = m.filas;
        columnas = m.columnas;

        arreglo = new double*[filas];
        arreglo[0] = new double[filas*columnas];
        for(unsigned int i = 1; i < filas; ++i){
            arreglo[i] = arreglo[i-1] + columnas;
        }

        for(unsigned int i = 0; i < filas; ++i){
            for(unsigned int j = 0; j < columnas; ++j){
                arreglo[i][j] = m.arreglo[i][j];
            }
        }
    }catch(std::bad_alloc &){
        throw "No es posible construir la matriz";
    }

    return *this;
}
//*DESTRUCTOR*
Matriz::~Matriz(){
    delete arreglo[0];
    delete arreglo;
}
//*SUMA*
Matriz Matriz::operator+(const Matriz &m) const{
    if (filas != m.filas || columnas != m.columnas) throw "Dimensiones inaptas para suma";

    Matriz suma(filas, columnas);
    for(unsigned int i = 0; i < filas; ++i){
        for(unsigned int j = 0; j < columnas; ++j){
            suma.arreglo[i][j] = arreglo[i][j] + m.arreglo[i][j];
        }
    }

    return suma;
}
//*RESTA*
Matriz Matriz::operator-(const Matriz &m) const{
    if (filas != m.filas || columnas != m.columnas) throw "Dimensiones inaptas para resta";

    Matriz resta(filas, columnas);
    for(unsigned int i = 0; i < filas; ++i){
        for(unsigned int j = 0; j < columnas; ++j){
            resta.arreglo[i][j] = arreglo[i][j] - m.arreglo[i][j];
        }
    }

    return resta;
}
//*PRODCUTO MATRIZ POR ESCALAR*
Matriz Matriz::operator*(double escalar) const{
    Matriz multiplo(this->filas, this->columnas);
    for(unsigned int i = 0; i < filas; ++i){
        for(unsigned int j = 0; j < columnas; ++j){
            multiplo.arreglo[i][j] = arreglo[i][j]*escalar;
        }
    }

    return multiplo;
}
//*PRODUCTO MATRICIAL*
Matriz Matriz::operator*(const Matriz &m) const{
    if(columnas != m.filas) throw "Dimensiones inaptas para prodcuto matricial";

    Matriz producto(filas, m.columnas);
    double suma;
    for(unsigned int i = 0; i < filas; ++i){
        for(unsigned int j = 0; j < m.columnas; ++j){
            for(unsigned int k = 0; k < columnas; ++k){
                suma += arreglo[i][k]*m.arreglo[k][j];
            }
            producto.arreglo[i][j] = suma;
            suma = 0;
        }
    }

    return producto;
}
//*TRASPUESTA*
Matriz Matriz::Trasponer() const{
    Matriz traspuesta(this->columnas, this->filas);
    for(unsigned int i = 0; i < traspuesta.filas; ++i){
        for(unsigned int j = 0; j < traspuesta.columnas; ++j){
            traspuesta.arreglo[i][j] = arreglo[j][i];
        }
    }

    return traspuesta;
}
//*INVERSA*
Matriz Matriz::Invertir() const{
    if(filas != columnas) throw "Dimensiones inaptas para calcular la inversa de una matriz";

    Matriz inversa(filas, columnas);

    //Proceso de inversa aqui.

    return inversa;
}
//*MATRIZ ADJUNTA*
//*DETERMINANTE DE MATRIZ*
//*SUBMATRIZ*
// ¿que significa ignora fila e ignora columna? diferenciar entre punto de vista de usuario y punto de vista de desarrollador y su proposito
Matriz Matriz::SubMatriz(unsigned int ignoraFila, unsigned int ignoraColumna) const{
    // Comprobar si las dimensiones son apropiadas para obtener una submatriz
    if(ignoraFila < 0 || ignoraFila >= filas || ignoraColumna < 0 || ignoraColumna >= columnas){
            char mensajeError [12];
            sprintf(mensajeError, "No funciono");
            //sprintf (mensajeError, "Error: No se puede obtener la submatriz para la posicion %d , %d para matriz de %d x %d", ignoraFila, ignoraColumna, filas, columnas);
            throw mensajeError;
    }
    if(filas != columnas) throw "Solo se aceptan matrices cuadradas para obtener una submatriz";
    if(filas == 1 && columnas == 1) throw "Las dimensiones de la matriz tienen que ser mayor a 1x1 para obtener una submatriz";

    Matriz resultante((filas-1), (columnas-1));

    // Indices de la matriz resultante.
    unsigned int indiceFilasResultante = 0;
    unsigned int indiceColumnasResultante = 0;

    // Iteramos a traves de toda la matriz original.
    for(unsigned i = 0; i < filas; ++i){
        if(i != ignoraFila){
            for(unsigned int j = 0; j < columnas; ++j){
                if(j != ignoraColumna){
                    resultante.arreglo[indiceFilasResultante][indiceColumnasResultante] = arreglo[i][j];
                    ++indiceColumnasResultante;
                }
            }
            indiceColumnasResultante = 0;
            ++indiceFilasResultante;
        }
    }

    return resultante;
}

//*REDIMENSIONAMIENTO*
void Matriz::Redimensionar(unsigned int filas, unsigned int columnas){
    if(this->filas == filas && this->columnas == columnas) return;
    if(filas < 1 || columnas < 1) throw "Dimensiones fuera de rango";

    try{
        unsigned int m = this->filas;
        unsigned int n = this->columnas;
        double **aux = arreglo;

        this->filas = filas;
        this->columnas = columnas;
        arreglo = new double*[filas];
        arreglo[0] = new double[filas*columnas];
        for(unsigned int i = 1; i < filas; ++i){
            arreglo[i] = arreglo[i-1] + columnas;
        }
        // To Do List. Convertir este for a un método y asignarle su explicación de propósito.
        for(unsigned int i = 0; i < filas; ++i){
            for(unsigned int j = 0; j < columnas; ++j){
                arreglo[i][j] = 0;
            }
        }
        // Filas y columna son las nuevas dimenciones en cambio m y n son las dimensiones anteriores.
        // Escoger el limite de copia dependiendo de la dimensión mas chica.
        unsigned int limiteFilas, limiteColumnas;
        if(filas > m && columnas > n){
            limiteFilas = m;
            limiteColumnas = n;
        }else if(filas <= m && columnas >= n){
            limiteFilas = filas;
            limiteColumnas = n;
        }else if(filas >= m && columnas <= n){
            limiteFilas = m;
            limiteColumnas = columnas;
        }else if(filas < m && columnas < n){
            limiteFilas = filas;
            limiteColumnas = columnas;
        }

        for(unsigned int i = 0; i < limiteFilas; ++i){
            for(unsigned int j = 0; j < limiteColumnas; ++j)
                arreglo[i][j] = aux[i][j];
        }

        delete[] aux[0];
        delete[] aux;
        aux = nullptr;
     }catch(std::bad_alloc &){
        throw "No es posible redimensionar la matriz";
     }
}

//*FUNCIONES AMIGUITAS*

//*PRODUCTO ESCALAR POR MATRIZ*
Matriz operator*(double escalar, const Matriz &m){
    Matriz multiplo(m.filas, m.columnas);
    for(unsigned int i = 0; i < multiplo.filas; ++i){
        for(unsigned int j = 0; j < multiplo.columnas; ++j){
            multiplo.arreglo[i][j] = m.arreglo[i][j]*escalar;
        }
    }

    return multiplo;
}
//*FLUJO DE SALIDA*
std::ostream & operator<<(std::ostream &out, const Matriz &m){
    out << '\n';
    for(unsigned int i = 0; i < m.filas; ++i){
        out << "\u007c";
        for(unsigned int j = 0; j < m.columnas; ++j){
            out << m.arreglo[i][j];
            out << ' ';
        }
        out << "\b\u007c" << '\n';
    }

    return out;
}
//*FLUJO DE ENTRADA*
std::istream & operator>>(std::istream &in, Matriz &m){
    for(unsigned int i = 0; i < m.filas; ++i){
        for(unsigned int j = 0; j < m.columnas; ++j){
            in >> m.arreglo[i][j];
        }
    }

    return in;
}
