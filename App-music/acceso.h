#pragma once
#include "fecha.h"

class Acceso{
    private:
        int _idSuscriptor;
        int _idCancion;
        Fecha _fechaAcceso;


    public:
        Acceso();
        Acceso(int idSuscriptor, int idCancion, Fecha fechaAcceso);



        void setIdSuscriptor(int id);
        void setIdCancion(int id);
        void setFechaAcceso(Fecha f);

        int getIdSuscriptor();
        int getIdCancion();
        Fecha getFechaAcceso();
};
