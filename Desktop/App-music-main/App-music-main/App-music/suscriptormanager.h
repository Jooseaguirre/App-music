#include <string>
#pragma once



class SuscriptorManager{
public:
    void cargarSuscriptor();
    void modificarSuscriptor();
    void eliminarSuscriptor();
    void mostrarCantidadSuscriptores();
    void listarTodos();
    bool existeSuscriptor(int id);
    bool darDeAltaSuscriptor();
    void buscarSuscriptorPorId();


};
