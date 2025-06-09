#pragma once

#include <string>
#include <iostream>
#include "fecha.h"

class Suscriptor{
private:
    int _idSuscriptor;
    char _dni[50];
    char _nombre[50];
    char _apellido[50];
    char _telefono[50];
    char _email[50];
    bool _activo;
    Fecha _fechaNacimiento;

public:
    Suscriptor();
    Suscriptor(int id, std::string dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fecha_nacimiento);

    int getId();
    std::string getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    bool getActivo();
    Fecha getFechaNacimiento();
    std::string toCSV();

    void setId(int id);
    void setDni(std::string dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setActivo(bool activo);
    void setFecha(Fecha fecha_nacimiento);

    int getIdSuscriptor() { return _idSuscriptor; }
    void setIdSuscriptor(int id) { _idSuscriptor = id; }
};




