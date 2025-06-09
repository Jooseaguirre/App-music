#pragma once

class ArtistasPorCancion {
private:
    int _idCancion;
    int _idArtista;
    bool _activo;

public:
    ArtistasPorCancion();
    ArtistasPorCancion(int idCancion, int idArtista, bool activo = true);

    void setIdCancion(int id);
    void setIdArtista(int id);
    void setActivo(bool activo);

    int getIdCancion() const;
    int getIdArtista() const;
    bool getActivo() const;

    void cargar();
    void mostrar() const;
};
