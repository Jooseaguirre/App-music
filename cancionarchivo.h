#pragma once
#include "cancion.h"
#include <string>


class CancionArchivo{
private:
    std::string _nombreArchivo;
public:
    CancionArchivo();
    CancionArchivo(std::string nombreArchivo);

    bool guardar (Cancion reg);
    bool guardar (Cancion reg, int pos);
    Cancion leer(int pos);
    int getCantidadRegistros();
    Cancion buscarPorId(int id);

};
