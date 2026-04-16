#ifndef EJERCICIOFUERZA_H
#define EJERCICIOFUERZA_H

#include "Ejercicio.h"

//Clase Fuerza
class EjercicioFuerza:public Ejercicio {
    private:
        int repeticiones;
        int series;
        double peso;

    public:
        EjercicioFuerza(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana, 
            int repeticiones, int series, double peso);

        ~EjercicioFuerza();


        //Metodos get y set de la clase fuerza
        int getRepeticiones();
        void setRepeticiones(int repeticiones);
        int getSeries();
        void setSeries(int series);
        double getPeso();
        void setPeso(double peso);

        //Menu polimorfo
        void mostrarInfo() override;
};

#endif
