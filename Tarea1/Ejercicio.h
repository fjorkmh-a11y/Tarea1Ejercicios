#include <iostream>
using namespace std;


//Clase base Ejercicio
class Ejercicio{
    private:
        int codigo;
        string nombre;
        string tipo;
        string intensidad;
        int tiempo;
        string descripcion;
        int ultimaSemana; 
        
    public: 
        //Constructor 
        Ejercicio(int codigo, string nombre, string tipo, string intensidad, int tiempo, string descripcion, int ultimaSemana);

        //Destructor
        virtual ~Ejercicio(){}

        //Virtual para ejecutar las clases hijas
        virtual void mostrarInfo(); 


        //Metodos get para obtener los datos
        int getTiempo();
        int getCodigo();
        int getultimaSemana();
        string getNombre();
        string getTipo();
        string getIntensidad();

        //Metodos set para modificar datos
        void setNombre(string nombre);
        void setTipo(string tipo);
        void setIntensidad(string intensidad);
        void setTiempo(int tiempo);
        void setDescripcion(string descripcion);
        void setultimaSemana(int ultimaSemana);



};
#endif
