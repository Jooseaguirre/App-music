#include "artistaarchivo.h"
#include <cstdio>

ArtistaArchivo::ArtistaArchivo(){
    _nombreArchivo = "artistas.dat";
}

ArtistaArchivo::ArtistaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArtistaArchivo::guardar(Artista reg){
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Artista), 1, p) == 1;
    fclose(p);
    return resultado;
}

bool ArtistaArchivo::guardar(Artista reg, int pos){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Artista), SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Artista), 1, p) == 1;
    fclose(p);
    return resultado;
}

Artista ArtistaArchivo::leer(int pos){
    Artista reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return Artista();
    fseek(p, sizeof(Artista) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Artista), 1, p) != 1){
        reg = Artista();
    }
    fclose(p);
    return reg;
}

int ArtistaArchivo::getCantidadRegistros(){
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Artista);
}

int ArtistaArchivo::buscarIdPorNombre(const std::string& nombre) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = leer(i);
        if (a.getNombre() == nombre && a.getEstado()) {
            return a.getId();
        }
    }
    return -1;
}

bool ArtistaArchivo::existePorId(int id) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = leer(i);
        if (a.getId() == id && a.getEstado()) {
            return true;
        }
    }
    return false;
}

Artista ArtistaArchivo::leerPorId(int id) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = leer(i);
        if (a.getId() == id) {
            return a;
        }
    }
    return Artista();
}

int ArtistaArchivo::getMaxId() {
    int maxId = 0;
    int total = getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista a = leer(i);
        if (a.getId() > maxId) {
            maxId = a.getId();
        }
    }

    return maxId;
}

int ArtistaArchivo::buscarPosicionPorId(int id) {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Artista art = leer(i);
        if (art.getId() == id) {
            return i;
        }
    }
    return -1;
}
