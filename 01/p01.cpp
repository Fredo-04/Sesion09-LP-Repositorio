#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;  
template <typename T>  
class UnaClase{ 
private:  
    vector<T> arreglo;  
public:  
    UnaClase(int size) : arreglo(size) {}  
    T& operator[](int index) {  
    if (index < 0 || index >= arreglo.size()) {  
        cout << "Índice fuera de rango: " << index +1 << endl;  
        exit(1);  
    }  
    return arreglo[index];  
}  
int getSize() const {  
    return arreglo.size();  
}  
};  

void informacionAlumno(UnaClase<string>& studentList) {  
    int num;  
    cout << "Indique de qué alumno desea saber su nombre: ";  
    cin >> num;  
    cout << studentList[num-1] << endl;  
} 
void mostrarListaAlumnos(UnaClase<string>& studentList) {  
    cout << "\nLista de alumnos:\n";  
    for (int i = 0; i < studentList.getSize(); ++i) {  
        cout << "Alumno " << (i + 1) << ": " << studentList[i] << endl;  
    }  
}  
void rellenarDatos(UnaClase<string>& studentList) {  
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
    UnaClase<string> studentList(cantidadAlumnos);  
    rellenarDatos(studentList);  
    mostrarListaAlumnos(studentList);  
    informacionAlumno(studentList);  
    informacionAlumno(studentList);  
    return 0;
}