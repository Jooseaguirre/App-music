#include "suscriptorarchivo.h"

SuscriptorArchivo::SuscriptorArchivo(){
    _nombreArchivo = "suscriptores.dat";
}

SuscriptorArchivo::SuscriptorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool SuscriptorArchivo::guardar(Suscriptor reg){

FILE* p = fopen(_nombreArchivo.c_str(), "ab");
if (p == nullptr) return false;
bool resultado = fwrite(&reg, sizeof(Suscriptor), 1 , p) == 1;
fclose(p);
return resultado;
}


bool SuscriptorArchivo::guardar(Suscriptor reg, int pos){

FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
if (p == nullptr) return false;
fseek (p, sizeof(Suscriptor) * pos, SEEK_SET);
bool resultado = fwrite(&reg, sizeof(Suscriptor), 1 , p) == 1;
fclose(p);
return resultado;
}


Suscriptor SuscriptorArchivo:: leer (int pos){
    Suscriptor reg;
    FILE* p = fopen (_nombreArchivo.c_str(), "rb");
    if (p == nullptr){
    return reg;
    }

    fseek(p , sizeof(Suscriptor) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Suscriptor), 1, p) != 1){
    reg = Suscriptor();
}
    fclose(p);
    return reg;
}

int SuscriptorArchivo::getCantidadRegistros(){
FILE* p = fopen(_nombreArchivo.c_str(), "rb");
if (p == nullptr){
    return 0;
    }
fseek (p, 0, SEEK_END);
int tam = ftell(p);
fclose(p);
return tam / sizeof(Suscriptor);
}





int SuscriptorArchivo::buscar(const std::string& dniBuscado){
    FILE *pFile;
    Suscriptor reg;
    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr){
        return -2;
    }

    while(fread(&reg, sizeof(Suscriptor), 1, pFile) == 1){
        if (reg.getDni() == dniBuscado){
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}



int SuscriptorArchivo::buscarPosicionPorId(int id) {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Suscriptor reg = leer(i);
        if (reg.getIdSuscriptor() == id) {
            return i;
        }
    }
    return -1;
}


Suscriptor SuscriptorArchivo::buscarPorId(int id) {
    Suscriptor reg;
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        reg = leer(i);
        if (reg.getIdSuscriptor() == id) {
            return reg;
        }
    }

    Suscriptor noEncontrado;
    noEncontrado.setIdSuscriptor(-1);
    return noEncontrado;
}
