#pragma once
#include <string>
#include "artista.h"

class ArtistaArchivo {
private:
    std::string _nombreArchivo;
public:
    ArtistaArchivo();
    ArtistaArchivo(std::string nombreArchivo);

    bool guardar(Artista reg);
    bool guardar(Artista reg, int pos);

    Artista leer(int pos);

    int getCantidadRegistros();
};
