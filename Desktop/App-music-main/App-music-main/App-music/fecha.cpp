#include <iostream>
#include "fecha.h"
#include <ctime>
#include "validaciones.h"

using namespace std;

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 2000;
    hora = 0;
    minuto = 0;
}

Fecha::Fecha(int d, int m, int a, int h, int mini) {
    setDia(d);
    setMes(m);
    setAnio(a);
    setHora(h);
    setMinuto(mini);
}

void Fecha::cargar() {
    string entrada;
    int d, m, a, h, mini;


    do {
        cout << "Ingrese dia (1-31): ";
        getline(cin, entrada);
        if (!Validaciones::esSoloNumeros(entrada)) {
            cout << "Error: solo se permiten números." << endl;
            d = -1;
        } else {
            d = stoi(entrada);
        }
    } while (d < 1 || d > 31);


    do {
        cout << "Ingrese mes (1-12): ";
        getline(cin, entrada);
        if (!Validaciones::esSoloNumeros(entrada)) {
            cout << "Error: solo se permiten números." << endl;
            m = -1;
        } else {
            m = stoi(entrada);
        }
    } while (m < 1 || m > 12);


    do {
        cout << "Ingrese anio (1900-2100): ";
        getline(cin, entrada);
        if (!Validaciones::esSoloNumeros(entrada)) {
            cout << "Error: solo se permiten números." << endl;
            a = -1;
        } else {
            a = stoi(entrada);
        }
    } while (a < 1900 || a > 2100);


    do {
        cout << "Ingrese hora (0-23): ";
        getline(cin, entrada);
        if (!Validaciones::esSoloNumeros(entrada)) {
            cout << "Error: solo se permiten números." << endl;
            h = -1;
        } else {
            h = stoi(entrada);
        }
    } while (h < 0 || h > 23);

    do {
        cout << "Ingrese minuto (0-59): ";
        getline(cin, entrada);
        if (!Validaciones::esSoloNumeros(entrada)) {
            cout << "Error: solo se permiten números." << endl;
            mini = -1;
        } else {
            mini = stoi(entrada);
        }
    } while (mini < 0 || mini > 59);

    setDia(d);
    setMes(m);
    setAnio(a);
    setHora(h);
    setMinuto(mini);
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio << " - "
         << (hora < 10 ? "0" : "") << hora << " : "
         << (minuto < 10 ? "0" : "") << minuto << endl;
}


int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }
int Fecha::getHora() const { return hora; }
int Fecha::getMinuto() const { return minuto; }


void Fecha::setDia(int d) { if (d >= 1 && d <= 31) dia = d; }
void Fecha::setMes(int m) { if (m >= 1 && m <= 12) mes = m; }
void Fecha::setAnio(int a) { if (a >= 1900 && a <= 2100) anio = a; }
void Fecha::setHora(int h) { if (h >= 0 && h <= 23) hora = h; }
void Fecha::setMinuto(int m) { if (m >= 0 && m <= 59) minuto = m; }



Fecha Fecha::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    return Fecha(
        now->tm_mday,
        now->tm_mon + 1,
        now->tm_year + 1900,
        now->tm_hour,
        now->tm_min
    );
}
