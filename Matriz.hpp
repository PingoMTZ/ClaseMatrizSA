#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

class Matriz {
    /** \brief Operador de multiplicaci&oacute;n de escalar por matriz.
     *
     * \param escalar El n&uacute;mero por el que se multiplica la matriz.
     * \param m La matriz a multiplicar.
     * \return La matriz resultante de la multiplicaci&oacute;n por escalar.
     *
     * \exception const <b>char *<\b> El vector resultante no puede ser creado.
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
    explicit Matriz(unsigned int filas = 1, unsigned int columnas = 1);

    Matriz(const Matriz &m);

    Matriz & operator=(const Matriz &m);

    ~Matriz();

    Matriz operator+(const Matriz &m) const;

    Matriz operator-(const Matriz &m) const;

    Matriz operator*(double escalar) const;

    Matriz operator*(const Matriz &m) const;

    Matriz Trasponer() const;

    Matriz Invertir() const;

    Matriz Adjunta() const;

    double Determinante() const;

    Matriz SubMatriz(unsigned int ignoraFila, unsigned int ignoraColumna) const;

    void Redimensionar(unsigned int filas, unsigned int columnas);

private:

    unsigned int filas;

    unsigned int columnas;

    double **arreglo;
};

#endif // MATRIZ_HPP_INCLUDED
