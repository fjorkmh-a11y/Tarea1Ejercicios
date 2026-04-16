#ifndef EJERCICIOCARDIO_H
#define EJERCICIOCARDIO_H

#include "Ejercicio.h"

//Clase hija cardio heredando de clase Ejercicio
class EjercicioCardio:public Ejercicio{

    private:
        string implemento; //Atributo especifico privado. 

    public: 
        //Constructo recibe lo de clase padre y lo propio
        EjercicioCardio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana, string implemento);

        //Destructor
        ~EjercicioCardio();

        //Get y set para EjercicioCardio
        string getImplemento();     
        void setImplemento(string implemento);


        //Sobreescribir el metodo para mostrar la informacion
        void mostrarInfo() override;

        };

#endif
