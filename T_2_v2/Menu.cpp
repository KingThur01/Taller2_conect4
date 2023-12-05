#include "Menu.h"
#include "Juego.h"


Juego juego;

void ajustarTamanoTerminal() {
    int ancho = 80;
    int alto = 40;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = {0, 0, static_cast<SHORT>(ancho - 1), static_cast<SHORT>(alto - 1)};
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

// Función para mostrar el menú
int mostrarMenu() {
    int opcion;
    cout << "==============================" << endl;
    cout << "||           MENU           ||" << endl;
    cout << "||==========================||" << endl;
    cout << "||  [1] Juego 1 V/S 1       ||" << endl;
    cout << "||  [2] Juego 1 V/S BOT     ||" << endl;
    cout << "||  [3] 1 v/s BOT (corte)   ||" << endl;
    cout << "||  [4] Continuar Partida   ||" << endl;
    cout << "||  [5] Salir               ||" << endl;
    cout << "==============================" << endl;
    cout << "\n > ";
    cin >> opcion;
    return opcion;
}

// Función que muestra el nivel de dificultad
int mostrarNivelDificultad(){
    system("cls");
    int nivel;
    cout << "==============================" << endl;
    cout << "||   Nivel de Dificultad    ||" << endl;
    cout << "||==========================||" << endl;
    cout << "||  [1] Facil               ||" << endl;
    cout << "||  [2] Medio               ||" << endl;
    cout << "||  [3] Dificil             ||" << endl;
    cout << "||  [4] Salir               ||" << endl;
    cout << "==============================" << endl;
    cout << "\n > ";
    cin >> nivel;
    return nivel;
}

// Seleccionar menu
void menu(){
    system("cls");
    int opcion, nivel;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                juego.iniciarJuego();
                break;
            case 2:
                nivel = mostrarNivelDificultad();
                system("cls");

                //juego_vsBot();
                break;
            case 3:
                nivel = mostrarNivelDificultad();
                system("cls");

                //juego_BotCorte_ab();
                break;
            case 4:
                //Continuar Partida en CSV
                break;

            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "\nOpción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);  // Continuar hasta que el usuario elija salir (Opción 4)
}


