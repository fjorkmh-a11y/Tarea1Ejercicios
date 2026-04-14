#include <vector>
#include <string>
#include <iostream>
#include "EjercicioCardio.h"
#include "EjercicioFuerza.h"
#include "Rutina.h"

using namespace std;

int main() {
    vector<Ejercicio*> listaEjercicios;  // Lista para guardar todos los ejercicios creados
    int opcion;  // Variable para guardar la opcion del menu
    int codigoSiguiente = 100;  // Numero para crear IDs automaticos para los ejercicios

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

        // Leer la opcion del usuario y validar que sea un numero
        //Si entrada erronea, el if ! lo niega y muestra error
        if (!(cin >> opcion)) {
            cout << "Error: Debes ingresar un numero valido." << endl;
            cin.clear();  // Limpiar el estado de error de cin
            cin.ignore(10000, '\n');  // Ignorar el resto de la linea
            continue;  // Volver al inicio del bucle
        }

        // Limpiar el buffer despues de leer el numero
        cin.ignore(10000, '\n');

        //Switch para manejar cada opcion
        //Evalua opcion y ejecuta el caso que corresponda
        switch (opcion) {
            //Caso 1: Crear ejercicio cardiovascular
            case 1: { 
                string nombre, tipo, intensidad, descripcion, implemento;
                int tiempo, ultimaSemana;
                
                //Nombre
                cout << "Nombre del ejercicio: ";
                getline(cin, nombre); //Leer linea completa de texto
                //Verificar que no este vacia
                if (nombre.empty()) {
                    cout << "Error: El nombre no puede estar vacio." << endl;
                    break;
                }

                //Tipo
                cout << "Tipo: ";
                getline(cin, tipo);
                if (tipo.empty()) {
                    cout << "Error: El tipo no puede estar vacio." << endl;
                    break;
                }
                //Nivel intensidad
                cout << "Intensidad (Basico/Intermedio/Avanzado/Alto rendimiento): ";
                getline(cin, intensidad);
                if (intensidad.empty()) {
                    cout << "Error: El nivel no puede estar vacio." << endl;
                    break;
                }
                //Tiempo del ejercicio
                cout << "Tiempo en minutos: ";
                //Verificar entrada correcta o que sea positivo
                if (!(cin >> tiempo) || tiempo <= 0) {
                    cout << "Error: El tiempo debe ser un numero positivo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                cout << "Descripcion: ";
                getline(cin, descripcion);

                cout << "Implemento: ";
                getline(cin, implemento);

                cout << "Semana del ultimo uso (0 si es nuevo, debe ser no negativo): ";
                if (!(cin >> ultimaSemana) || ultimaSemana < 0) {
                    cout << "Error: La semana debe ser un numero no negativo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                //Crear el ejercicio y agregarlo a la lista vector
                listaEjercicios.push_back(new EjercicioCardio(codigoSiguiente++, nombre, tipo,  intensidad, tiempo, descripcion, ultimaSemana, implemento));
                cout << "¡Ejercicio Cardiovascular creado exitosamente!" << endl;
                break;
            }

            //Crear ejercicio de fuerza
            case 2: {  
                string nombre, tipo, intensidad, descripcion;
                int tiempo, repeticiones, series, ultimaSemana;
                double peso;

                cout << "Nombre del ejercicio: ";
                getline(cin, nombre);
                if (nombre.empty()) {
                    cout << "Error: El nombre no puede estar vacio." << endl;
                    break;
                }

                cout << "Tipo: ";
                getline(cin, tipo);
                if (tipo.empty()) {
                    cout << "Error: El tipo no puede estar vacio." << endl;
                    break;
                }

                cout << "Intensidad (Basico/Intermedio/Avanzado/Alto rendimiento):  ";
                getline(cin, intensidad);
                if (intensidad.empty()) {
                    cout << "Error: El nivel no puede estar vacio." << endl;
                    break;
                }

                cout << "Tiempo en minutos (debe ser positivo): ";
                if (!(cin >> tiempo) || tiempo <= 0) {
                    cout << "Error: El tiempo debe ser un numero positivo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                cout << "Descripcion: ";
                getline(cin, descripcion);

                cout << "Repeticiones (debe ser positivo): ";
                if (!(cin >> repeticiones) || repeticiones <= 0) {
                    cout << "Error: Las repeticiones deben ser un numero positivo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                cout << "Series (debe ser positivo): ";
                if (!(cin >> series) or series <= 0){
                    cout << "Error: Las series deben ser numero positivo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                cout << "Peso en kg (debe ser positivo): ";
                if (!(cin >> peso) || peso <= 0) {
                    cout << "Error: El peso debe ser un numero positivo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                cout << "Semana del ultimo uso (debe ser positivo): ";
                if (!(cin >> ultimaSemana) || ultimaSemana < 0) {
                    cout << "Error: La semana debe ser un numero no negativo." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                cin.ignore(10000, '\n');

                // Crear el ejercicio y agregarlo a la lista
                listaEjercicios.push_back(new EjercicioFuerza(codigoSiguiente++, nombre, tipo, intensidad, tiempo, descripcion, ultimaSemana, repeticiones, series, peso));
                cout << "¡Ejercicio de Fuerza creado exitosamente!" << endl;
                break;
            }

            // Ver todos los ejercicios
            case 3: {  
                //Verificar que hayan ejercicios creados
                if (listaEjercicios.empty()) {
                    cout << "No hay ejercicios creados aun." << endl;
                } else {
                    cout << "\n--- LISTADO DE EJERCICIOS ---" << endl;
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

                        //Actualizar usando los set
                        ejercicio->setNombre(nuevoNombre);
                        ejercicio->setDescripcion(nuevaDescripcion);

                        cout << "¡Datos actualizados correctamente!" << endl;
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
                int semanaActual;
                cout << "Semana actual del calendario (no negativo): ";
                cin >> semanaActual;
                cin.ignore();

                //Validacion
                 if (semanaActual < 0) {
                    cout << "Advertencia: Semana negativa, se usara 0." << endl;
                    semanaActual = 0;
                }

                //Cantidad de ejercicios en la rutina
                int numeroEjercicios;
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
                for (int i = 0; i < numeroEjercicios; i++) {

                    int idEjercicio; //Variable para la id del ejercicio
                    cout << "ID del ejercicio " << (i + 1) << ": ";
                    cin >> idEjercicio;
                    cin.ignore();
                    

                    bool agregado = false;
                    for (Ejercicio* ejercicio:listaEjercicios) {
                        if (ejercicio->getCodigo() == idEjercicio) {
                            nuevaRutina->agregarEjercicio(ejercicio, semanaActual);
                            cout << "Ejercicio agregado: " << ejercicio->getNombre() << endl;
                            agregado = true;
                            break;
                        }
                    }
                    if (!agregado) {
                        cout << "ID no encontrado, intenta de nuevo." << endl;
                        i--;  // Repetir este paso
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
    for (Ejercicio* ejercicio : listaEjercicios) {
        delete ejercicio;
    }
    listaEjercicios.clear();  // Limpiar el vector

    return 0;
}