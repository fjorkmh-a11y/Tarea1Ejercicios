#include "Rutina.h"
#include <iostream>


//Constructor para inicializar datos
Rutina::Rutina(string nombreCliente, int numeroSemana){
    this->nombreCliente = nombreCliente;
    this->numeroSemana = numeroSemana;
}

//Destructor definicion
Rutina::~Rutina(){}

//Def metodo agregar ejercicio
bool Rutina::agregarEjercicio(Ejercicio* ejercicio, int numeroSemana){
    //Verificar si ejercicio fue usado semana anterior
    //Comparar ejercicio->getultimaSemana con la semana anterior
    //llamar a metodo del objeto al que apunta ejercicio->
    if (ejercicio->getultimaSemana() == numeroSemana - 1) {
        // No se puede agregar porque fue usado la semana anterior
        cout << "Error: Ejercicio usado semana anterior" << endl;
        return false;
    } else {
        //Si no se uso, agregar el ejercicio al vector
        ejercicios.push_back(ejercicio);
        
        // Actualizar la última semana en que se usó el ejercicio
        //llamar al metodo del objeto al que apunta ejercicio
        ejercicio->setultimaSemana(numeroSemana);
        return true;
    }
}

//Metodo para calcular tiempo
int Rutina::calcularTiempoTotal(){
    int total = 0;
    //Recorrer el vector sumando tiempos  
    //Usar metodo size() del vector para devolver cantidad 
    for (int i = 0; i < ejercicios.size(); i++) {
        total += ejercicios[i]->getTiempo();
    }
    return total;
}

//Mostrar rutina
void Rutina::mostrarRutina(){
    cout << "\nRUTINA DE ENTRENAMIENTO" << endl;
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Semana: " << numeroSemana << endl;
    cout << "Total de ejercicios: " << ejercicios.size() << endl;
    cout << "Tiempo estimado de la rutina: " << calcularTiempoTotal() << " minutos" << endl;

    cout << "\nDETALLE DE EJERCICIOS" << endl;
    for (int i = 0; i < ejercicios.size(); i++) {
        cout << "\nEjercicio " << (i + 1) << ":" << endl;
        ejercicios[i]->mostrarInfo();
    }
}
