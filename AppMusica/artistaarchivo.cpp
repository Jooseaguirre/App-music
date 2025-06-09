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
