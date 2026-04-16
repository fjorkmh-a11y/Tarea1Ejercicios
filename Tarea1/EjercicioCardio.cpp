#include "EjercicioCardio.h"

//Implementacion de constructor. Destructor. Get y set. Mostrarinfo()

//Constructor para llamar clase padre
EjercicioCardio::EjercicioCardio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana, string implemento)

    //Llamar a clase padre
    :Ejercicio(codigo, nombre, tipo, intensidad, tiempo, descripcion, ultimaSemana){
        this->implemento = implemento; //Atributo propio
    }

//Destructor vacio. No hay memoria dinamica.
EjercicioCardio::~EjercicioCardio(){}

//Metodos get y set
string EjercicioCardio::getImplemento() {
    return implemento;
}

void EjercicioCardio::setImplemento(string implemento){
    this-> implemento = implemento; //Parametro coincide con atributo: this->   
}

//Polimorfismo para mostrar info general mas la propia de cardio
void EjercicioCardio::mostrarInfo(){
    Ejercicio::mostrarInfo();
    //Detalles propios de cardio
    cout << "Tipo: Cardiovascular" << endl;
    cout << "Implemento necesario: " << implemento << endl;
}
