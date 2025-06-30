#pragma once
#include <string>

class Validaciones {
public:
    static bool esSoloLetras(const std::string& texto);
    static bool esSoloNumeros(const std::string& texto);
    static bool esEmailValido(const std::string& email);
    static int pedirIdValido(const std::string& mensaje);
    static bool esDNIValido(const std::string& dni);
    static int leerOpcionMenu(const std::string& input, int minimo, int maximo);

    };

