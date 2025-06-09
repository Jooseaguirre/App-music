#pragma once
#include "artistasporcancion.h"
#include <string>

class ArtistasPorCancionArchivo {
private:
    std::string _nombreArchivo;

public:
    ArtistasPorCancionArchivo();
    ArtistasPorCancionArchivo(std::string nombreArchivo);

    bool guardar(ArtistasPorCancion reg);
    bool guardar(ArtistasPorCancion reg, int pos);
    ArtistasPorCancion leer(int pos);
    int getCantidadRegistros();
    ArtistasPorCancion buscarPorIdCancion(int idCancion);
};
