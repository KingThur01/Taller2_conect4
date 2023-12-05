#include "Nodo.h"

Nodo::Nodo(int filas, int columnas) : filas(filas), columnas(columnas), ultimaColumna(-1) {
    tablero.resize(filas, vector<char>(columnas, ' '));  // Inicializar el tablero con un estado vacío.
}

Nodo::Nodo(const Nodo& otro) : filas(otro.filas), columnas(otro.columnas), ultimaColumna(otro.ultimaColumna) {
    tablero = otro.tablero;
}

Nodo::Nodo(const Tablero& tablero)  {
    // Lógica de inicialización adicional si es necesario
}

int Nodo::obtenerFilas() const {
    return filas;
}

int Nodo::obtenerColumnas() const {
    return columnas;
}

char Nodo::obtenerFichaEnCasilla(int fila, int columna) const {
    return tablero[fila][columna];
}

int Nodo::obtenerUltimaColumna() const {
    return ultimaColumna;
}

void Nodo::establecerValor(int valor) {
    this->valor = valor;
}

int Nodo::obtenerValor() const {
    return valor;
}

void Nodo::realizarMovimiento(int columna, char ficha) {
   // Verificar que la columna sea válida y que no esté llena.
    if (columna >= 0 && columna < columnas) {
        // Encontrar la primera fila vacía en la columna.
        int fila = filas - 1;
        while (fila >= 0 && tablero[fila][columna] != ' ') {
            fila--;
        }

        // Realizar el movimiento.
        if (fila >= 0) {
            tablero[fila][columna] = ficha;
            ultimaColumna = columna;
        } else {
            cout << "\n==========================================" << endl; 
            cout << "||  Columna llena. Intente otra columna  ||" << endl;
            cout << "==========================================\n" << endl;
        }
    } else {
        cout << "\n==================================================" << endl;
        cout << "||  Movimiento INVALIDO. Intente de nuevamente  ||" << endl;
        cout << "==================================================\n" << endl;
    }
}
