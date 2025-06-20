#include "artistamanager.h"
#include "artistaarchivo.h"
#include "artista.h"
#include <iostream>

using namespace std;

void ArtistaManager::cargarArtista() {
    Artista art;
    art.cargar();

    ArtistaArchivo archivo;
    if (archivo.guardar(art)) {
        cout << "Artista guardado." << endl;
    } else {
        cout << "Error al guardar el artista." << endl;
    }
}

void ArtistaManager::listarArtistas() {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);


        cout << "ID: " << art.getId() << " - Nombre: " << art.getNombre()
             << " [" << (art.getEstado() ? "Activo" : "Inactivo") << "]" << endl;
    }
}
void ArtistaManager::buscarArtistaPorId(int id) {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);
        if (art.getId() == id && art.getEstado()) {
            art.mostrar();
            return;
        }
    }
    cout << "No se encontro el artista con el ID " << id <<  endl;
}

bool ArtistaManager::darDeBajaArtista(int id) {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);
        if (art.getId() == id && art.getEstado()) {
            art.setEstado(false);
            return archivo.guardar(art, i);
        }
    }
    return false;
}

std::string ArtistaManager::obtenerNombrePorId(int id) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = leerRegistro(i);
        if (a.getId() == id) return a.getNombre();
    }
    return "Artista desconocido";
}

int ArtistaManager::getCantidadRegistros() {
    FILE* pFile = fopen("artistas.dat", "rb");
    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);
    return tam / sizeof(Artista);
}

Artista ArtistaManager::leerRegistro(int pos) {
    Artista obj;
    FILE* pFile = fopen("artistas.dat", "rb");
    if (pFile == nullptr) return obj;

    fseek(pFile, pos * sizeof(Artista), SEEK_SET);
    fread(&obj, sizeof(Artista), 1, pFile);
    fclose(pFile);
    return obj;
}


bool ArtistaManager::darDeAltaArtista(int id) {
    ArtistaArchivo archivo;
    int pos = archivo.buscarPosicionPorId(id);

    if (pos == -1) return false;

    Artista art = archivo.leer(pos);
    if (art.getEstado()) return false;

    art.setEstado(true);
    return archivo.guardar(art, pos);
}
