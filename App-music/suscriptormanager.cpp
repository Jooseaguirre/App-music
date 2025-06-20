#include <iostream>
#include <cstring>
#include "suscriptor.h"
#include "suscriptorarchivo.h"
#include "suscriptormanager.h"
#include "fecha.h"


using namespace std;



void SuscriptorManager::cargarSuscriptor(){

    Suscriptor s;
    SuscriptorArchivo sArchivo;
    bool  valido = true;
    int id = 0;

    SuscriptorArchivo arch;
    int total = arch.getCantidadRegistros();
    for (int i = 0; i < total; i++){
        Suscriptor aux = arch.leer(i);
        if (aux.getIdSuscriptor() > id){
            id = aux.getIdSuscriptor();
        }
    }

s.setIdSuscriptor(id + 1);



std::string dni, nombre, apellido, telefono, email;
Fecha f;


cout << "Ingrese DNI: ";
cin >> dni;
cin.ignore();


cout << "Ingrese nombre: ";
getline(cin, nombre);

cout << "Ingrese apellido: ";
getline(cin, apellido);

do {
    cout << "Ingrese telefono (solo numeros): ";
    getline(cin, telefono);


    for (int i = 0; telefono[i] != '\0'; i++) {
        if (telefono[i] < '0' || telefono[i] > '9') {
            valido = false;
            cout << "Telefono invalido, solo numeros permitidos. Intente de nuevo." << endl;
            break;
        }
    }
} while (!valido);

cout << "Ingrese email: ";
getline(cin, email);

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

        cout << "ID: " << s.getIdSuscriptor() << endl;
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
    cout << "Ingrese el ID del suscriptor a modificar: ";
    cin >> id;

    SuscriptorArchivo sArchivo;
    int posicion = sArchivo.buscarPosicionPorId(id);
    if (posicion >= 0){
        Suscriptor reg = sArchivo.leer(posicion);

        string nombre, apellido, telefono, email;

        cout << "Ingrese nuevo nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese nuevo apellido: ";
        getline(cin, apellido);

        cout << "Ingrese nuevo telefono: ";
        getline(cin, telefono);

        cout << "Ingrese nuevo email: ";
        getline(cin, email);

        cout << "Ingrese nueva fecha de nacimiento: ";
        nuevaFecha.cargar();

        reg.setNombre(nombre);
        reg.setApellido(apellido);
        reg.setTelefono(telefono);
        reg.setEmail(email);
        reg.setFecha(nuevaFecha);

        if (sArchivo.guardar(reg, posicion))
        {
            cout << "Suscriptor modificado correctamente." << endl;
        }
        else
        {
            cout << "Error al modificar el suscriptor." << endl;
        }
    }
    else
    {
        if (posicion == -1) {
            cout << "No existe el suscriptor con ese ID." << endl;
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
    return archivo.buscarPorId(id).getIdSuscriptor() != -1;
}





bool SuscriptorManager::darDeAltaSuscriptor() {
    int id;
    cout << "Ingrese el ID del suscriptor a dar de alta: ";
    cin >> id;

    SuscriptorArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Suscriptor s = archivo.leer(i);
        if (s.getIdSuscriptor() == id) {
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
    cout << "No se encontró suscriptor con ese ID." << endl;
    return false;
}



void SuscriptorManager::buscarSuscriptorPorId() {
    int id;
    cout << "Ingrese el ID del suscriptor a buscar: ";
    cin >> id;

    SuscriptorArchivo archivo;
    int posicion = archivo.buscarPosicionPorId(id);

    if (posicion >= 0) {
        Suscriptor s = archivo.leer(posicion);

        cout << "ID: " << s.getIdSuscriptor() << endl;
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



