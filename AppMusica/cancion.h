#pragma once
#include "fecha.h"



class Cancion{
    private:
        int _idCancion;
        char _nombre [30];
        char _autor[30];
        char _interprete[30];
        Fecha _fechaDePublicacion;

    public:
        Cancion();
        Cancion(int id, std::string nombre, std::string autor, std::string interprete, Fecha fecha);



        int getIdCancion();
        std::string getNombre();
        std::string getAutor();
        std::string getInterprete();
        Fecha getFechaDePublicacion();

        void setIdCancion(int id);
        void setNombre(std::string nombre);
        void setAutor(std::string autor);
        void setInterprete(std::string interprete);
        void setFechaDePublicacion(Fecha fecha);
}
