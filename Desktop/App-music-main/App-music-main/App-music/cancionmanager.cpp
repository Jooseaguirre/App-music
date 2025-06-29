#include <iostream>
#include <cstring>
#include "cancionManager.h"
#include "cancionarchivo.h"
#include "cancion.h"
#include "cancionxartista.h"
#include "cancionxartistaarchivo.h"
#include "artistaarchivo.h"
#include "validaciones.h"

using namespace std;

void CancionManager::cargarCancion() {
    Cancion s;
    CancionArchivo cArchivo;
    int idMax = 0;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion aux = cArchivo.leer(i);
        if (aux.getIdCancion() > idMax) {
            idMax = aux.getIdCancion();
        }
    }

    s.setIdCancion(idMax + 1);

    string nombre, autor;
    Fecha f;

    //cin.ignore();
    do {
        cout << "Ingrese nombre de la cancion: ";
        getline(cin, nombre);
        if (!Validaciones::esSoloLetras(nombre)) {
            cout << "Error: Solo se permiten letras y espacios." << endl;
    }
} while (!Validaciones::esSoloLetras(nombre));

    do {
        cout << "Ingrese Autor: ";
        getline(cin, autor);
        if (!Validaciones::esSoloLetras(autor)) {
            cout << "Error: Solo se permiten letras y espacios." << endl;
    }
} while (!Validaciones::esSoloLetras(autor));


    cout << "Ingrese fecha de publicacion: ";
    f.cargar();

    s.setNombre(nombre);
    s.setAutor(autor);
    s.setFechaDePublicacion(f);
    s.setEstado(true);

    ArtistaArchivo artistaArchivo;
    CancionXArtistaArchivo archivoRel;

    int idAutor = artistaArchivo.buscarIdPorNombre(autor);
    if (idAutor == -1) {
        cout << "El autor no está registrado como artista. ¿Desea crearlo? (s/n): ";
        char op;
        cin >> op;
        cin.ignore();
        if (op == 's' || op == 'S') {
            idAutor = artistaArchivo.getCantidadRegistros() + 1;
            Artista nuevoArtista;
            nuevoArtista.setId(idAutor);
            nuevoArtista.setNombre(autor);
            nuevoArtista.setEstado(true);
            if (artistaArchivo.guardar(nuevoArtista)) {
                cout << "Autor creado exitosamente como artista con ID " << idAutor << "." << endl;
            } else {
                cout << "Error al crear el artista autor." << endl;
                idAutor = -1;
            }
        }
    }

    if (cArchivo.guardar(s)) {
        cout << "Cancion guardada exitosamente." << endl;

        if (idAutor != -1 && !archivoRel.existeRelacion(s.getIdCancion(), idAutor)) {
            CancionXArtista relAutor;
            relAutor.setIdCancion(s.getIdCancion());
            relAutor.setIdArtista(idAutor);
            relAutor.setEstado(true);
            if (archivoRel.guardar(relAutor)) {
                cout << "Autor asociado correctamente como artista." << endl;
            } else {
                cout << "Error al asociar el autor." << endl;
            }
        }

        char opcion;
        do {
            int idArtista = 0;
            string nombreArt;
            bool idValido = false;

            cout << "Artistas disponibles (ID - Nombre): " << endl;
            int totalArtistas = artistaArchivo.getCantidadRegistros();
            for (int i = 0; i < totalArtistas; i++) {
                Artista a = artistaArchivo.leer(i);
                if (a.getEstado()) {
                    cout << a.getId() << " - " << a.getNombre() << endl;
                }
            }

            do {
               idArtista = Validaciones::pedirIdValido("Ingrese ID del artista que participo (si es el unico artista, vuelva a escribir el mismo ID): ");

                if (artistaArchivo.existePorId(idArtista)) {
                    idValido = true;
                } else {
                    cout << "ID de artista no encontrado o inactivo. ¿Desea crearlo? (s/n): ";
                    char resp;
                    cin >> resp;
                    cin.ignore();
                    if (resp == 's' || resp == 'S') {
                        do {
                            cout << "Ingrese nombre del nuevo artista: ";
                            getline(cin, nombreArt);
                            if (!Validaciones::esSoloLetras(nombreArt)) {
                            cout << "Error: Solo letras y espacios." << endl;
    }
}                       while (!Validaciones::esSoloLetras(nombreArt));
                        int nuevoId = artistaArchivo.getCantidadRegistros() + 1;

                        Artista nuevoArtista;
                        nuevoArtista.setId(nuevoId);
                        nuevoArtista.setNombre(nombreArt);
                        nuevoArtista.setEstado(true);

                        if (artistaArchivo.guardar(nuevoArtista)) {
                            cout << "Artista creado exitosamente con ID " << nuevoId << "." << endl;
                            idValido = true;
                            idArtista = nuevoId;
                        } else {
                            cout << "Error al crear artista." << endl;
                        }
                    }
                }
            } while (!idValido);

            if (!archivoRel.existeRelacion(s.getIdCancion(), idArtista)) {
                CancionXArtista rel;
                rel.setIdCancion(s.getIdCancion());
                rel.setIdArtista(idArtista);
                rel.setEstado(true);

                if (archivoRel.guardar(rel)) {
                    cout << "Artista asociado correctamente." << endl;
                } else {
                    cout << "Error al guardar la asociacion." << endl;
                }
            } else {
                cout << "Este artista ya esta asociado a esta cancion." << endl;
            }

            cout << "¿Agregar otro artista? (s/n): ";
            cin >> opcion;
            cin.ignore();
        } while (opcion == 's' || opcion == 'S');

    } else {
        cout << "Error al guardar la cancion." << endl;
    }
}

void CancionManager::modificarCancion() {
    //cin.ignore();
    int id = Validaciones::pedirIdValido("Ingrese el ID de la cancion a modificar: ");

    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion c = cArchivo.leer(i);
        if (c.getIdCancion() == id) {
            cout << "Cancion actual:\n";
            cout << c.toCSV() << endl;

            char opcion = '0';
            do {
                system("pause");
                system("cls");
                cout << "Seleccione el dato a modificar:\n";
                cout << "1. Nombre de la cancion\n";
                cout << "2. Autor\n";
                cout << "3. Fecha de publicacion\n";
                cout << "4. Finalizar modificacion\n";
                cout << "Opcion: ";
                cin >> opcion;
                cin.ignore();

                switch (opcion) {
                    case '1': {
                        string nombre;
                        bool valido;
                        do {
                            cout << "Ingrese nuevo nombre: ";
                            getline(cin, nombre);
                            valido = Validaciones::esSoloLetras(nombre);
                            if (!valido) cout << "Nombre invalido. Solo letras y espacios permitidos.\n";
                        } while (!valido);
                        c.setNombre(nombre);
                        break;
                    }
                    case '2': {
                        string autor;
                        bool valido;
                        do {
                            cout << "Ingrese nuevo autor: ";
                            getline(cin, autor);
                            valido = Validaciones::esSoloLetras(autor);
                            if (!valido) cout << "Autor invalido. Solo letras y espacios permitidos.\n";
                        } while (!valido);
                        c.setAutor(autor);
                        break;
                    }
                    case '3': {
                        Fecha f;
                        cout << "Ingrese nueva fecha de publicacion:\n";
                        f.cargar();
                        c.setFechaDePublicacion(f);
                        break;
                    }
                    case '4': {
                        cout << "Finalizando modificacion.\n";
                        break;
                    }
                    default: {
                        cout << "Opcion invalida, intente de nuevo.\n";
                        break;
                    }
                }
            } while (opcion != '4');

            if (cArchivo.guardar(c, i)) {
                cout << "Cancion modificada correctamente.\n";
                Cancion verificacion = cArchivo.leer(i);
                cout << "Verificacion tras guardar: " << verificacion.toCSV() << endl;
            } else {
                cout << "Error al modificar la cancion.\n";
            }
            return;
        }
    }

    cout << "No se encontro una cancion con ese ID.\n";
}

void CancionManager::mostrarCantidadCanciones() {
    CancionArchivo cArchivo;
    int total = cArchivo.getCantidadRegistros();
    cout << "Cantidad total de canciones registradas: " << total << endl;
}

void CancionManager::listarTodas() {
    CancionArchivo cArchivo;
    CancionXArtistaArchivo relArchivo;
    ArtistaArchivo artistaArchivo;

    int total = cArchivo.getCantidadRegistros();

    for (int i = 0; i < total; i++) {
        Cancion c = cArchivo.leer(i);

        cout << "ID: " << c.getIdCancion() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
        cout << "Autor: " << c.getAutor() << endl;
        cout << "Estado: " << (c.getEstado() ? "Activa" : "Dada de baja") << endl;

        Fecha f = c.getFechaDePublicacion();
        cout << "Fecha de publicacion: ";
        f.mostrar();

        cout << "Artistas que participaron:" << endl;
        int totalRel = relArchivo.cantidadRegistros();
        bool tieneArtistas = false;

        for (int j = 0; j < totalRel; j++) {
            CancionXArtista rel = relArchivo.leer(j);
            if (rel.getIdCancion() == c.getIdCancion() && rel.getEstado()) {
                Artista artista = artistaArchivo.leerPorId(rel.getIdArtista());
                if (artista.getEstado()) {
                    cout << "  - ID: " << artista.getId() << endl;
                    cout << "    Nombre: " << artista.getNombre() << endl;
                    tieneArtistas = true;
                }
            }
        }

        if (!tieneArtistas) {
            cout << "  (Ninguno)" << endl;
        }

        cout << "-----------------------------\n";
    }
}

void CancionManager::borrarCancion() {
    //cin.ignore();
    int id = Validaciones::pedirIdValido("ID de la cancion a dar de baja: ");

    CancionArchivo archivo;
    int pos = archivo.buscarPosicionPorId(id);

    if (pos == -1) {
        cout << "No se encontro la cancion con ese ID." << endl;
        return;
    }

    Cancion c = archivo.leer(pos);

    if (!c.getEstado()) {
        cout << "La cancion ya esta dada de baja." << endl;
        return;
    }

    c.setEstado(false);
    if (archivo.guardar(c, pos)) {
        cout << "Cancion dada de baja." << endl;
    } else {
        cout << "Error al modificar la cancion." << endl;
    }
}

void CancionManager::darDeAltaCancion() {
    //cin.ignore();
    int id = Validaciones::pedirIdValido("ID de la cancion a recuperar: ");

    CancionArchivo archivo;
    int pos = archivo.buscarPosicionPorId(id);

    if (pos == -1) {
        cout << "No se encontro la cancion con ese ID." << endl;
        return;
    }

    Cancion c = archivo.leer(pos);
    if (c.getEstado()) {
        cout << "La cancion ya esta activa." << endl;
        return;
    }

    c.setEstado(true);
    if (archivo.guardar(c, pos)) {
        cout << "Cancion recuperada." << endl;
    } else {
        cout << "Error al recuperar la cancion." << endl;
    }
}

void CancionManager::buscarPorId() {
    int id = Validaciones::pedirIdValido("Ingrese ID de la cancion a buscar: ");

    CancionArchivo cArchivo;
    CancionXArtistaArchivo relArchivo;
    ArtistaArchivo artistaArchivo;

    int pos = cArchivo.buscarPosicionPorId(id);
    if (pos == -1) {
        cout << "Cancion no encontrada." << endl;
        return;
    }

    Cancion c = cArchivo.leer(pos);

    cout << "ID: " << c.getIdCancion() << endl;
    cout << "Nombre: " << c.getNombre() << endl;
    cout << "Autor: " << c.getAutor() << endl;
    cout << "Estado: " << (c.getEstado() ? "Activa" : "Dada de baja") << endl;

    Fecha f = c.getFechaDePublicacion();
    cout << "Fecha de publicacion: ";
    f.mostrar();

    cout << "Artistas que participaron:" << endl;
    int totalRel = relArchivo.cantidadRegistros();
    bool tieneArtistas = false;

    for (int i = 0; i < totalRel; i++) {
        CancionXArtista rel = relArchivo.leer(i);
        if (rel.getIdCancion() == c.getIdCancion() && rel.getEstado()) {
            Artista artista = artistaArchivo.leerPorId(rel.getIdArtista());
            if (artista.getEstado()) {
                cout << "  - ID: " << artista.getId() << endl;
                cout << "    Nombre: " << artista.getNombre() << endl;
                tieneArtistas = true;
            }
        }
    }

    if (!tieneArtistas) {
        cout << "  (Ninguno)" << endl;
    }

    cout << "-----------------------------\n";
}
