#include "Jugador.h"

Jugador::Jugador(char ficha) : ficha(ficha) {}

char Jugador::obtenerFicha() const {
    return ficha;
}

int Jugador::realizarMovimiento() const {
    int columna;
    cout << "\nJugador, ingrese columna (1-7)" << endl;
    cout << " > ";

    cin >> columna;
    return columna-1;
}
