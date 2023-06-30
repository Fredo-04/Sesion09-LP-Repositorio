#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  
class ClaseExcepcion : public exception{  
    public:
        const char* what() const noexcept override{
        return "Error, fuera de rango.";  
    }; 
};  

class Alumno    
{  
    public:  
        string nombre;  
        int edad;  
        string carrera;  
        Alumno(string n, int e, string c): nombre(n), edad(e), carrera(c){}  
        void mostrarAlumno(){  
        cout<<"Alumno: "<<nombre<<", edad: "<<edad<<", carrera: "<<carrera<<endl;  
        }  
};  
class EstructuraDeDatos 
{  
    private:  
        vector<Alumno> alumnos;  
        int tamanio;  
    public:  
        EstructuraDeDatos(int tam):tamanio(tam){}  
        void operator [](int indice){ 
            if (indice >=1 && indice <= tamanio){  
                alumnos[indice].mostrarAlumno();  
            }else{  
                throw ClaseExcepcion();  
            }  
        }  
        EstructuraDeDatos& agregarAlumno(Alumno a){  
            alumnos.push_back(a);  
        }  
};  
int main(){  
    int opcion;  
    Alumno alumno1("Luis", 18, "Ingenieria de sistemas");  
    Alumno alumno2("Ximena", 18, "Ingenieria biotecnologica");  
    Alumno alumno3("Rodrigo", 20, "Ingeniera de minas");  
    Alumno alumno4("Jose", 19, "Derecho");  
    Alumno alumno5("Alexa", 18, "Psicologia");  
    EstructuraDeDatos MiEstructura(5);  
    MiEstructura.agregarAlumno(alumno1).agregarAlumno(alumno2).agregarAlumno(alumno3).agregarAlumno(alumno4).agregarAlumno(alumno5);  
    try  
    {  
        cout<<"Ingrese un una opcion del 1 al 5 para ver los estudiantes."<<endl;
        cin>>opcion;
        MiEstructura[opcion];  
    } catch(const ClaseExcepcion &c){
        cout<<"Excepcion..."<<c.what()<<endl;
    }
    return 0;
};