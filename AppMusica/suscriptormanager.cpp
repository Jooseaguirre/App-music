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
    int id = 0;

    SuscriptorArchivo arch;
    int total = arch.getCantidadRegistros();
    for (i = 0; i < total; i++){
        Suscriptor aux = arch.leer(i);
        if (aux.getIdSuscriptor() > id){
            id = aux.getIdSuscriptor();
        }
    }

s.setIdSuscriptor(id + 1);



char dni[50]
char _apellido[50];
char _telefono[50];
char _email[50];
Fecha f;


cout << "Ingrese DNI: ";
cin.ignore();
cin.getline(cin, dni);

cout << "Ingrese nombre: ";
getline(cin, nombre);

cout << "Ingrese apellido: ";
getline(cin, apellido);

cout << "Ingrese telefono: ";
getline(cin, telefono);

cout << "Ingrese email: ";
getline(cin, email);

cout << "Ingrese Fecha de Nacimiento: ";
f.cargar();

s.setDni(std::string(dni));
s.setNombre(std::string(nombre));
s.setApellido(std::string(apellido));
s.setTelefono(std::string(telefono));
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

    for (int i = 0, i < cantidad ; i++){
        s = sArchivo.leer(i);
        cout << s.toCSV() << endl;
    }
}


void SuscriptorManager::modificarSuscriptor(){
Fecha nuevaFecha;
std:: string dni;
cout << "Ingrese el DNI del suscriptor a modificar: " << endl;
cin >> dni;

SuscriptorArchivo sArchivo;
int posicion = sArchivo.buscar(dni);

if (posicion >= 0){
    Suscriptor reg = sArchivo.leer(posicion);

    string nombre, apellido, telefono, email;
    int dia, mes, anio;


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
            cout << "No existe el suscriptor." << endl;
        }
        else if (posicion == -2) {
            cout << "Error al abrir el archivo." << endl;
        }
    }
}




void SuscriptorManager::eliminarSuscriptor(){
std:: string dni;
cout << "Ingrese el DNI del suscriptor a eliminar: " << endl;
cin >> dni;


SuscriptorArchivo sArchivo;
posicion = sArchivo.buscar(dni);

if (posicion >= 0){
    Suscriptor reg = sArchivo.leer(posicion);

    reg.setActivo(false);
    if(sArchivo.guardar(reg,posicion)){
        cout << "Suscriptor dado de baja correctamente-" <<endl;
    }
    else {
        cout << "Error al dar de baja el suscriptor." << endl;
    }
}

  else
    {
        if (posicion == -1) {
            cout << "No existe el suscriptor." << endl;
        }
        else if (posicion == -2) {
            cout << "Error al abrir el archivo." << endl;
        }
    }
}
