#include "ArbolJuego.h"

Nodo::Nodo(/* parámetros */) {
}

ArbolJuego::ArbolJuego(Jugador& jugadorHumano) : jugadorIA('X'), jugadorHumano(jugadorHumano) {
     // Suponiendo que 'X' es la ficha inicial
}

void ArbolJuego::construirArbol(int profundidad) {
    construirArbolRecursivo(raiz, profundidad, true); // Comienza con el jugador maximizador.
}

void ArbolJuego::construirArbolRecursivo(Nodo& nodo, int profundidad, bool esMaximizador) {
    if (profundidad == 0 || tablero.verificarVictoria(jugadorIA.obtenerFicha()) || tablero.verificarVictoria(jugadorIA.obtenerFicha())) {
        int valorEvaluacion = evaluarNodo(nodo);
        nodo.establecerValor(valorEvaluacion);
        return;
    }

    for (int columna = 0; columna < Tablero::COLUMNAS; columna++) {
        if (tablero.esColumnaValida(columna)) {
            Tablero nuevoTablero = tablero; // Hacer una copia del tablero actual
            nuevoTablero.realizarJugada(columna, esMaximizador ? jugadorIA.obtenerFicha() : jugadorIA.obtenerFicha());

            Nodo nuevoNodo(nuevoTablero); // Crear un nuevo nodo con el tablero modificado
            nuevoNodo.establecerValor(columna);

            nodo.agregarHijo(nuevoNodo);  // Agrega el nuevo nodo como hijo del nodo actual.
        }
    }
}

int ArbolJuego::minimax(const Nodo &nodo, int profundidad, bool esMaximizador)
{
    if (profundidad == 0 || nodo.obtenerHijos().empty()) {
        // Si hemos alcanzado la profundidad máxima o es un nodo terminal, retornamos el valor del nodo.
        return evaluarNodo(nodo);
    }

    if (esMaximizador) {
        int mejorValor = numeric_limits<int>::min();
        for (const auto& hijo : nodo.obtenerHijos()) {
            int valor = minimax(hijo, profundidad - 1, false);
            mejorValor = max(mejorValor, valor);
        }
        return mejorValor;
    } else {
        int mejorValor = numeric_limits<int>::max();
        for (const auto& hijo : nodo.obtenerHijos()) {
            int valor = minimax(hijo, profundidad - 1, true);
            mejorValor = min(mejorValor, valor);
        }
        return mejorValor;
    }
}

int ArbolJuego::obtenerMejorMovimiento() {
    int mejorMovimiento = 0;
    int mejorValor = numeric_limits<int>::min();

    for (int columna = 0; columna < Tablero::COLUMNAS; columna++) {
        if (tablero.esColumnaValida(columna)) {
            tablero.realizarJugada(columna, jugadorIA.obtenerFicha());
            int valor = minimax(raiz, profundidad - 1, false);
            tablero.deshacerJugada(columna);

            if (valor > mejorValor) {
                mejorValor = valor;
                mejorMovimiento = columna;
            }
        }
    }
    return mejorMovimiento;
}

int evaluarNodo(const Nodo& nodo) {
    int puntaje = 0;

    // Evaluar en horizontal
    for (int fila = 0; fila < nodo.obtenerFilas(); fila++) {
        for (int columna = 0; columna <= nodo.obtenerColumnas() - 4; columna++) {
            int contadorFichas = 0;
            for (int i = 0; i < 4; i++) {
                if (nodo.obtenerFichaEnCasilla(fila, columna + i) == 'X') {
                    contadorFichas++;
                } else if (nodo.obtenerFichaEnCasilla(fila, columna + i) == 'O') {
                    contadorFichas--;
                }
            }
            puntaje += contadorFichas;
        }
    }

    // Evaluar en vertical
    for (int fila = 0; fila <= nodo.obtenerFilas() - 4; fila++) {
        for (int columna = 0; columna < nodo.obtenerColumnas(); columna++) {
            int contadorFichas = 0;
            for (int i = 0; i < 4; i++) {
                if (nodo.obtenerFichaEnCasilla(fila + i, columna) == 'X') {
                    contadorFichas++;
                } else if (nodo.obtenerFichaEnCasilla(fila + i, columna) == 'O') {
                    contadorFichas--;
                }
            }
            puntaje += contadorFichas;
        }
    }

    // Evaluar en diagonal (de izquierda a derecha)
    for (int fila = 0; fila <= nodo.obtenerFilas() - 4; fila++) {
        for (int columna = 0; columna <= nodo.obtenerColumnas() - 4; columna++) {
            int contadorFichas = 0;
            for (int i = 0; i < 4; i++) {
                if (nodo.obtenerFichaEnCasilla(fila + i, columna + i) == 'X') {
                    contadorFichas++;
                } else if (nodo.obtenerFichaEnCasilla(fila + i, columna + i) == 'O') {
                    contadorFichas--;
                }
            }
            puntaje += contadorFichas;
        }
    }

    // Evaluar en diagonal (de derecha a izquierda)
    for (int fila = 0; fila <= nodo.obtenerFilas() - 4; fila++) {
        for (int columna = 3; columna < nodo.obtenerColumnas(); columna++) {
            int contadorFichas = 0;
            for (int i = 0; i < 4; i++) {
                if (nodo.obtenerFichaEnCasilla(fila + i, columna - i) == 'X') {
                    contadorFichas++;
                } else if (nodo.obtenerFichaEnCasilla(fila + i, columna - i) == 'O') {
                    contadorFichas--;
                }
            }
            puntaje += contadorFichas;
        }
    }

    return puntaje;
}