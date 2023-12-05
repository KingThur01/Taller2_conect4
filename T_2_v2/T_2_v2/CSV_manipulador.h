#ifndef CSV_MANIPULADOR_H
#define CSV_MANIPULADOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class CSV_manipulador {
public:
    static void crearCSV(const string& nombreArchivo, const vector<vector<string>>& datos);
    static vector<vector<string>> leerCSV(const string& nombreArchivo);
    static void modificarCSV(const string& nombreArchivo, int fila, int columna, const string& nuevoValor);
};

#endif // CSV_MANIPULADOR_H
