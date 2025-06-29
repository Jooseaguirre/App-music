#include "CancionXArtista.h"
#include <cstring>


CancionXArtista::CancionXArtista() {
    _idCancion = 0;
    _idArtista = 0;
    _estado = true;
}


CancionXArtista::CancionXArtista(int idCancion, int idArtista, bool estado) {
    _idCancion = idCancion;
    _idArtista = idArtista;
    _estado = estado;
}

int CancionXArtista::getIdCancion() { return _idCancion; }
int CancionXArtista::getIdArtista() { return _idArtista; }
bool CancionXArtista::getEstado() { return _estado; }
std::string CancionXArtista::getNombreArtista() {
    return _nombreArtista;
}

void CancionXArtista::setIdCancion(int id) { _idCancion = id; }
void CancionXArtista::setIdArtista(int id) { _idArtista = id; }
void CancionXArtista::setEstado(bool estado) { _estado = estado; }
void CancionXArtista::setNombreArtista(std::string nombre) {
    strcpy(_nombreArtista, nombre.c_str());
}


std::string CancionXArtista::toCSV() {
    return std::to_string(_idCancion) + "," +
           std::to_string(_idArtista) + "," +
           (_estado ? "1" : "0");
}
