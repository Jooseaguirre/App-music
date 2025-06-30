#include "artista.h"
#include <iostream>
#include <cstring>

using namespace std;

Artista::Artista() {
    _id = 0;
    strcpy(_nombre, "");
    _estado = true;
}

Artista::Artista(int id, string nombre, bool estado) {
    setId(id);
    setNombre(nombre);
    setEstado(estado);
}

int Artista::getId() const {
    return _id;
}

string Artista::getNombre() const {
    return _nombre;
}

bool Artista::getEstado() const {
    return _estado;
}

void Artista::setId(int id) {
    _id = id;
}

void Artista::setNombre(string nombre) {
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre));
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Artista::setEstado(bool estado) {
    _estado = estado;
}

void Artista::cargar() {
    //cout << "ID del artista: ";
    //cin >> _id; //guardo en un atributo pv pq es toy dentro de la clase
    //cin.ignore();
    cout << "Nombre del artista: ";
    cin.getline(_nombre, sizeof(_nombre));
    _estado = true;
}

void Artista::mostrar() const {
    cout << "ID: " << _id << " - Nombre: " << _nombre;
    if (_estado) {
        cout << " [Activo]";
    } else {
        cout << " [Inactivo]";
    }
    cout << endl;
}

string Artista::toCSV() const {
    return to_string(_id) + "," + string(_nombre) + "," + to_string(_estado);
}
