#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
using namespace std;

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha();
    Fecha(int d, int m, int a);
    void mostrar();
};


#endif // FECHA_H_INCLUDED
