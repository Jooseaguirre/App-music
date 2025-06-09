#include "artistasporcancionarchivo.h"

ArtistasPorCancionArchivo::ArtistasPorCancionArchivo() {
    _nombreArchivo = "artistascancion.dat";
}

ArtistasPorCancionArchivo::ArtistasPorCancionArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArtistasPorCancionArchivo::guardar(ArtistasPorCancion reg) {
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(ArtistasPorCancion), 1, p) == 1;
    fclose(p);
    return resultado;
}

bool ArtistasPorCancionArchivo::guardar(ArtistasPorCancion reg, int pos) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(ArtistasPorCancion), SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(ArtistasPorCancion), 1, p) == 1;
    fclose(p);
    return resultado;
}

ArtistasPorCancion ArtistasPorCancionArchivo::leer(int pos) {
    ArtistasPorCancion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;
    fseek(p, sizeof(ArtistasPorCancion) * pos, SEEK_SET);
    fread(&reg, sizeof(ArtistasPorCancion), 1, p);
    fclose(p);
    return reg;
}

int ArtistasPorCancionArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(ArtistasPorCancion);
}

ArtistasPorCancion ArtistasPorCancionArchivo::buscarPorIdCancion(int idCancion) {
    ArtistasPorCancion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;

    while (fread(&reg, sizeof(ArtistasPorCancion), 1, p) == 1) {
        if (reg.getIdCancion() == idCancion && reg.getActivo()) {
            fclose(p);
            return reg;
        }
    }

    fclose(p);
    reg.setIdCancion(-1);
    return reg;
}
