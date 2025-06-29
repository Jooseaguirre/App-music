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
    bool existePorId(int id);

    Artista leer(int pos);

    int getCantidadRegistros();
    int buscarIdPorNombre(const std::string& nombre);
     int getMaxId();
    Artista leerPorId(int id);
    int buscarPosicionPorId(int id);
};
