#include "sesion.h"
#include "suscriptormanager.h"
#include "suscriptorarchivo.h"
#include "cancionarchivo.h"
#include "accesomanager.h"

int Sesion::_idSuscriptorActual = -1;

void Sesion::iniciarSesion(int idSuscriptor) {
    _idSuscriptorActual = idSuscriptor;
}

void Sesion::cerrarSesion() {
    _idSuscriptorActual = -1;
}

int Sesion::getIdSuscriptorActual() {
    return _idSuscriptorActual;
}

bool Sesion::estaLogueado() {
    return _idSuscriptorActual != -1;
}


 void Sesion::loginSuscriptor() {
    if (estaLogueado()) {
        cout << "Ya hay una sesi�n iniciada con ID: " << getIdSuscriptorActual() << ". Cierre sesi�n antes de iniciar otra." << endl;
        return;
    }


    SuscriptorArchivo archivo;
    SuscriptorManager manager;

    int id;
    cout << "Ingrese ID de suscriptor para iniciar sesi�n: ";
    cin >> id;
    cin.ignore();

    if (manager.existeSuscriptor(id)) {
        Sesion::iniciarSesion(id);
        cout << "Sesi�n iniciada con ID: " << id << endl;
        return;
    }

    cout << "No existe suscriptor con ese ID. �Desea crearlo? (s/n): ";
    char opc;
    cin >> opc;
    cin.ignore();

    if (opc == 's' || opc == 'S') {
        Suscriptor nuevo;
        nuevo.setIdSuscriptor(id);

        string dni, nombre, apellido, telefono, email;
        Fecha f;

        cout << "Ingrese DNI: ";
        getline(cin, dni);
        cout << "Ingrese nombre: ";
        getline(cin, nombre);
        cout << "Ingrese apellido: ";
        getline(cin, apellido);
        cout << "Ingrese tel�fono: ";
        getline(cin, telefono);
        cout << "Ingrese email: ";
        getline(cin, email);
        cout << "Ingrese fecha de nacimiento: ";
        f.cargar();

        nuevo.setDni(dni);
        nuevo.setNombre(nombre);
        nuevo.setApellido(apellido);
        nuevo.setTelefono(telefono);
        nuevo.setEmail(email);
        nuevo.setFecha(f);
        nuevo.setActivo(true);

        if (archivo.guardar(nuevo)) {
            Sesion::iniciarSesion(id);
            cout << "Suscriptor creado e ingresado con ID: " << id << endl;
        } else {
            cout << "Error al guardar el nuevo suscriptor." << endl;
        }
    }
}


void Sesion::reproduccionCancion() {
    if (!Sesion::estaLogueado()) {
        cout << "Debe iniciar sesi�n primero para reproducir una canci�n." << endl;
        return;
    }

    CancionArchivo archivoCancion;
    int total = archivoCancion.getCantidadRegistros();

    if (total == 0) {
        cout << "No hay canciones disponibles para reproducir." << endl;
        return;
    }

    cout << "Listado de canciones disponibles:" << endl;
    for (int i = 0; i < total; i++) {
        Cancion c = archivoCancion.leer(i);
        cout << c.getIdCancion() << " - " << c.getNombre() << endl;
    }

    int idCancion;
    cout << "Ingrese ID de la canci�n a reproducir: ";
    cin >> idCancion;

    Cancion cancionSeleccionada;
    bool encontrada = false;
    for (int i = 0; i < total; i++) {
        Cancion c = archivoCancion.leer(i);
        if (c.getIdCancion() == idCancion) {
            cancionSeleccionada = c;
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "Canci�n no encontrada." << endl;
        return;
    }

    cout << "Reproduciendo: " << cancionSeleccionada.getNombre() << endl;

    AccesoManager accesoManager;
    accesoManager.cargarAccesoAutomatico(Sesion::getIdSuscriptorActual(), cancionSeleccionada.getIdCancion());
}
