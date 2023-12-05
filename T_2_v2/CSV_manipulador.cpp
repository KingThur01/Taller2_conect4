#include "CSV_manipulador.h"

static void crearCSV(const string& nombreArchivo, const vector<vector<string>>& datos) {
    
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const auto& fila : datos) {
            for (const auto& elemento : fila) {
                archivo << elemento << ",";
            }
            archivo << "\n";
        }
        archivo.close();
        cout << "Archivo CSV creado: " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
}

static vector<vector<string>> leerCSV(const string& nombreArchivo) {
    vector<vector<string>> datos;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while ( getline(archivo, linea)) {
            vector< string> fila;
            stringstream ss(linea);
            string elemento;
            while (getline(ss, elemento, ',')) {
                fila.push_back(elemento);
            }
            datos.push_back(fila);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
    }

    return datos;
}

static void modificarCSV(const string& nombreArchivo, int fila, int columna, const string& nuevoValor) {
    vector<vector<string>> datos = leerCSV(nombreArchivo);

    if (fila < datos.size() && columna < datos[fila].size()) {
        datos[fila][columna] = nuevoValor;
        crearCSV(nombreArchivo, datos);
        cout << "Valor modificado en el archivo CSV." << endl;
    } else {
        cerr << "Índices de fila o columna fuera de rango." << endl;
    }
}