#include "artistamanager.h"
#include "artistaarchivo.h"
#include "artista.h"
#include <iostream>
#include "validaciones.h"

using namespace std;

void ArtistaManager::cargarArtista() {
    ArtistaArchivo archivo;
    int nuevoId = 1;

    int total = archivo.getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = archivo.leer(i);
        if (a.getId() >= nuevoId) {
            nuevoId = a.getId() + 1;
        }
    }

    Artista art;
    art.setId(nuevoId);

    cin.ignore();

    string nombre;
    bool valido;
    do {
        cout << "Ingrese nombre del artista: ";
        getline(cin, nombre);
        valido = Validaciones::esSoloLetras(nombre);
        if (!valido) {
            cout << "Nombre invalido. Solo se permiten letras y espacios." << endl;
        }
    } while (!valido);

    art.setNombre(nombre);
    art.setEstado(true);

    if (archivo.guardar(art)) {
        cout << "Artista guardado con ID " << nuevoId << "." << endl;
    } else {
        cout << "Error al guardar el artista." << endl;
    }
}

void ArtistaManager::listarArtistas() {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);


        cout << "ID: " << art.getId() << " - Nombre: " << art.getNombre()
             << " [" << (art.getEstado() ? "Activo" : "Inactivo") << "]" << endl;
    }
}

void ArtistaManager::buscarArtistaPorId(int id) {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);
        if (art.getId() == id && art.getEstado()) {
            art.mostrar();
            return;
        }
    }
    cout << "No se encontro el artista con el ID " << id <<  endl;
}

bool ArtistaManager::darDeBajaArtista(int id) {
    ArtistaArchivo archivo;
    int total = archivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Artista art = archivo.leer(i);
        if (art.getId() == id && art.getEstado()) {
            art.setEstado(false);
            return archivo.guardar(art, i);
        }
    }
    return false;
}

std::string ArtistaManager::obtenerNombrePorId(int id) {
    int total = getCantidadRegistros();
    for (int i = 0; i < total; i++) {
        Artista a = leerRegistro(i);
        if (a.getId() == id) return a.getNombre();
    }
    return "Artista desconocido";
}

int ArtistaManager::getCantidadRegistros() {
    FILE* pFile = fopen("artistas.dat", "rb");
    if (pFile == nullptr) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);
    return tam / sizeof(Artista);
}

Artista ArtistaManager::leerRegistro(int pos) {
    Artista obj;
    FILE* pFile = fopen("artistas.dat", "rb");
    if (pFile == nullptr) return obj;

    fseek(pFile, pos * sizeof(Artista), SEEK_SET);
    fread(&obj, sizeof(Artista), 1, pFile);
    fclose(pFile);
    return obj;
}

bool ArtistaManager::darDeAltaArtista(int id) {
    ArtistaArchivo archivo;
    int pos = archivo.buscarPosicionPorId(id);

    if (pos == -1) return false;

    Artista art = archivo.leer(pos);
    if (art.getEstado()) return false;

    art.setEstado(true);
    return archivo.guardar(art, pos);
}

void ArtistaManager::modificarArtista() {
    int id;
    cout << "Ingrese el ID del artista a modificar: ";
    id = Validaciones::pedirIdValido("");

    ArtistaArchivo aArchivo;
    int posicion = aArchivo.buscarPosicionPorId(id);

    if (posicion >= 0) {
        Artista reg = aArchivo.leer(posicion);

        if (!reg.getEstado()) {
            cout << "El artista esta dado de baja. No se puede modificar." << endl;
            return;
        }

        cout << "Artista actual: " << reg.toCSV() << endl;

        char opcion = '0';
        do {
            system("pause");
            system("cls");

            cout << "======= MODIFICAR ARTISTA =======" << endl;
            cout << "1. Modificar nombre" << endl;
            cout << "2. Finalizar modificacion" << endl;
            cout << "Opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case '1': {
                    string nuevoNombre;
                    bool valido;
                    do {
                        cout << "Ingrese nuevo nombre del artista: ";
                        getline(cin, nuevoNombre);
                        valido = Validaciones::esSoloLetras(nuevoNombre);
                        if (!valido) cout << "Nombre invalido. Solo se permiten letras." << endl;
                    } while (!valido);

                    reg.setNombre(nuevoNombre);
                    break;
                }
                case '2':
                    cout << "Finalizando modificacion." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo." << endl;
                    break;
            }

        } while (opcion != '2');

        if (aArchivo.guardar(reg, posicion)) {
            cout << "Artista modificado correctamente." << endl;

            Artista verificacion = aArchivo.leer(posicion);
            cout << "Verificación tras guardar: " << verificacion.toCSV() << endl;
        } else {
            cout << "Error al guardar los cambios del artista." << endl;
        }

    } else {
        if (posicion == -1) {
            cout << "No existe un artista con ese ID." << endl;
        } else if (posicion == -2) {
            cout << "Error al abrir el archivo." << endl;
        }
    }
}
