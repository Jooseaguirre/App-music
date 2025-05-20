#include <cstring>
#include "suscriptor.h"
#include <string>
#include "fecha.h"
using namespace std;


Suscriptor::Suscriptor(){
    _idSuscriptor = 0;
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Suscriptor::Suscriptor(int id, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fecha_nacimiento){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFecha(fecha_nacimiento);

}


int Suscriptor::getId(){
    return _idSuscriptor;
}

int Suscriptor::getDni(){
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
    return _fecha_nacimiento;
}



void Suscriptor::setId(int id){
    _idSuscriptor = id;
}

void Suscriptor::setDni(int dni){
    _dni = dni;
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
void Suscriptor::setFecha(Fecha fecha_nacimiento){
    _fecha_nacimiento = fecha_nacimiento;
}
