#include "cancionarchivo.h"


CancionArchivo::CancionArchivo(){
    _nombreArchivo = "canciones.dat";
}

CancionArchivo::CancionArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;

}

bool CancionArchivo::guardar(Cancion reg){
FILE*  p = fopen(_nombreArchivo.c_str(), "ab");
if (p == nullptr) return false;
bool resultado = fwrite(&reg, sizeof(Cancion), 1, p) == 1;
fclose(p);
return resultado;
}

bool CancionArchivo::guardar(Cancion reg, int pos){

   FILE* p;

   p= fopen(_nombreArchivo.c_str(), "rb+");

   if (p == nullptr){
      return false;
   }

   fseek(p, pos * sizeof(Cancion) , SEEK_SET);
   bool resultado = fwrite(&reg, sizeof(Cancion), 1, p) == 1;

   fclose(p);

   return resultado;

}


Cancion CancionArchivo::leer(int pos){
    Cancion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return Cancion();
    fseek(p, sizeof(Cancion) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Cancion), 1, p) != 1){
        reg = Cancion();
    }
    fclose(p);
    return reg;

}



int CancionArchivo::getCantidadRegistros(){
FILE* p = fopen(_nombreArchivo.c_str(), "rb");
if (p == nullptr){
    return 0;
    }
fseek (p, 0, SEEK_END);
int tam = ftell(p);
fclose(p);
return tam / sizeof(Cancion);
}

Cancion CancionArchivo::buscarPorId(int id) {
    Cancion reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) {
        reg.setIdCancion(-1);
        return reg;
    }
    while (fread(&reg, sizeof(Cancion), 1, p) == 1) {
        if (reg.getIdCancion() == id) {
            fclose(p);
            return reg;
        }
    }
    fclose(p);
    reg.setIdCancion(-1);
    return reg;
}

int CancionArchivo::buscarPosicionPorId(int id) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Cancion c = leer(i);
        if (c.getIdCancion() == id) {
            return i;
        }
    }
    return -1;
}
