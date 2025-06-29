#pragma once
#include "artista.h"
#include <string>

class ArtistaManager {
public:
    void cargarArtista();
    void listarArtistas();
    void buscarArtistaPorId(int id);
    bool darDeBajaArtista(int id);
    bool darDeAltaArtista(int id);
    void modificarArtista();
    std::string obtenerNombrePorId(int id);
    int getCantidadRegistros();
    Artista leerRegistro(int pos);

};
