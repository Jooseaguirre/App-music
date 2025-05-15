#pragma once

#include <string>
#include <iostream>
#include "fecha.h"

class Suscriptor{
private:
    int _idSuscriptor;
    int _dni;
    char _nombre[50];
    char _apellido[50];
    char _telefono[50];
    char _email[50];
    Fecha _fecha_nacimiento;

public:
    Suscriptor();
    Suscriptor(int id, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fecha_nacimiento);

    int getId();
    int getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    Fecha getFechaNacimiento();

    void setId(int id);
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setFecha(Fecha fecha_nacimiento);
};




