#include "fecha.h"

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 2000;
}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio << endl;
}
