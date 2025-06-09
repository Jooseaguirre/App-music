#include "accesoarchivo.h"



AccesoArchivo::AccesoArchivo(){
    _nombreArchivo = "accesos.dat";
}

AccesoArchivo::AccesoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;

}



bool AccesoArchivo::guardar(Acceso reg){
FILE*  p = fopen(_nombreArchivo.c_str(), "ab");
if (p == nullptr) return false;
bool resultado = fwrite(&reg, sizeof(Acceso), 1, p) == 1;
fclose(p);
return resultado;
}

bool AccesoArchivo::guardar(Acceso reg, int pos){

   FILE* p;

   p= fopen(_nombreArchivo.c_str(), "rb+");

   if (p == nullptr){
      return false;
   }

   fseek(p, pos * sizeof(Acceso) , SEEK_SET);
   bool resultado = fwrite(&reg, sizeof(Acceso), 1, p) == 1;

   fclose(p);

   return resultado;

}


Acceso AccesoArchivo::leer(int pos){
    Acceso reg;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return reg;
    fseek(p, sizeof(Acceso) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Acceso), 1, p) != 1){
        reg = Acceso();
    };
    fclose(p);
    return reg;

}



int AccesoArchivo::getCantidadRegistros(){
FILE* p = fopen(_nombreArchivo.c_str(), "rb");
if (p == nullptr){
    return 0;
    }
fseek (p, 0, SEEK_END);
int tam = ftell(p);
fclose(p);
return tam / sizeof(Acceso);
}
