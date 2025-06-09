#include "artistasporcancion.h"
#include <iostream>
using namespace std;

ArtistasPorCancion::ArtistasPorCancion() {
    _idCancion = 0;
    _idArtista = 0;
    _activo = true;
}

ArtistasPorCancion::ArtistasPorCancion(int idCancion, int idArtista, bool activo) {
    _idCancion = idCancion;
    _idArtista = idArtista;
    _activo = activo;
}

void ArtistasPorCancion::setIdCancion(int id) { _idCancion = id; }
void ArtistasPorCancion::setIdArtista(int id) { _idArtista = id; }
void ArtistasPorCancion::setActivo(bool activo) { _activo = activo; }

int ArtistasPorCancion::getIdCancion() const { return _idCancion; }
int ArtistasPorCancion::getIdArtista() const { return _idArtista; }
bool ArtistasPorCancion::getActivo() const { return _activo; }

void ArtistasPorCancion::cargar() {
    cout << "ID de canción: ";
    cin >> _idCancion;
    cout << "ID de artista: ";
    cin >> _idArtista;
    _activo = true;
}

void ArtistasPorCancion::mostrar() const {
    cout << "ID Canción: " << _idCancion
         << " - ID Artista: " << _idArtista;
         if (_activo) {
        cout << " [Activo]";
    } else {
        cout << " [Inactivo]";
    }
    cout << endl;
}
