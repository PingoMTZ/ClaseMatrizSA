/**
 * \file Matriz.hpp
 * \brief Implementaci&oacute;n de una matriz din&oacute;mica.
 * \author Adri&aacute;n Mart&iacute;nez Zamora, Ana Sof&iacute;a Matti R&iacute;s.
 * \date 06/02/2024
 */

#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

/** \class Matriz
 *
 * Permite utilizar <b> matrices din&aacute;micas </b> y ofrece un conjunto de operaciones b&aacute;sicas: suma, resta, multiplicaci&oacute;n de una
 * matriz por un escalar, producto matricial, trasponer, invertir.
 *
 *
 */

class Matriz {
    /** \brief Operador de multiplicaci&oacute;n de escalar por matriz.
     *
     * \param escalar El n&uacute;mero por el que se multiplica la matriz.
     * \param m La matriz a multiplicar.
     * \return La matriz resultante de la multiplicaci&oacute;n por escalar.
     *
     * \exception const <b>char *<\b> La matriz resultante no puede ser creada.
     *
     */
    friend Matriz operator*(double escalar, const Matriz &m);

    /** \brief Operador de inserci&oacute;n. Permite imprimir una matriz mendiante un flujo de salida.
     *
     * \param out El flujo de salida.
     * \param m La matriz a imprimir.
     * \return El flujo de salida. Permite aplicaci&oacute;n en cascada del operador.
     *
     */
    friend std::ostream & operator<<(std::ostream &out, const Matriz &m);

    /** \brief Operador de extracci&oacute;n. Permite capturar una matriz mediante un flujo de entrada.
     *
     * \param in El flujo de entrada
     * \param m La matriz a capturar
     * \return El flujo de entrada. Permite aplicaci&oacute;n en cascada del operador.
     *
     */
    friend std::istream & operator>>(std::istream &in, Matriz &m);

public:

    /**
     * \brief Constructor.
     *
     * Este constructor crea una matriz con el n&uacute;mero especificado de filas y columnas,
     * inicializando todos los elementos a cero. Por default a los parametros filas y columnas se les asignar&aacute; como valor 1.
     *
     * \param filas N&uacute;mero de filas de la matriz. Debe ser un valor positivo.
     * \param columnas N&uacute;mero de columnas de la matriz. Debe ser un valor positivo.
     *
     * \throw std::invalid_argument Si filas o columnas es menor que 1.
     * \throw std::bad_alloc Si no se puede asignar memoria para la matriz.
     *
     * \return Referencia al objeto Matriz recién creado.
     *
     * Ejemplo de uso:
     * \code
     *    try {
     *        Matriz matriz(3, 4);
     *    } catch (const std::exception& e) {
     *        std::cerr << "Error al crear la matriz: " << e.what() << std::endl;
     *    }
     * \endcode
     */

    explicit Matriz(unsigned int filas = 1, unsigned int columnas = 1);

    /**
     * \brief Constructor de copia.
     *
     * Este constructor crea una nueva instancia de la clase Matriz, copiando el contenido
     * de otra instancia existente.
     *
     * \param m Referencia constante a la Matriz que se va a copiar.
     */

    Matriz(const Matriz &m);

    /**
     * \brief Operador de asignaci&oacute;n.
     *
     * Este operador asigna el contenido de otra instancia de la clase Matriz a la instancia actual.
     *
     * \param m Referencia constante a la Matriz cuyo contenido se va a copiar.
     * \return Referencia a la instancia actual después de la asignaci&oacute;n.
     *
     * \note Si la instancia actual y la instancia proporcionada son la misma (this == &m),
     * el operador no realiza ninguna acci&oacute;n y devuelve la instancia actual sin cambios.
     *
     * \throws std::invalid_argument Si la matriz proporcionada tiene un n&uacute;mero de filas o columnas menor que 1.
     * \throws std::bad_alloc Si no se puede asignar memoria para la matriz.
     * \throws const char* Si ocurre un error al asignar memoria durante la construcci&oacute;n de la matriz.
     */

    Matriz & operator=(const Matriz &m);

    /**
     * \brief Destructor.
     *
     * Este destructor libera la memoria asignada din&aacute;micamente para la matriz.
     *
     * \note Si la matriz ya ha sido liberada (por ejemplo, si el destructor se llama varias veces),
     * este destructor no tiene ning&uacute;n efecto adicional.
     */

    ~Matriz();

    /**
     * \brief Operador de suma.
     *
     * Este operador realiza la suma de dos matrices, creando y devolviendo una nueva matriz como resultado.
     *
     * \param m Referencia constante a la Matriz que se sumar&aacute; con la instancia actual.
     * \return Nueva instancia de la Matriz que representa la suma de las dos matrices.
     *
     * \throws const char* Si las dimensiones de las matrices no son adecuadas para la suma.
     *
     * \note Las matrices deben tener las mismas dimensiones para que la suma sea posible.
     *
     * Ejemplo de uso:
     * \code
     * Matriz A(2, 2); // se inicializa la matriz A
     * Matriz B(2, 2); // se inicializa la matriz B
     * Matriz C = A + B; // se suma A y B, se almacena el resultado en C
     * \endcode
     */

    Matriz operator+(const Matriz &m) const;

    /**
     * \brief Operador de resta.
     *
     * Este operador realiza la resta de la instancia actual con otra matriz, creando y devolviendo una nueva matriz como resultado.
     *
     * \param m Referencia constante a la Matriz que se restar&aacute; de la instancia actual.
     * \return Nueva instancia de la Matriz que representa la resta de las dos matrices.
     *
     * \throws const char* Si las dimensiones de las matrices no son adecuadas para la resta.
     *
     * \note Las matrices deben tener las mismas dimensiones para que la resta sea posible.
     *
     * Ejemplo de uso:
     *
     * \code
     * Matriz A(2, 2); // se inicializa la matriz A
     * Matriz B(2, 2); // se inicializa la matriz B
     * Matriz C = A - B; // se resta A y B, se almacena el resultado en C
     * \endcode
     */

    Matriz operator-(const Matriz &m) const;


    /**
     * \brief Operador de multiplicaci&oacute;n por escalar.
     *
     * Este operador realiza la multiplicaci&oacute;n de cada elemento de la matriz por un escalar dado, creando y devolviendo una nueva matriz como resultado.
     *
     * \param escalar Valor que multiplicar&aacute; cada elemento de la matriz.
     * \return Nueva instancia de la Matriz que representa la matriz original multiplicada por el escalar.
     *
     * Se multiplica la matriz A por el escalar 2, almacenando el resultado en la matriz B.
     * \code
     * Matriz A(2, 2); // se inicializa la matriz A
     * Matriz B = A * 2;// se multiplica A por 2, se almacena el resultado en B
     *\endcode
     */

    Matriz operator*(double escalar) const;

    /**
     * \brief Operador de multiplicaci&oacute;n.
     *
     * Realiza el producto matricial de la instancia actual con otra matriz, creando y devolviendo una nueva matriz como resultado.
     *
     * \param m Referencia constante a la Matriz que se multiplicar con la instancia actual.
     * \return Nueva instancia de la Matriz que representa el producto matricial de las dos matrices.
     *
     * \throws const char* Si las dimensiones de las matrices no son adecuadas para el producto matricial.
     *
     * \note El n&uacute;mero de columnas de la instancia actual debe ser igual al número de filas de la matriz proporcionada para que el producto matricial sea posible.
     *
     * \code
     *  Ejemplo de uso:
     * Matriz A(2, 3);  // se inicializa la matriz A
     * Matriz B(3, 2);  // se inicializa la matriz B
     * Matriz C = A * B; // se multiplica A y B, se almacena el resultado en C
     * \endcode
     *
     */

    Matriz operator*(const Matriz &m) const;

    /**
     * \brief Calcula la matriz traspuesta.
     *
     * Este m&eacute;todo calcula y devuelve la matriz traspuesta de la instancia actual.
     *
     * \return Matriz traspuesta de la instancia actual.
     *
     * \code
     * // Ejemplo de uso:
     * Matriz A(2, 3);  // se inicializa la matriz A
     * // se llena A con datos
     * Matriz A_traspuesta = A.Trasponer(); // se calcula la matriz traspuesta de A
     * \endcode
     */

    Matriz Trasponer() const;

    /**
     * \brief Calcula la matriz inversa.
     *
     * Este m&eacute;todo calcula y devuelve la matriz inversa de la instancia actual.
     * Solo se aceptan matrices cuadradas para obtener la matriz inversa, y el determinante de la matriz no debe ser cero.
     *
     * \return Matriz inversa de la instancia actual.
     *
     * \throws const char* Si la matriz no es cuadrada o su determinante es cero.
     *
     * \code
     * // Ejemplo de uso:
     * Matriz A(3, 3);  // se inicializa una matriz cuadrada
     * // se llena A con datos
     * Matriz A_inversa = A.Invertir(); // se calcula la matriz inversa de A
     * \endcode
     */

    Matriz Invertir() const;

    /**
     * \brief Redimensiona la matriz a las nuevas dimensiones especificadas.
     *
     * Este m&eacute;todo redimensiona la instancia actual a las nuevas dimensiones especificadas.
     *
     * \param filas Nueva cantidad de filas para la matriz.
     * \param columnas Nueva cantidad de columnas para la matriz.
     *
     * \throws const char* Si las nuevas dimensiones están fuera de rango o no se puede asignar memoria para la matriz redimensionada.
     *
     * \code
     * // Ejemplo de uso:
     * Matriz A(2, 3);  // se inicializa una matriz
     * A.Redimensionar(3, 4); // se redimensiona la matriz a 3x4
     * \endcode
     */

    void Redimensionar(unsigned int filas, unsigned int columnas);

private:

    unsigned int filas;

    unsigned int columnas;

    double **arreglo;

    Matriz Adjunta() const;

    double Determinante() const;

    Matriz SubMatriz(unsigned int ignoraFila, unsigned int ignoraColumna) const;

};

#endif // MATRIZ_HPP_INCLUDED
