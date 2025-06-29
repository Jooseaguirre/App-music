#include <iostream>
#include <cstring>
#include "suscriptor.h"
#include "suscriptorarchivo.h"
#include "suscriptormanager.h"
#include "fecha.h"
#include "validaciones.h"


using namespace std;



void SuscriptorManager::cargarSuscriptor(){

    Suscriptor s;
    SuscriptorArchivo sArchivo;
    bool valido;
    int id = 0;

    SuscriptorArchivo arch;
    int total = arch.getCantidadRegistros();
    for (int i = 0; i < total; i++){
        Suscriptor aux = arch.leer(i);
        if (aux.getId() > id){
            id = aux.getId();
        }
    }

s.setId(id + 1);



std::string dni, nombre, apellido, telefono, email;
Fecha f;


do {
    cout << "Ingrese DNI: ";
    getline(cin, dni);
    valido = Validaciones::esSoloNumeros(dni);
    if (!valido) cout << "DNI invalido. Solo numeros permitidos." << endl;
} while (!valido);


do {
    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    valido = Validaciones::esSoloLetras(nombre);
    if (!valido) cout << "Nombre invalido. Solo letras permitidas." << endl;
} while (!valido);


do {
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    valido = Validaciones::esSoloLetras(apellido);
    if (!valido) cout << "Apellido invalido. Solo letras permitidas." << endl;
} while (!valido);

do {
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    valido = Validaciones::esSoloNumeros(telefono);
    if (!valido) cout << "Telefono invalido. Solo numeros permitidos." << endl;
} while (!valido);


do {
    cout << "Ingrese email: ";
    getline(cin, email);
    valido = Validaciones::esEmailValido(email);
    if (!valido) cout << "Email invalido. Intente de nuevo." << endl;
} while (!valido);

cout << "Ingrese Fecha de Nacimiento: ";
f.cargar();

s.setDni(std::string(dni));
s.setNombre(std::string(nombre));
s.setApellido(std::string(apellido));
s.setTelefono(telefono);
s.setEmail(std::string(email));
s.setFecha(f);

if (sArchivo.guardar(s))
{
    cout << "Se guardo correctamente!" << endl;
}
else
{
    cout << "Hubo un error inesperado." << endl;
}

}

void SuscriptorManager::mostrarCantidadSuscriptores(){
    SuscriptorArchivo sArchivo;
    int cantidad = sArchivo.getCantidadRegistros();

    cout << "La cantidad total de suscriptores es de: " << cantidad << endl;
}

void SuscriptorManager::listarTodos(){
    SuscriptorArchivo sArchivo;
    Suscriptor s;
    int cantidad = sArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        s = sArchivo.leer(i);

        cout << "ID: " << s.getId() << endl;
        cout << "DNI: " << s.getDni() << endl;
        cout << "Nombre: " << s.getNombre() << endl;
        cout << "Apellido: " << s.getApellido() << endl;
        cout << "Telefono: " << s.getTelefono() << endl;
        cout << "Email: " << s.getEmail() << endl;

        Fecha f = s.getFechaNacimiento();
        cout << "Fecha de Nacimiento: ";
        cout << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
        cout << " " << f.getHora() << ":" << f.getMinuto() << endl;

        cout << "Estado: " << (s.getActivo() ? "ACTIVO" : "INACTIVO") << endl;

        cout << "-----------------------------" << endl;
    }
}

void SuscriptorManager::modificarSuscriptor(){
    Fecha nuevaFecha;
    int id;
    cout << "Ingrese el ID del suscriptor a modificar: " << endl;
    cin >> id;

    SuscriptorArchivo sArchivo;
    int posicion = sArchivo.buscarPosicionPorId(id);

    if (posicion >= 0){
        Suscriptor reg = sArchivo.leer(posicion);

        cout << "Suscriptor actual: " << reg.toCSV() << endl;

        char opcion = '0';
        do {
            system ("pause");
            system("cls");
            cout << "Seleccione el dato a modificar:" << endl;
            cout << "1. DNI" << endl;
            cout << "2. Nombre" << endl;
            cout << "3. Apellido" << endl;
            cout << "4. Telefono" << endl;
            cout << "5. Email" << endl;
            cout << "6. Fecha de nacimiento" << endl;
            cout << "7. Finalizar modificacion" << endl;
            cout << "Opcion: " << endl;
            cin >> opcion;
            cin.ignore();

            switch(opcion){

                case '1': {
                    string dni;
                    do {
                        cout << "Ingrese DNI: ";
                        getline(cin, dni);
                        if (!Validaciones::esDNIValido(dni)) {
                            cout << "DNI invalido. Debe tener solo numeros entre 7 u 8 digitos." << endl;
                        }
                    } while (!Validaciones::esDNIValido(dni));
                    reg.setDni(dni);
                    break;
                }


                case '2': {
                    string nombre;
                    bool valido;
                    do {
                        cout << "Ingrese nuevo nombre: ";
                        getline(cin, nombre);
                        valido = Validaciones::esSoloLetras(nombre);
                        if (!valido) cout << "Nombre invalido. Solo letras permitidas." << endl;
                    } while (!valido);
                    reg.setNombre(nombre);
                    break;
                }
                case '3': {
                    string apellido;
                    bool valido;
                    do {
                        cout << "Ingrese nuevo apellido: ";
                        getline(cin, apellido);
                        valido = Validaciones::esSoloLetras(apellido);
                        if (!valido) cout << "Apellido invalido. Solo letras permitidas." << endl;
                    } while (!valido);
                    reg.setApellido(apellido);
                    break;
                }
                case '4': {
                    string telefono;
                    bool valido;
                    do {
                        cout << "Ingrese nuevo telefono: ";
                        getline(cin, telefono);
                        valido = Validaciones::esSoloNumeros(telefono);
                        if (!valido) cout << "Telefono invalido. Solo numeros disponibles." << endl;
                    } while (!valido);
                    reg.setTelefono(telefono);
                    break;
                }
                case '5': {
                    string email;
                    bool valido;
                    do {
                        cout << "Ingrese nuevo email: ";
                        getline(cin, email);
                        valido = Validaciones::esEmailValido(email);
                        if (!valido) cout << "Email invalido. Solo formatos de email con @ y ." <<endl;
                    } while (!valido);
                    reg.setEmail(email);
                    break;
                }
                case '6': {
                    Fecha f;
                    cout << "Ingrese nueva fecha de nacimiento:\n";
                    f.cargar();
                    reg.setFecha(f);
                    break;
                }
                case '7': {
                    cout << "Finalizando modificacion.\n";
                    break;
                }
                default: {
                    cout << "Opcion invalida, intente de nuevo.\n";
                    break;
                }
            }
        } while(opcion != '7');

        if (sArchivo.guardar(reg, posicion)){
            cout << "Suscriptor modificado correctamente." << endl;

            Suscriptor verificacion = sArchivo.leer(posicion);
            cout << "Verificacion tras guardar: " << verificacion.toCSV() << endl;
        } else {
            cout << "Error al modificar el suscriptor." << endl;
        }

    } else {
        if (posicion == -1) {
            cout << "No existe el suscriptor." << endl;
        }
        else if (posicion == -2) {
            cout << "Error al abrir el archivo." << endl;
        }
    }
}

void SuscriptorManager::eliminarSuscriptor(){
    int id;
    cout << "Ingrese el ID del suscriptor a eliminar: " << endl;
    cin >> id;
    cin.ignore(10000, '\n');

    SuscriptorArchivo sArchivo;
    int posicion = sArchivo.buscarPosicionPorId(id);

    if (posicion >= 0){
        Suscriptor reg = sArchivo.leer(posicion);
        reg.setActivo(false);
        if(sArchivo.guardar(reg,posicion)){
            cout << "Suscriptor dado de baja correctamente." << endl;
        }
        else {
            cout << "Error al dar de baja el suscriptor." << endl;
        }
    }
    else {
        cout << "No existe el suscriptor con ese ID." << endl;
    }
}

bool SuscriptorManager::existeSuscriptor(int id) {
    SuscriptorArchivo archivo;
    return archivo.buscarPorId(id).getId() != -1;
}

bool SuscriptorManager::darDeAltaSuscriptor() {
    int id;
    cout << "Ingrese el ID del suscriptor a dar de alta: ";
    cin >> id;
    cin.ignore(10000, '\n');

    SuscriptorArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Suscriptor s = archivo.leer(i);
        if (s.getId() == id) {
            if (s.getActivo()) {
                cout << "El suscriptor ya está activo." << endl;
                return false;
            }
            s.setActivo(true);
            if(archivo.guardar(s, i)) {
                cout << "Suscriptor dado de alta correctamente." << endl;
                return true;
            } else {
                cout << "Error al guardar el suscriptor." << endl;
                return false;
            }
        }
    }
    cout << "No se encontro suscriptor con ese ID." << endl;
    return false;
}

void SuscriptorManager::buscarSuscriptorPorId() {
    int id;
    cout << "Ingrese el ID del suscriptor a buscar: ";
    cin >> id;
    cin.ignore(10000, '\n');

    SuscriptorArchivo archivo;
    int posicion = archivo.buscarPosicionPorId(id);

    if (posicion >= 0) {
        Suscriptor s = archivo.leer(posicion);

        cout << "ID: " << s.getId() << endl;
        cout << "DNI: " << s.getDni() << endl;
        cout << "Nombre: " << s.getNombre() << endl;
        cout << "Apellido: " << s.getApellido() << endl;
        cout << "Telefono: " << s.getTelefono() << endl;
        cout << "Email: " << s.getEmail() << endl;

        Fecha f = s.getFechaNacimiento();
        cout << "Fecha de Nacimiento: ";
        cout << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
        cout << " " << f.getHora() << ":" << f.getMinuto() << endl;

        cout << "Estado: " << (s.getActivo() ? "ACTIVO" : "INACTIVO") << endl;

    } else {
        cout << "No se encontró suscriptor con ese ID." << endl;
    }
}
