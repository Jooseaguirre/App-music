#include "AccesoManager.h"
#include "cancionarchivo.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct RegistroAcceso {
    char usuario[30];
    char contrasena[30];
    int idCancion;
};

AccesoManager::AccesoManager() {
    _nombreArchivo = "accesos.dat";
}

AccesoManager::AccesoManager(const std::string& nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

void AccesoManager::cargarAcceso() {
    RegistroAcceso reg;

    cout << "Ingrese usuario: ";
    cin.ignore();
    cin.getline(reg.usuario, 30);

    cout << "Ingrese contrasena: ";
    cin.getline(reg.contrasena, 30);

    CancionManager cManager;
    cManager.listarTodas();

    cout << "Ingrese el ID de la cancion reproducida: ";
    cin >> reg.idCancion;
    cin.ignore();

    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        cout << "Error al abrir archivo." << endl;
        return;
    }

    if (fwrite(&reg, sizeof(RegistroAcceso), 1, pFile) == 1) {
        cout << "Acceso registrado correctamente." << endl;
    } else {
        cout << "Error al guardar el acceso." << endl;
    }

    fclose(pFile);
}

void AccesoManager::mostrarAccesos() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        cout << "No se encontraron accesos registrados." << endl;
        return;
    }

    CancionArchivo cArchivo;
    RegistroAcceso reg;
    cout << "----- Lista de accesos -----" << endl;
    while (fread(&reg, sizeof(RegistroAcceso), 1, pFile) == 1) {
        cout << "Usuario: " << reg.usuario << endl;
        cout << "Contrasena: " << reg.contrasena << endl;

        Cancion cancion = cArchivo.buscarPorId(reg.idCancion);
        if (cancion.getIdCancion() != -1) {
            cout << "Cancion reproducida: " << cancion.getNombre() << endl;
        } else {
            cout << "Cancion reproducida ID " << reg.idCancion << " no encontrada." << endl;
        }

        cout << "---------------------------" << endl;
    }

    fclose(pFile);
}
