#include "sesion.h"
#include "suscriptormanager.h"
#include "suscriptorarchivo.h"
#include "cancionarchivo.h"
#include "accesomanager.h"
#include "validaciones.h"

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


bool Sesion::loginSuscriptor() {
    if (estaLogueado()) {
        cout << "Ya hay una sesion iniciada con ID: " << getIdSuscriptorActual() << ". Cierre sesion antes de iniciar otra." << endl;
        return true;
    }

    SuscriptorArchivo archivo;
    SuscriptorManager manager;
    bool valido;

    int id = Validaciones::pedirIdValido("Ingrese su ID de suscriptor: ");

    if (manager.existeSuscriptor(id)) {
        Sesion::iniciarSesion(id);
        cout << "Sesion iniciada con ID: " << id << endl;
        return true;
    }

    cout << "No existe suscriptor con ese ID. ¿Desea crearlo? (s/n): ";
    char opc;
    cin >> opc;
    cin.ignore();

    if (opc == 's' || opc == 'S') {
        Suscriptor nuevo;
        nuevo.setId(id);

        string dni, nombre, apellido, telefono, email;
        Fecha f;

        cout << "Ingrese DNI: ";
        getline(cin, dni);
        cout << "Ingrese nombre: ";
        getline(cin, nombre);
        cout << "Ingrese apellido: ";
        getline(cin, apellido);

        do {
            valido = true;
            cout << "Ingrese telefono (solo numeros): ";
            getline(cin, telefono);

            for (int i = 0; telefono[i] != '\0'; i++) {
                if (telefono[i] < '0' || telefono[i] > '9') {
                    valido = false;
                    cout << "Telefono invalido, solo numeros permitidos. Intente de nuevo." << endl;
                    break;
                }
            }
        } while (!valido);

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
            return true;
        } else {
            cout << "Error al guardar el nuevo suscriptor." << endl;
            return false;
        }
    }

    return false;
}

void Sesion::reproduccionCancion() {
    if (!Sesion::estaLogueado()) {
        cout << "Debe iniciar sesion primero para reproducir una cancion." << endl;
        system("pause");
        return;
    }

    CancionArchivo archivoCancion;
    int total = archivoCancion.getCantidadRegistros();

    if (total == 0) {
        cout << "No hay canciones disponibles para reproducir." << endl;
        system("pause");
        return;
    }

    bool hayActivas = false;
    for (int i = 0; i < total; i++) {
        if (archivoCancion.leer(i).getEstado()) {
            hayActivas = true;
            break;
        }
    }

    if (!hayActivas) {
        cout << "No hay canciones activas para reproducir." << endl;
        system("pause");
        return;
    }

    string seguir = "s";
    while (seguir == "s" || seguir == "S") {
        system("cls");
        cout << "Listado de canciones disponibles:\n";

        for (int i = 0; i < total; i++) {
            Cancion c = archivoCancion.leer(i);
            if (c.getEstado()) {
                cout << c.getIdCancion() << " - " << c.getNombre() << endl;
            }
        }

        int idCancion;
        cout << "\nIngrese ID de la cancion a reproducir: ";
        while (!(cin >> idCancion)) {
            cout << "ID invalido. Ingrese un numero: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        bool encontrada = false;
        Cancion cancionSeleccionada;

        for (int i = 0; i < total; i++) {
            Cancion c = archivoCancion.leer(i);
            if (c.getIdCancion() == idCancion && c.getEstado()) {
                cancionSeleccionada = c;
                encontrada = true;
                break;
            }
        }

        if (!encontrada) {
            cout << "ID invalido o cancion dada de baja." << endl;
        } else {
            cout << "Reproduciendo: " << cancionSeleccionada.getNombre() << endl;
            AccesoManager accesoManager;
            accesoManager.cargarAccesoAutomatico(Sesion::getIdSuscriptorActual(), cancionSeleccionada.getIdCancion());
        }

        cin.ignore();

        do {
            cout << "\n¿Desea reproducir otra cancion? (S/N): ";
            getline(cin, seguir);
            if (seguir != "s" && seguir != "S" && seguir != "n" && seguir != "N") {
                cout << "Respuesta invalida. Solo S o N." << endl;
            }
        } while (seguir != "s" && seguir != "S" && seguir != "n" && seguir != "N");
    }
}





bool Sesion::esAdministrador() {
    return _idSuscriptorActual == 1;
}
