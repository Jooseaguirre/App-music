#include "fecha.h"

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 2000;
    hora = 0;
    minuto = 0;
}

Fecha::Fecha(int d, int m, int a, int h, int mini) {
    dia = d;
    mes = m;
    anio = a;
    hora = h;
    minuto = mini;
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio << " - "
    << (hora < 10 ? "0" : "" ) << hora << " : "
    << (minuto < 10 ? "0" : "") << minuto << endl;
}
