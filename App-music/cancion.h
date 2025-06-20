#pragma once
#include "fecha.h"



class Cancion{
    private:
        int _idCancion;
        char _nombre [30];
        char _autor[30];
        bool _estado;
        Fecha _fechaDePublicacion;

    public:
        Cancion();
        Cancion(int id, std::string nombre, std::string autor, bool estado, Fecha fecha);



        int getIdCancion();
        std::string getNombre();
        std::string getAutor();
        bool getEstado();


        Fecha getFechaDePublicacion();
        void setEstado(bool estado);
        void setIdCancion(int id);
        void setNombre(std::string nombre);
        void setAutor(std::string autor);
        void setFechaDePublicacion(Fecha fecha);
};
