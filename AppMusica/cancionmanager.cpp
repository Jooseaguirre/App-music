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

s.setIdCancion (idMax + 1);



string nombre;
string autor;
Fecha f;

cout << "Ingrese nombre de la cancion: ";
cin.ignore();
getline(cin, nombre);

cout << "Ingrese Autor: ";
getline(cin, autor);

cout << "Ingrese fecha de publicacion: ";
f.cargar();

s.setNombre(nombre);
s.setAutor(autor);
s.setFechaDePublicacion(f);

if (cArchivo.guardar(s)) {
    cout << "Cancion guardada exitosamente.\n";
} else {
    cout << "Error al guardar la cancion.\n";
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


        cout << "Nueva fecha de publicacion:\n";
        fecha.cargar();

        c.setNombre(nombre);
        c.setAutor(autor);
        c.setFechaDePublicacion(fecha);

        if (cArchivo.guardar(c, i)) {
            cout << "Cancion modificada correctamente.";
        } else {
            cout << "Error al modificar la cancion.";
        }
        return;
    }
}

cout << "No se encontr� una cancion con ese ID.";

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
            cout << "Fecha de publicaci�n: "  << endl;
            f.mostrar();
            cout << "-----------------------------\n";
        }
    }
}

void CancionManager::buscarPorId() {
    int id;
    cout << "Ingrese ID de la cancion a buscar: ";
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
            cout << "Fecha de publicacion: " << endl;
            f.mostrar();
            return;
        }
    }

    cout << "Cancion no encontrada.\n";
}

void CancionManager::borrarCancion() {
    int id;
    cout << "Ingrese el ID de la cancion a borrar: ";
    cin >> id;

    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion c = cArchivo.leer(i);
        if (c.getIdCancion() == id) {
            c.setIdCancion(-1);
            if (cArchivo.guardar(c, i)) {
                cout << "Cancion borrada \n";
            } else {
                cout << "Error al borrar la cancion \n";
            }
            return;
        }
    }
    cout << "No se encontro una cancion con ese ID \n";
}
