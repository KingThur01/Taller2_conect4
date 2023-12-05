#include "Tablero.h"

Tablero::Tablero() {
    reiniciarTablero();
}

void Tablero::reiniciarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void Tablero::mostrarTablero() const {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "| " << tablero[i][j] << " |";
        }
        cout << endl;
    }
    cout << "----------------------------------\n [1]  [2]  [3]  [4]  [5]  [6]  [7]" << endl; // Números de columna
}

bool Tablero::realizarJugada(int columna, char ficha) {
    for (int i = FILAS - 1; i >= 0; i--) {
        if (tablero[i][columna] == ' ') {
            tablero[i][columna] = ficha;
            return true;
        }
    }
    cout << "\n==========================================" << endl; 
    cout << "||  Columna llena. Intente otra columna  ||" << endl;
    cout << "==========================================\n" << endl; 
    return false; // Columna llena
}

bool Tablero::verificarVictoria(char ficha) const {
    // Verificar en horizontal
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j <= COLUMNAS - 4; j++) {
            if (tablero[i][j] == ficha && tablero[i][j + 1] == ficha &&
                tablero[i][j + 2] == ficha && tablero[i][j + 3] == ficha) {
                return true;
            }
        }
    }

    // Verificar en vertical
    for (int i = 0; i <= FILAS - 4;i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == ficha && tablero[i + 1][j] == ficha &&
                tablero[i + 2][j] == ficha && tablero[i + 3][j] == ficha) {
                return true;
            }
        }
    }

    // Verificar en diagonal (de izquierda a derecha)
    for (int i = 0; i <= FILAS - 4; i++) {
        for (int j = 0; j <= COLUMNAS - 4; j++) {
            if (tablero[i][j] == ficha && tablero[i + 1][j + 1] == ficha &&
                tablero[i + 2][j + 2] == ficha && tablero[i + 3][j + 3] == ficha) {
                return true;
            }
        }
    }

    // Verificar en diagonal (de derecha a izquierda)
    for (int i = 0; i <= FILAS - 4; i++) {
        for (int j = 3; j < COLUMNAS; j++) {
            if (tablero[i][j] == ficha && tablero[i + 1][j - 1] == ficha &&
                tablero[i + 2][j - 2] == ficha && tablero[i + 3][j - 3] == ficha) {
                return true;
            }
        }
    }

    return false;
}

bool Tablero::esColumnaValida(int columna) const {
    return tablero[0][columna] == ' ';
}

void Tablero::deshacerJugada(int columna) {
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][columna] != ' ') {
            tablero[i][columna] = ' ';
            break;
        }
    }
}

