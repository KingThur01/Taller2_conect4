#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
    char ficha;

public:
    Jugador(char ficha);
    char obtenerFicha() const;
    int realizarMovimiento() const;
};

#endif // JUGADOR_H
