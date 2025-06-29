#include <iostream>
#include <cstdio>
#include "suscriptor.h"
#include "backup.h"

using namespace std;

bool hacerBackupSuscriptores() {
    FILE* origen = fopen("suscriptores.dat", "rb");
    if (origen == nullptr) {
        cout << " No se pudo abrir el archivo original de suscriptores." << endl;
        return false;
    }

    FILE* destino = fopen("suscriptores.bkp", "wb");
    if (destino == nullptr) {
        fclose(origen);
        cout << " No se pudo crear el archivo de backup." << endl;
        return false;
    }

    Suscriptor reg;

    while (fread(&reg, sizeof(Suscriptor), 1, origen) == 1) {
        fwrite(&reg, sizeof(Suscriptor), 1, destino);
    }

    fclose(origen);
    fclose(destino);
    cout << " Backup de suscriptores realizado correctamente." << endl;
    return true;
}

bool recuperarBackupSuscriptores() {
    FILE* origen = fopen("suscriptores.bkp", "rb");
    if (origen == nullptr) {
        cout << " No se pudo abrir el archivo de backup de suscriptores." << endl;
        return false;
    }

    FILE* destino = fopen("suscriptores.dat", "wb");
    if (destino == nullptr) {
        fclose(origen);
        cout << "No se pudo crear el archivo original de suscriptores." << endl;
        return false;
    }

    Suscriptor reg;

    while (fread(&reg, sizeof(Suscriptor), 1, origen) == 1) {
        fwrite(&reg, sizeof(Suscriptor), 1, destino);
    }

    fclose(origen);
    fclose(destino);
    cout << " Recuperación de suscriptores realizada correctamente." << endl;
    return true;
}
