#include <iostream>
#include <cstring>
#include "CancionManager.h"
#include "cancionarchivo.h"
#include "cancion.h"

using namespace std;


void CancionManager::cargarCancion(){

    Cancion s;
    CancionArchivo cArchivo;
    int idMax = 0;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++){
        Cancion aux = cArchivo.leer(i);
        if (aux.getIdCancion() > idMax){
            idMax = aux.getIdCancion();
        }
    }

c.setIdCancion (idMax + 1);



char nombre[50]
char autor[50];
Fecha f;

cout << "Ingrese nombre de la cancion: ";
cin.ignore();
getline(cin, nombre);

cout << "Ingrese Autor: ";
getline(cin, autor);

cout << "Ingrese fecha de publicacion: ";
f.cargar();

c.setNombre(nombre);
c.setAutor(autor);
c.setFechaDePublicacion(f);

if (arch.guardar(c)) {
    cout << "Canci�n guardada exitosamente.\n";
} else {
    cout << "Error al guardar la canci�n.\n";
    }
}



void CancionManager::modificarCancion(){
int id;
cout << "Ingrese el ID de la cancion a modificar: ";
cin >> id;

CancionArchivo cArchivo;

int total = cArchivo.getCantidadRegistros();
for (int i = 0; i < total; i++) {
    Cancion c = cArchivo.leer(i);
    if (c.getIdCancion() == id) {
        string nombre, autor, interprete;
        Fecha fecha;

        cout << "Nuevo nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Nuevo autor: ";
        getline(cin, autor);


        cout << "Nueva fecha de publicaci�n:\n";
        fecha.Cargar();

        c.setNombre(nombre);
        c.setAutor(autor);
        c.setFechaDePublicacion(fecha);

        if (cArchivo.guardar(c, i)) {
            cout << "Canci�n modificada correctamente.";
        } else {
            cout << "Error al modificar la canci�n.";
        }
        return;
    }
}

cout << "No se encontr� una canci�n con ese ID.";

}



void CancionManager::mostrarCantidadCanciones() {
    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();
    cout << "Cantidad total de canciones registradas: " << total << endl;
}

void CancionManager::listarTodas() {
    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion c = cArchivo.leer(i);
        if (c.getIdCancion() != -1) {
            cout << "ID: " << c.getIdCancion() << endl;
            cout << "Nombre: " << c.getNombre() << endl;
            cout << "Autor: " << c.getAutor() << endl;
            Fecha f = c.getFechaDePublicacion();
            cout << "Fecha de publicaci�n: " << f.toString() << endl;
            cout << "-----------------------------\n";
        }
    }
}

void CancionManager::buscarPorId() {
    int id;
    cout << "Ingrese ID de la canci�n a buscar: ";
    cin >> id;

    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion c = cArchivo.leer(i);
        if (c.getIdCancion() == id) {
            cout << "ID: " << c.getIdCancion() << endl;
            cout << "Nombre: " << c.getNombre() << endl;
            cout << "Autor: " << c.getAutor() << endl;
            Fecha f = c.getFechaDePublicacion();
            cout << "Fecha de publicaci�n: " << f.toString() << endl;
            return;
        }
    }

    cout << "Canci�n no encontrada.\n";
}
