#include "EjercicioCardio.h"

//Lista de inicializacion para llamar clase padre
EjercicioCardio::EjercicioCardio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana, string implemento)

    //Llamar a clase padre
    : Ejercicio(codigo, nombre, tipo, intensidad, tiempo, descripcion, ultimaSemana){
        this->implemento = implemento; //Atributo propio
    }

//Destructor vacio. No hay memoria dinamica.
EjercicioCardio::~EjercicioCardio(){}

//Metodos get y set
string EjercicioCardio::getImplemento() {
    return implemento;
}

//PARAMETRO// recibe, no regresa
void EjercicioCardio::setImplemento(string implemento){
    this-> implemento = implemento; //Parametro coincide con atributo: this->   
}

//Mostrar info general mas la propia de cardio
void EjercicioCardio::mostrarInfo(){
    //Llamar al metodo del padre para mostrar la info general basica
    Ejercicio::mostrarInfo();

    //Detalles propios de cardio
    cout << "Tipo: Cardiovascular" << endl;
    cout << "Implemento necesario: " << implemento << endl;
}
