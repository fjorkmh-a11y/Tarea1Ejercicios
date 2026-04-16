#ifndef RUTINA_H
#define RUTINA_H

#include <vector> //Contenedor dinamico. Array que crece solo
#include <string>
#include "Ejercicio.h"

using namespace std;

class Rutina{
    private:
        string nombreCliente;
        int numeroSemana;

        //lista de puntero. Apuntando a objetos concretos(cardio, fuerza)
        vector<Ejercicio*> ejercicios; 
        /* Ejercicio*: puntero a un objeto de Ejercicio
        ejercicios: lista dinamica de punteros*/

    public:
        //Constructor con cliente + semana
        Rutina(string nombreCliente, int numeroSemana);
        ~Rutina();

        //Regla Negocio: Metodo que valide la restriccion de no repetir 2 semanas
        /* -Como Parametros recibe Ejercicio* ejercicio para que acepte cualquier ejercicio
        y la regla de negocio numero de semana
        - Si pasa validacion, guarda el ejercicio en el vector*/
        bool agregarEjercicio(Ejercicio* ejercicio, int numeroSemana);


        //Calcular tiempo total de la rutina
        int calcularTiempoTotal();

        //ver rutina
        void mostrarRutina();

        //Metodos get de los atributos
        string getnombreCliente();
        int getnumeroSemana();

    };          

#endif
