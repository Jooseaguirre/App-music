#pragma once
#include "acceso.h"
#include <string>


class AccesoArchivo{
private:
    std::string _nombreArchivo;

public:
    AccesoArchivo();
    AccesoArchivo(std::string nombreArchivo);

    bool guardar(Acceso reg);
    bool guardar(Acceso reg, int pos);
    Acceso leer(int pos);
    int getCantidadRegistros();

};
