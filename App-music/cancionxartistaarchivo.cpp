#include "cancionxartista.h"
#include "cancionxartistaarchivo.h"
#include <cstdio>

CancionXArtistaArchivo::CancionXArtistaArchivo() {
    _nombreArchivo = "cancionxartista.dat";
}

CancionXArtistaArchivo::CancionXArtistaArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool CancionXArtistaArchivo::guardar(CancionXArtista reg) {
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(CancionXArtista), 1, p);
    fclose(p);
    return ok;
}

CancionXArtista CancionXArtistaArchivo::leer(int pos) {
    CancionXArtista reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;
    fseek(p, sizeof(CancionXArtista) * pos, SEEK_SET);
    fread(&reg, sizeof(CancionXArtista), 1, p);
    fclose(p);
    return reg;
}

int CancionXArtistaArchivo::cantidadRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(CancionXArtista);
}
