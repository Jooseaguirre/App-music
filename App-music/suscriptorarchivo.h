#pragma once
#include <string>
#include "suscriptor.h"


class SuscriptorArchivo{
private:
    std::string _nombreArchivo;
public:
    SuscriptorArchivo();
    SuscriptorArchivo (std::string nombreArchivo);

    Suscriptor leer(int pos);
    int getCantidadRegistros();
    bool guardar(Suscriptor reg);
    bool guardar(Suscriptor reg, int pos);
    int buscar(const std::string& dniBuscado);
    int buscarPosicionPorId(int id);
    Suscriptor buscarPorId(int id);
    };
