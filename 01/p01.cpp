#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
template <typename T> 
class SafeArray { 
private: 
    vector<T> arr; 
public: 
    explicit SafeArray(int size) : arr(size) {} 
    T& operator[](int index) { 
        if (index < 0 || index >= arr.size()) { 
            cout << "Índice fuera de rango: " << index << endl; 
            exit(1); 
        } 
        return arr[index]; 
    } 
    int getSize() const { 
        return arr.size(); 
    } 
}; 
void informacionAlumno(SafeArray<string>& studentList) { 
    int num; 
    cout << "Indique de qué alumno desea saber su nombre: "; 
    cin >> num; 
    cout << studentList[num] << endl; 
} 
void mostrarListaAlumnos(SafeArray<string>& studentList) { 
    cout << "\nLista de alumnos:\n"; 
    for (int i = 0; i < studentList.getSize(); ++i) { 
        cout << "Alumno " << (i + 1) << ": " << studentList[i] << endl; 
    } 
} 
void rellenarDatos(SafeArray<string>& studentList) { 
    for (int i = 0; i < studentList.getSize(); ++i) { 
        string name; 
        cout << "Ingrese el nombre del alumno " << (i + 1) << ": "; 
        cin >> name; 
        studentList[i] = name; 
    } 
} 

int main() { 
    int cantidadAlumnos; 
    cout << "Indique cuántos alumnos tiene su clase: "; 
    cin >> cantidadAlumnos; 
    SafeArray<string> studentList(cantidadAlumnos); 
    rellenarDatos(studentList); 
    mostrarListaAlumnos(studentList); 
    informacionAlumno(studentList); 
    informacionAlumno(studentList); 
    return 0; 
} 