#include <cstring>
#include "cancion.h"
#include <string>
using namespace std;



Cancion::Cancion() {
    _idCancion = 0;
    strcpy(_nombre, "");
    strcpy(_autor, "");
    strcpy(_interprete, "");
}


Cancion::Cancion(int id, std::string nombre, std::string autor, std::string interprete, Fecha fechaPublicacion) {
    setIdCancion(id);
    setNombre(nombre);
    setAutor(autor);
    setInterprete(interprete);
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

std::string Cancion::getInterprete() {
    return _interprete;
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

void Cancion::setInterprete(std::string interprete) {
    strcpy(_interprete, interprete.c_str());
}

void Cancion::setFechaDePublicacion(Fecha fecha) {
    _fechaDePublicacion = fecha;
}
