#include <vector>
#include <string>
#include <iostream>
#include "EjercicioCardio.h"
#include "EjercicioFuerza.h"
#include "Rutina.h"

using namespace std;

int main() {
    vector<Ejercicio*> listaEjercicios;  //Lista dinamica para guardar todos los ejercicios creados
    int opcion;  //Variable para guardar la opcion del menu
    int codigoSiguiente = 100;  //Numero para crear ids automaticos para los ejercicios con codigoSiguiente++

    //Bucle do para ejecutara al menos una vez y que el usuario decida salir
    do { 
        // Mostrar el menu de opciones
        cout << "\n=== SISTEMA DE ENTRENAMIENTO UNAB ===" << endl;
        cout << "1. Crear Ejercicio Cardiovascular" << endl;
        cout << "2. Crear Ejercicio de Fuerza" << endl;
        cout << "3. Ver todos los ejercicios" << endl;
        cout << "4. Actualizar un ejercicio" << endl;
        cout << "5. Generar Rutina Personalizada" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;
        cin.ignore();

        //Switch para manejar cada opcion
        //Evalua opcion y ejecuta el caso que corresponda
        switch (opcion) {
            //Caso 1: Crear ejercicio cardiovascular
            case 1: { 
                string nombre, tipo, intensidad, descripcion, implemento;
                int tiempo, ultimaSemana;
                
                //Nombre
                cout << "Nombre del ejercicio: ";
                getline(cin, nombre); //Leer linea completa de texto con espacios y guardar en nombre
                
                //Tipo
                cout << "Tipo: ";
                getline(cin, tipo);
                
                //Nivel intensidad
                cout << "Intensidad (Basico/Intermedio/Avanzado/Alto rendimiento): ";
                getline(cin, intensidad);
                
                //Tiempo del ejercicio
                cout << "Tiempo en minutos:  ";
                cin >> tiempo;  
                cin.ignore();

                cout << "Descripcion: ";
                getline(cin, descripcion);

                cout << "Implemento: ";
                getline(cin, implemento);

                cout << "Semana del ultimo uso (0 si es nuevo): ";
                cin >> ultimaSemana;
                cin.ignore(); //quita el salto de espacio para que getline despues no lea una linea vacia

                //Crear el ejercicio y agregarlo a la lista vector
                EjercicioCardio* nuevo = new EjercicioCardio
                (codigoSiguiente++, nombre, tipo,  intensidad, tiempo, descripcion, ultimaSemana, implemento);
                listaEjercicios.push_back(nuevo);

                cout << "Ejercicio Cardiovascular creado exitosamente" << endl;
                break;
            }

            //Crear ejercicio de fuerza
            case 2: {  
                string nombre, tipo, intensidad, descripcion;
                int tiempo, repeticiones, series, ultimaSemana;
                double peso;

                cout << "Nombre del ejercicio: ";
                getline(cin, nombre);
                

                cout << "Tipo: ";
                getline(cin, tipo);
                

                cout << "Intensidad (Basico/Intermedio/Avanzado/Alto rendimiento):  ";
                getline(cin, intensidad);
                

                cout << "Tiempo en minutos:  ";
                cin >> tiempo;  
                cin.ignore();
                
                
                cout << "Descripcion: ";
                getline(cin, descripcion);

                cout << "Repeticiones: ";
                cin >> repeticiones;
                cin.ignore();
                

                cout << "Series: ";
                cin >> series;
                cin.ignore();

                cout << "Peso en kg: ";
                cin >> peso;
                cin.ignore();
                

                cout << "Semana del ultimo uso: ";
                cin >> ultimaSemana;
                cin.ignore();

                // Crear el ejercicio y agregarlo a la lista
                EjercicioFuerza* nuevo = new EjercicioFuerza
                (codigoSiguiente++, nombre, tipo, intensidad, tiempo, descripcion, ultimaSemana, repeticiones, series, peso);
                listaEjercicios.push_back(nuevo);

                cout << "Ejercicio de Fuerza creado exitosamente" << endl;
                break;
            }

            //Ver todos los ejercicios
            case 3: {  
                //Verificar que hallan ejercicios creados
                if (listaEjercicios.empty()) {
                    cout << "No hay ejercicios creados aun." << endl;
                } else {
                    cout << "\nLISTADO DE EJERCICIOS" << endl;
                    for (Ejercicio* ejercicio:listaEjercicios) {
                        ejercicio->mostrarInfo();  //polimorfismo para mostrar info
                        cout << endl;
                    }
                }
                break;
            }

            //Actualizar un ejercicio
            case 4: {  
                //Verificacion que hayan ejercicios en vector
                if (listaEjercicios.empty()) {
                    cout << "No hay ejercicios para actualizar." << endl;
                    break;
                }

                //Variable para guardar codigo buscado
                int idBuscar;
                cout << "Ingrese el codigo del ejercicio a modificar: ";
                cin >> idBuscar;
                cin.ignore(); //Limpiar salto de linea

                //Buscar y actualizar
                bool encontrado = false;

                for(Ejercicio* ejercicio:listaEjercicios){

                    if (ejercicio->getCodigo() == idBuscar){
                        //Nuevos datos
                        string nuevoNombre, nuevaDescripcion;

                        cout << "Nuevo nombre: ";
                        getline(cin, nuevoNombre);

                        cout << "Nueva descripcion: ";
                        getline(cin, nuevaDescripcion);

                        //Actualizar usando los metodos set
                        ejercicio->setNombre(nuevoNombre);
                        ejercicio->setDescripcion(nuevaDescripcion);

                        cout << "Datos actualizados correctamente" << endl;
                        encontrado = true;
                        break;
                    }
                }
                
                //Validacion si se encontro
                if (encontrado == false) {
                    cout << "No se encontro un ejercicio con ese codigo." << endl;
                }
                break;
            }

            //Generar rutina personalizada
            case 5: {  
                if (listaEjercicios.empty()) {
                    cout << "No hay ejercicios disponibles para crear una rutina." << endl;
                    break;
                }

                //Datos cliente
                string nombreCliente;
                int semanaActual, numeroEjercicios;
                cout << "Nombre del cliente: ";
                getline(cin, nombreCliente);

                //Validacion nombre no este vacio
                if (nombreCliente.empty()) {
                    cout << "Error: El nombre del cliente no puede estar vacio." << endl;
                    break;
                }

                //Semana actual
                cout << "Semana actual del calendario (no negativo): ";
                cin >> semanaActual;
                cin.ignore();

                //Validacion
                 if (semanaActual < 0) {
                    cout << "Advertencia: Semana negativa, se usara 0." << endl;
                    semanaActual = 0;
                }

                //Cantidad de ejercicios en la rutina
                cout << "Cuantos ejercicios desea en la rutina: ";
                cin >> numeroEjercicios;
                cin.ignore();

                //Validación 
                if (numeroEjercicios <= 0) {
                    cout << "Error: Debe elegir al menos 1 ejercicio." << endl;
                    break;
                }


                // Crear la rutina
                Rutina* nuevaRutina = new Rutina(nombreCliente, semanaActual);


                // Mostrar ejercicios disponibles para la seleccion 
                cout << "Ejercicios disponibles:" << endl;
                for (Ejercicio* ejercicio:listaEjercicios) {
                    cout << "[" << ejercicio->getCodigo() << "] " << ejercicio->getNombre() << endl;
                }

                //Seleecionar ejercicios para la rutina
                cout << "Seleccione los ejercicios: " << endl;
                int ejerciciosAgregados = 0; 
                while (ejerciciosAgregados < numeroEjercicios) { 

                    int idEjercicio; //Variable para la id del ejercicio
                    cout << "ID del ejercicio " << (ejerciciosAgregados + 1) << ": ";
                    cin >> idEjercicio;
                    cin.ignore();
                    

                    bool agregado = false; //Suponer de inicio que no esta
                    for (Ejercicio* ejercicio:listaEjercicios) {
                        //Coincide con el codigo?
                        if (ejercicio->getCodigo() == idEjercicio) {
                            nuevaRutina->agregarEjercicio(ejercicio, semanaActual);
                            cout << "Ejercicio agregado: " << ejercicio->getNombre() << endl;
                            agregado = true;
                            break;
                        }
                    }

                    if (agregado == true){
                        ejerciciosAgregados++;
                    }

                    if (agregado == false) {
                        cout << "ID no encontrado, intenta de nuevo." << endl;
                    }
                }

                //Mostrar resultado
                nuevaRutina->mostrarRutina();
                
                //Liberar memoria
                delete nuevaRutina;
                
                break;
            }

            case 0: {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            
            default: {
                cout << "Opcion invalida. Intenta de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 0);

    // Liberar la memoria de todos los ejercicios al final
    for (Ejercicio* ejercicio:listaEjercicios) {
        delete ejercicio;
    }
    listaEjercicios.clear();  // Limpiar el vector

    return 0;
}
