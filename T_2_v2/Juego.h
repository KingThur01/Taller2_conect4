#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include "ArbolJuego.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Juego {
private:
    Tablero tablero;
    Jugador jugador1;
    Jugador jugador2;
    vector<pair<char, int>> movimientos; // Usando pair directamente
    bool victoria;
    ArbolJuego arbol;

public:
    Juego();
    void iniciarJuego();
    void realizarMovimiento();
    void guardarPartidaCSV(const string& nombreArchivo) const;
    void jugarContraIA();
};

#endif // JUEGO_H
