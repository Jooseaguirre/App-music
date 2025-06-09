#include <iostream>
#include "fecha.h"

using namespace std;

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


void Fecha::cargar(){

    int d, m, a, h, mini;

    do{
        cout << "Ingrese dia (1-31): ";
        cin >> d;
    } while (d < 1 || d > 31);

    do {
        cout << "Ingrese mes (1-12): ";
        cin >> m;
    } while (m < 1 || m > 12);

    do {
        cout << "Ingrese anio (1900-2100): ";
        cin >> a;
    } while (a < 1900 || a > 2100);

    do {
        cout << "Ingrese hora (0-23): ";
        cin >> h;
    } while (h < 0 || h > 23);

    do {
        cout << "Ingrese minuto (0-59): ";
        cin >> mini;
    } while (mini < 0 || mini > 59);

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
