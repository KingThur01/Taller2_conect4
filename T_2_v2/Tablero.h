#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
using namespace std;

class Tablero {
    public:
        static const int FILAS = 6;
        static const int COLUMNAS = 7;

    private:
        char tablero[FILAS][COLUMNAS];

    public:
        Tablero();
        void reiniciarTablero();
        void mostrarTablero() const;
        bool realizarJugada(int columna, char ficha);
        bool verificarVictoria(char ficha) const;
        bool esColumnaValida(int columna) const;
        void deshacerJugada(int columna);
};

#endif // TABLERO_H
