#include <cstring>
#include "suscriptor.h"
#include <string>
#include "fecha.h"
#include <cstdio>
using namespace std;


Suscriptor::Suscriptor(){
  //  _idSuscriptor = 0;
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
     _activo = true;
}

Suscriptor::Suscriptor(int id, std::string dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNacimiento){
    /*setIdSuscriptor(id);*/
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFecha(fechaNacimiento);
     _activo = true;

}


std::string Suscriptor::getDni(){
    return _dni;
}

std::string Suscriptor::getNombre(){
    return _nombre;
}

std::string Suscriptor::getApellido(){
    return _apellido;
}

std::string Suscriptor::getTelefono(){
    return _telefono;
}

std::string Suscriptor::getEmail(){
    return _email;
}

Fecha Suscriptor::getFechaNacimiento() {
    return _fechaNacimiento;
}

bool Suscriptor::getActivo() {
    return _activo;
}

void Suscriptor::setDni(std::string dni){
    strcpy(_dni, dni.c_str());
}
void Suscriptor::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}
void Suscriptor::setApellido(std::string apellido){
    strcpy(_apellido, apellido.c_str());
}
void Suscriptor::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}
void Suscriptor::setEmail(std::string email){
    strcpy(_email, email.c_str());
}
void Suscriptor::setFecha(Fecha fechaNacimiento){
    _fechaNacimiento = fechaNacimiento;
}

void Suscriptor::setActivo(bool activo) {
    _activo = activo;
}


std::string Suscriptor::toCSV() {
    char buffer[300];
    snprintf(buffer, sizeof(buffer), "%d,%s,%s,%s,%s,%s,%02d/%02d/%04d %02d:%02d",
             _idSuscriptor, _dni, _nombre, _apellido, _telefono, _email,
             _fechaNacimiento.dia, _fechaNacimiento.mes, _fechaNacimiento.anio,
             _fechaNacimiento.hora, _fechaNacimiento.minuto, _activo ? "ACTIVO" : "INACTIVO");
    return std::string(buffer);
}
