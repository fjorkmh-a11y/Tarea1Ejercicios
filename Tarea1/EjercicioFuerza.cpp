#include "EjercicioFuerza.h"


/*IMPLEMENTAR:
Constructor. Destructor. Get y set. Mostrarinfo()*/

//1.Constructor
EjercicioFuerza::EjercicioFuerza(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana, 
            int repeticiones, int series, double peso)
    : Ejercicio(codigo, nombre, tipo, intensidad, tiempo, descripcion, ultimaSemana){
        //Atributos propio clase Fuerza
        this->repeticiones = repeticiones;
        this->series = series;
        this->peso = peso;
    }

//2. Destructor
EjercicioFuerza::~EjercicioFuerza(){}

//Metodos get y set
int EjercicioFuerza::getRepeticiones() {return repeticiones;}
void EjercicioFuerza::setRepeticiones(int repeticiones) {this->repeticiones = repeticiones;}

int EjercicioFuerza::getSeries() {return series;}
void EjercicioFuerza::setSeries(int series) {this->series = series;}

double EjercicioFuerza::getPeso() {return peso;}
void EjercicioFuerza::setPeso(double peso) {this->peso = peso;}


//Polimorfismo para reutilizar base 
void EjercicioFuerza::mostrarInfo(){
    Ejercicio::mostrarInfo(); 

    //Detalles info propio de la clase fuerza
    cout << "Tipo: Fuerza / Pesas" << endl;
    cout << "Repeticiones: " << repeticiones << endl;
    cout << "Series: " << series << endl;
    cout << "Peso: " << peso << endl;


}

