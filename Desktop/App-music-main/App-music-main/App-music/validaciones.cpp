#include "validaciones.h"
#include <iostream>
#include <string>



using namespace std;


bool Validaciones::esSoloLetras(const std::string& texto) {
    int longitud = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false;
        }
        longitud++;
    }
    return (longitud > 0);
}

bool Validaciones::esSoloNumeros(const std::string& texto) {
    int longitud = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c < '0' || c > '9') {
            return false;
        }
        longitud++;
    }
    return (longitud > 0);
}


bool Validaciones::esEmailValido(const std::string& email) {
    int longitud = 0;
    int contadorArroba = 0;
    int posicionArroba = -1;


    for (int i = 0; email[i] != '\0'; i++) {
        char c = email[i];
        if (c == '@') {
            contadorArroba++;
            posicionArroba = i;
        }
        longitud++;
    }

    if (longitud == 0) return false;
    if (contadorArroba != 1) return false;
    if (posicionArroba == 0) return false;
    if (posicionArroba == longitud - 1) return false;


    bool hayPuntoDespues = false;
    for (int i = posicionArroba + 1; i < longitud; i++) {
        if (email[i] == '.') {
            hayPuntoDespues = true;

            if (i == posicionArroba + 1) return false;
            if (i == longitud - 1) return false;
            break;
        }
    }
    if (!hayPuntoDespues) return false;

    return true;
}

bool Validaciones::esDNIValido(const std::string& dni) {
    if (!esSoloNumeros(dni)) {
        return false;
    }

    int longitud = dni.length();
    return (longitud == 7 || longitud == 8);
}


int Validaciones::pedirIdValido(const std::string& mensaje) {
    std::string input;
    bool valido = false;

    do {
        std::cout << mensaje;
        if (std::cin.peek() == '\n') std::cin.ignore();

        std::getline(std::cin, input);

        valido = true;
        bool tieneAlgo = false;

        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valido = false;
                break;
            }
            tieneAlgo = true;
        }

        if (!tieneAlgo) {
            std::cout << "Error: No ingreso nada. Intente de nuevo." << std::endl;
            valido = false;
        } else if (!valido) {
            std::cout << "Error: ID invalido. Ingrese solo numeros." << std::endl;
        }

    } while (!valido);

    int resultado = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        resultado = resultado * 10 + (input[i] - '0');
    }

    return resultado;
}

int Validaciones::leerOpcionMenu(const std::string& input, int minimo, int maximo) {
    if (input.empty()) return -1;

    for (char c : input) {
        if (!isdigit(c)) return -1;
    }

    int numero = 0;
    for (char c : input) {
        numero = numero * 10 + (c - '0');
    }

    if (numero < minimo || numero > maximo) return -1;

    return numero;
}
