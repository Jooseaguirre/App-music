#pragma once
#include <string>

class AccesoManager {
public:
    AccesoManager();

    void cargarAcceso();
    void mostrarAccesos();
    void cargarAccesoAutomatico(int idSuscriptor, int idCancion);
    void mostrarAccesosPorIdSuscriptor();
};
