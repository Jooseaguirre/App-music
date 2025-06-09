#pragma once
#include <string>

class Artista {
private:
    int _id;
    char _nombre[50];
    bool _estado;

public:
    Artista();
    Artista(int id, std::string nombre, bool estado);

    int getId() const;
    std::string getNombre() const;
    bool getEstado() const;

    void setId(int id);
    void setNombre(std::string nombre);
    void setEstado(bool estado);

    void cargar();
    void mostrar() const;
    std::string toCSV() const;
};

