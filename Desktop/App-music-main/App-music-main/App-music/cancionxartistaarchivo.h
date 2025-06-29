#pragma once
#include "CancionXArtista.h"
#include <string>

class CancionXArtistaArchivo {
private:
    std::string _nombreArchivo;

public:
    CancionXArtistaArchivo();
    CancionXArtistaArchivo(std::string nombreArchivo);

    bool guardar(CancionXArtista reg);
    CancionXArtista leer(int pos);
    int cantidadRegistros();
    bool existeRelacion(int idCancion, int idArtista);
};
