#pragma once

#include <string>
#include <iostream>

class CancionXArtista {
private:
    int _idCancion;
    int _idArtista;
    char _nombreArtista[50];
    bool _estado;

public:
    CancionXArtista();


    CancionXArtista(int idCancion, int idArtista, bool estado);


    int getIdCancion();
    int getIdArtista();
    std::string getNombreArtista();
    bool getEstado();

    void setIdCancion(int id);
    void setIdArtista(int id);
    void setEstado(bool estado);
    void setNombreArtista(std::string nombre);
    std::string toCSV();
};
