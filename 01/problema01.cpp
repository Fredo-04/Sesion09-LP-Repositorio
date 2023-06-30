#include <iostream> 
#include <vector> 
using namespace std; 
template <typename T> 
class Unaclase{ 
private: 
    vector<T> arreglo; 
public: 
    explicit Unaclase(int size) : arreglo(size) {} 
    T& operator[](int index) { 
        if (index < 0 || index >= arreglo.size()) { 
            cout << "Índice fuera de rango: " << index << endl; 
            exit(1); 
        } 
        return arreglo[index]; 
    } 
}; 
int main() { 
    Unaclase<int> listnumeros(5); 
    listnumeros[0] = 10; 
    cout << listnumeros[0] << endl; 
    cout << listnumeros[10] << endl;  
    return 0; 
} 