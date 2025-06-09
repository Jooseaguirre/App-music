#include <cstring>
#include "acceso.h"
#include <string>
using namespace std;




Acceso::Acceso(){
    _idSuscriptor = 0;
    _idCancion = 0;

}


Acceso::Acceso(int idSuscriptor, int idCancion, Fecha fechaAcceso){
    setIdSuscriptor(idSuscriptor);
    setIdCancion(idCancion);
    setFechaAcceso(fechaAcceso);
}


int Acceso::getIdSuscriptor() {
    return _idSuscriptor;
}

int Acceso::getIdCancion() {
    return _idCancion;
}

Fecha Acceso::getFechaAcceso() {
    return _fechaAcceso;
}


void Acceso::setIdSuscriptor(int idSuscriptor) {
    _idSuscriptor = idSuscriptor;
}

void Acceso::setIdCancion(int idCancion) {
    _idCancion = idCancion;
}

void Acceso::setFechaAcceso(Fecha fecha) {
    _fechaAcceso = fecha;
}
