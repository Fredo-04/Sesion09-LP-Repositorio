#include <iostream>  // Incluye la biblioteca de entrada/salida estándar
#include <vector>    // Incluye la biblioteca de vectores

using namespace std; // Permite el uso de nombres de la biblioteca estándar de C++ sin el prefijo std::

template <typename T> // Declaración de una plantilla de clase, el tipo T será reemplazado por un tipo específico al usar la clase

class Unaclase {
private:
    vector<T> arreglo; // Un vector que almacenará elementos de tipo T

public:
    Unaclase(int size) : arreglo(size) {} // Constructor de la clase, crea un vector de tamaño "size"

    T& operator[](int index) { // Sobrecarga del operador [] para acceder a los elementos del vector
        if (index < 0 || index >= arreglo.size()) { // Comprueba si el índice está dentro de los límites del vector
            cout << "Índice fuera de rango: " << index << endl; // Imprime un mensaje de error si el índice está fuera de rango
            exit(1); // Finaliza el programa con un código de error
        }
        return arreglo[index]; // Devuelve una referencia al elemento en la posición "index" del vector
    }
};

int main() {
    Unaclase<int> listnumeros(5); // Crea un objeto de la clase Unaclase con elementos de tipo int y tamaño 5

    listnumeros[0] = 10; // Accede al primer elemento del vector y le asigna el valor 10
    cout << listnumeros[0] << endl; // Imprime el valor del primer elemento del vector

    cout << listnumeros[10] << endl; // Intenta acceder a un elemento fuera de rango, lo cual generará un mensaje de error y finalizará el programa

    return 0; // Finaliza el programa con código de retorno 0 (indicando que el programa se ha ejecutado correctamente)
}
