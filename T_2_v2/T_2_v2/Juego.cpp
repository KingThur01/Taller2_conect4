#include "Juego.h"


Juego::Juego() : jugador1('X'), jugador2('O'), arbol(jugador1) {}

void Juego::iniciarJuego() {
    int turno = 1;
    bool victoria = false;

    do {
        tablero.mostrarTablero();

        Jugador& jugadorActual = (turno % 2 == 1) ? jugador1 : jugador2;

        int columna;
        do {
            columna = jugadorActual.realizarMovimiento();
        } while (!tablero.realizarJugada(columna, jugadorActual.obtenerFicha()));

        victoria = tablero.verificarVictoria(jugadorActual.obtenerFicha());

        turno ++;
    } while (!victoria);

    tablero.mostrarTablero();
    cout << "¡Felicidades! Jugador " << ((turno - 1) % 2 + 1) << " ha ganado.\n";
}

void Juego::realizarMovimiento() {

    // Registra el movimiento en el vector
    //movimientos.push_back(make_pair(jugadorActual.obtenerFicha(), columna));

    // Actualiza la victoria
    //victoria = tablero.verificarVictoria(jugadorActual.obtenerFicha());
}


void Juego::guardarPartidaCSV(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const auto& movimiento : movimientos) {
            archivo << movimiento.first << "," << movimiento.second << "\n";
        }
        archivo.close();
        cout << "Partida guardada en " << nombreArchivo << "\n";
    } else {
        cout << "No se pudo abrir el archivo para guardar la partida.\n";
    }
}

void Juego::jugarContraIA() {
    int turno = 1;
    bool victoria = false;

    do {
        tablero.mostrarTablero();
        if (turno % 2 == 1) {
            // Turno del jugador humano
            int columna;
            do {
                columna = jugador1.realizarMovimiento();
            } while (!tablero.realizarJugada(columna, jugador1.obtenerFicha()));
        } else {
            // Turno de la IA (Minimax)
            int mejorMovimiento = arbol.obtenerMejorMovimiento();
            tablero.realizarJugada(mejorMovimiento, jugador2.obtenerFicha());
        }
        victoria = tablero.verificarVictoria(jugador1.obtenerFicha()) || tablero.verificarVictoria(jugador2.obtenerFicha());
        turno++;
    } while (!victoria);

    tablero.mostrarTablero();
    cout << "¡Felicidades! Jugador " << ((turno - 1) % 2 + 1) << " ha ganado.\n";
}