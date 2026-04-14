#include "Ejercicio.h"

//Definicion del constructor 
Ejercicio::Ejercicio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana){
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipo = tipo;
    this->intensidad = intensidad;
    this->tiempo = tiempo;
    this->descripcion = descripcion;
    this->ultimaSemana = ultimaSemana;
}

//Destructor
Ejercicio::~Ejercicio(){}

//Metodos

//Metodo virtual
void Ejercicio::mostrarInfo(){
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << intensidad << endl;
    cout << "Tiempo: " << tiempo << "min" << endl;
    cout << "Descripcion: " << descripcion << endl;

}

//Implementacion metodos get
int Ejercicio::getTiempo(){
    return tiempo;
}
int Ejercicio::getCodigo() { return codigo; }
int Ejercicio::getultimaSemana() { return ultimaSemana; }
string Ejercicio::getNombre() { return nombre; }
string Ejercicio::getIntensidad() { return intensidad; }

//Implementacion metodos set
void Ejercicio::setNombre(string nombre) {this->nombre = nombre; }
void Ejercicio::setIntensidad(string intensidad) {this->intensidad = intensidad; }
void Ejercicio::setTiempo(int tiempo) {this->tiempo = tiempo; }
void Ejercicio::setDescripcion(string descripcion) {this->descripcion = descripcion; }
void Ejercicio::setultimaSemana(int ultimaSemana) {this->ultimaSemana = ultimaSemana; }


