#include <cstring>
#include "cancion.h"
#include <string>
using namespace std;



Cancion::Cancion() {
    _idCancion = 0;
    strcpy(_nombre, "");
    strcpy(_autor, "");
    _estado = true;
}


Cancion::Cancion(int id, std::string nombre, std::string autor, bool estado, Fecha fechaPublicacion) {
    setIdCancion(id);
    setNombre(nombre);
    setAutor(autor);
    setEstado(estado);
    setFechaDePublicacion(fechaPublicacion);
}


int Cancion::getIdCancion() {
    return _idCancion;
}

std::string Cancion::getNombre() {
    return _nombre;
}

std::string Cancion::getAutor() {
    return _autor;
}

bool Cancion::getEstado() {
    return _estado;
}


Fecha Cancion::getFechaDePublicacion() {
    return _fechaDePublicacion;
}

void Cancion::setIdCancion(int id) {
    _idCancion = id;
}

void Cancion::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Cancion::setAutor(std::string autor) {
    strcpy(_autor, autor.c_str());
}

void Cancion::setEstado(bool estado) {
    _estado = estado;
}


void Cancion::setFechaDePublicacion(Fecha fecha) {
    _fechaDePublicacion = fecha;
}

std::string Cancion::toCSV() {
    const char* estadoStr = _estado ? "ACTIVA" : "INACTIVA";

    char buffer[300];
    snprintf(buffer, sizeof(buffer), "%d,%s,%s,%02d/%02d/%04d,%s",
             _idCancion, _nombre, _autor,
             _fechaDePublicacion.getDia(), _fechaDePublicacion.getMes(), _fechaDePublicacion.getAnio(),
             estadoStr);

    return std::string(buffer);
}
