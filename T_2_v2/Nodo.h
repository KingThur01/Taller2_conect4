#ifndef NODO_H
#define NODO_H

#include <vector>
#include <iostream>
#include "Tablero.h"

using namespace std;

class Nodo {
    private:
        int filas;
        int columnas;
        vector<vector<char>> tablero;
        int ultimaColumna;
        int valor;
        vector<Nodo> hijos;

    public:
        Nodo(int filas, int columnas); // Constructor para inicializar el nodo con un tablero vacío.
        
        Nodo();
        Nodo(const Nodo& otro); // Constructor de copia.
        Nodo(const Tablero& tablero);

        Tablero obtenerTablero() const;

        int obtenerFilas() const;
        int obtenerColumnas() const;

        char obtenerFichaEnCasilla(int fila, int columna) const;
        int obtenerUltimaColumna() const;
        void establecerValor(int valor);
        int obtenerValor() const;

        void realizarMovimiento(int columna, char ficha);
        const vector<Nodo>& obtenerHijos() const { return hijos;}
        void agregarHijo(const Nodo& hijo) { hijos.push_back(hijo);}

};

#endif // NODO_H
