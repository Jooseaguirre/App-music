#include "artistasporcancionmanager.h"
#include <iostream>

using namespace std;

bool ArtistasporcancionManager::agregarRelacion(Artistasporcancion reg) {
    // Aquí podés agregar validaciones antes de guardar, si querés
    return archivo.agregarRegistro(reg);
}

bool ArtistasporcancionManager::bajaLogica(int idCancion, int idArtista) {
    int pos = archivo.buscarRelacion(idCancion, idArtista);
    if (pos == -1) return false;

    Artistasporcancion obj = archivo.leerRegistro(pos);
    obj.setEstado(false);
    return archivo.modificarRegistro(obj, pos);
}

bool ArtistasporcancionManager::altaLogica(int idCancion, int idArtista) {
    int pos = archivo.buscarRelacion(idCancion, idArtista);
    if (pos == -1) return false;

    Artistasporcancion obj = archivo.leerRegistro(pos);
    obj.setEstado(true);
    return archivo.modificarRegistro(obj, pos);
}

int ArtistasporcancionManager::buscarRelacion(int idCancion, int idArtista) {
    return archivo.buscarRelacion(idCancion, idArtista);
}

Artistasporcancion ArtistasporcancionManager::leerRegistro(int pos) {
    return archivo.leerRegistro(pos);
}

bool ArtistasporcancionManager::modificarRegistro(Artistasporcancion reg, int pos) {
    return archivo.modificarRegistro(reg, pos);
}

int ArtistasporcancionManager::getCantidadRegistros() {
    return archivo.contarRegistros();
}

bool ArtistasporcancionManager::listarRegistros() {
    return archivo.listarRegistros();
}
