#pragma once
#include <string>
#include "Cancion.h"
#include "CancionManager.h"


class AccesoManager {
private:
    std::string _nombreArchivo;

public:
    AccesoManager();
    AccesoManager(const std::string& nombreArchivo);

    void cargarAcceso();
    void mostrarAccesos();
};
