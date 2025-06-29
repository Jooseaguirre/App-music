#include "AccesoManager.h"
#include "Sesion.h"
#include "AccesoArchivo.h"
#include "Fecha.h"
#include "CancionArchivo.h"
#include "SuscriptorArchivo.h"
#include "cancionmanager.h"
#include <iostream>
#include "validaciones.h"
using namespace std;

AccesoManager::AccesoManager() {

}

void AccesoManager::cargarAcceso() {
    int idSuscriptor = Sesion::getIdSuscriptorActual();
    if (idSuscriptor == -1) {
        cout << "No hay un suscriptor logueado." << endl;
        return;
    }

    CancionManager cManager;
    cManager.listarTodas();

    int idCancion = Validaciones::pedirIdValido("Ingrese el ID de la cancion que desea reproducir: ");

    CancionArchivo cArchivo;
    Cancion cancion = cArchivo.buscarPorId(idCancion);

    if (cancion.getIdCancion() == -1 ) {
        cout << "ID de cancion inválido o la cancion está dada de baja." << endl;
        return;
    }

    if (!cancion.getEstado()) {
        cout << "La cancion está dada de baja y no puede reproducirse." << endl;
        return;
    }

    Fecha fechaAcceso = Fecha::obtenerFechaActual();

    Acceso acceso(idSuscriptor, idCancion, fechaAcceso);

    AccesoArchivo aArchivo;
    if (aArchivo.guardar(acceso)) {
        cout << "Acceso registrado correctamente." << endl;
    } else {
        cout << "Error al guardar el acceso." << endl;
    }
}

void AccesoManager::mostrarAccesos() {
    AccesoArchivo archivo;
    int cantidad = archivo.getCantidadRegistros();

    if (cantidad == 0) {
        cout << "No hay accesos registrados." << endl;
        return;
    }

    SuscriptorArchivo sArchivo;
    CancionArchivo cArchivo;

    cout << "----- LISTA DE ACCESOS -----" << endl;
    for (int i = 0; i < cantidad; i++) {
        Acceso acceso = archivo.leer(i);

        Suscriptor s = sArchivo.buscarPorId(acceso.getIdSuscriptor());
        Cancion c = cArchivo.buscarPorId(acceso.getIdCancion());

        cout << "Suscriptor: ";
        if (s.getId() != -1) {
            cout << s.getNombre() << " " << s.getApellido();
        } else {
            cout << "ID " << acceso.getIdSuscriptor() << " (no encontrado)";
        }
        cout << endl;

        cout << "Canción: ";
        if (c.getIdCancion() != -1) {
            cout << c.getNombre();
        } else {
            cout << "ID " << acceso.getIdCancion() << " (no encontrada)";
        }
        cout << endl;

        cout << "Fecha: ";
        acceso.getFechaAcceso().mostrar();

        cout << "-----------------------------" << endl;
    }
}

void AccesoManager::cargarAccesoAutomatico(int idSuscriptor, int idCancion) {
    Fecha fechaAcceso = Fecha::obtenerFechaActual();

    Acceso acceso(idSuscriptor, idCancion, fechaAcceso);

    AccesoArchivo aArchivo;
    if (aArchivo.guardar(acceso)) {
        cout << "Acceso registrado correctamente." << endl;
    } else {
        cout << "Error al guardar el acceso." << endl;
    }
}

void AccesoManager::mostrarAccesosPorIdSuscriptor() {
    int idBuscar = Validaciones::pedirIdValido("Ingrese ID del suscriptor para buscar accesos: ");

    AccesoArchivo archivo;
    int cantidad = archivo.getCantidadRegistros();

    SuscriptorArchivo sArchivo;
    CancionArchivo cArchivo;

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Acceso acceso = archivo.leer(i);
        if (acceso.getIdSuscriptor() == idBuscar) {
            encontrado = true;

            Suscriptor s = sArchivo.buscarPorId(acceso.getIdSuscriptor());
            Cancion c = cArchivo.buscarPorId(acceso.getIdCancion());

            cout << "Suscriptor: ";
            if (s.getId() != -1) {
                cout << s.getNombre() << " " << s.getApellido();
            } else {
                cout << "ID " << acceso.getIdSuscriptor() << " (no encontrado)";
            }
            cout << endl;

            cout << "Canción: ";
            if (c.getIdCancion() != -1) {
                cout << c.getNombre();
            } else {
                cout << "ID " << acceso.getIdCancion() << " (no encontrada)";
            }
            cout << endl;

            cout << "Fecha: ";
            acceso.getFechaAcceso().mostrar();

            cout << "-----------------------------" << endl;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron accesos para el suscriptor con ID " << idBuscar << "." << endl;
    }
}
