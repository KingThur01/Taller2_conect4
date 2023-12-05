#ifndef ARBOLJUEGO_H
#define ARBOLJUEGO_H

#include <vector>
#include <iostream>
#include <limits>
#include "Nodo.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;


class ArbolJuego {
    public:
        ArbolJuego(Jugador& jugadorHumano);

        // Método para construir el árbol de juego hasta cierta profundidad.
        void construirArbol(int profundidad);

        // Obtener el mejor movimiento usando el algoritmo Minimax.
        int obtenerMejorMovimiento();
        int evaluarNodo(const Nodo& nodo);

    private:
        Nodo raiz; // El nodo raíz del árbol de juego.
        Tablero tablero;
        Jugador jugadorIA;  // Asegúrate de tener la declaración de 'jugadorIA'
        Jugador jugadorHumano;  // Asegúrate de tener la declaración de 'jugadorIA'
        
        int profundidad;

        // Métodos internos para implementar la construcción del árbol y el algoritmo Minimax.
        void construirArbolRecursivo(Nodo& nodo, int profundidad, bool esMaximizador);
        int minimax(const Nodo& nodo, int profundidad, bool esMaximizador);
};

#endif // ARBOLJUEGO_H
