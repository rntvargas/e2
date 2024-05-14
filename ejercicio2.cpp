#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream archivo_entrada("C:/Users/renat/Desktop/ejercicio2/ejercicio2.txt");
    ofstream archivo_salida("C:/Users/renat/Desktop/ejercicio2/promedios.txt");

      if (!archivo_entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string nombre, materia_nota;
    double nota, suma_notas;
    int num_materias;
    while (archivo_entrada >> nombre) {
        suma_notas = 0.0;
        num_materias = 0;
        getline(archivo_entrada, materia_nota);
        stringstream ss(materia_nota);
        while (ss >> materia_nota >> nota) {
            suma_notas += nota;
            num_materias++;
        }
        if (num_materias > 0) {
            double promedio = suma_notas / num_materias;
            archivo_salida << nombre << ", Promedio: " << fixed << setprecision(2) << promedio << endl;
        } else {
            archivo_salida << nombre << ", Promedio: No se pueden calcular las notas" << endl;
        }
    }

    archivo_entrada.close();
    archivo_salida.close();
    cout << "Los promedios se han calculado y guardado en el archivo 'promedios.txt'." << endl;

    return 0;
}