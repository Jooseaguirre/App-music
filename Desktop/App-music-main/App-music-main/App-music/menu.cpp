# include<iostream>
# include<cstdlib>
# include "menu.h"
#include "cancionmanager.h"
#include "suscriptormanager.h"
#include "accesomanager.h"
#include "artistamanager.h"
#include "backup.h"
#include "reportes.h"
#include "sesion.h"
#include "validaciones.h"


using namespace std;




void menuPrincipal() {
    int opcion = -1;
    std::string input;

    do {
        system("cls");

        cout << "\n======= MENU PRINCIPAL =======" << endl;
        if (Sesion::estaLogueado()) {
            cout << "Sesion activa - ID suscriptor: " << Sesion::getIdSuscriptorActual() << endl;
        } else {
            cout << "No hay sesion activa." << endl;
        }
        cout << "------------------------------" << endl;
        cout << "1. Menu Usuario" << endl;
        cout << "2. Menu Administrador" << endl;
        cout << "3. Mostrar ID suscriptor logueado" << endl;
        cout << "4. Cerrar sesion" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 1, 5);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }


        switch(opcion) {
            case 1:
                menuUsuario();
                break;
            case 2:
                if (Sesion::esAdministrador()) {
                    menuAdministrador();
                } else {
                    cout << "Acceso denegado. Solo el administrador puede ingresar a este menu" << endl;
                    system("pause");
                }
                break;
            case 3:
                if (Sesion::estaLogueado()) {
                    cout << "Suscriptor logueado: " << Sesion::getIdSuscriptorActual() << endl;
                } else {
                    cout << "No hay ningun suscriptor logueado." << endl;
                }
                system("pause");
                break;
           case 4:
                Sesion::cerrarSesion();
                cout << "Sesion cerrada." << endl;
                system("pause");
                system ("cls");
                return;
            case 5:
                cout << "Saliendo del programa..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
                system("pause");
        }

    } while (opcion != 5);
}

void menuUsuario() {
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n======= MENU USUARIO =======" << endl;
        cout << "1. Reproducir Cancion" << endl;
        cout << "2. Menu Reportes" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 2);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcion) {
            case 1:
                Sesion::reproduccionCancion();
                system("pause");
                break;
            case 2:
                menuReportes();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
                system("pause");
        }
    } while (opcion != 0);
}

void menuAdministrador() {
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n======= MENU ADMINISTRADOR =======" << endl;
        cout << "1. Menu Canciones" << endl;
        cout << "2. Menu Suscriptores" << endl;
        cout << "3. Menu Artistas" << endl;
        cout << "4. Menu Accesos" << endl;
        cout << "5. Mantenimiento" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 5);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcion) {
            case 1:
                menuCanciones();
                break;
            case 2:
                menuSuscriptores();
                break;
            case 3:
                menuArtistas();
                break;
            case 4:
                menuAcceso();
                break;
            case 5:
                menuMantenimiento();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
                system("pause");
        }
    } while (opcion != 0);
}

void menuLogin() {
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n===== MENU LOGIN =====" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Cerrar sesion" << endl;
        cout << "3. Mostrar ID suscriptor logueado" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 3);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcion) {
            case 1:
                Sesion::loginSuscriptor();
                system("pause");
                break;
            case 2:
                Sesion::cerrarSesion();
                cout << "Sesion cerrada." << endl;
                system("pause");
                break;
            case 3:
                if (Sesion::estaLogueado()) {
                    cout << "Suscriptor logueado: " << Sesion::getIdSuscriptorActual() << endl;
                } else {
                    cout << "No hay ningún suscriptor logueado." << endl;
                }
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                system("pause");
        }

    } while (opcion != 0);
}

void menuCanciones(){
    int opcionCancion = -1;
    std::string input;

    CancionManager cManager;
    do {
        system("cls");
        cout << "****************** MENU CANCIONES ******************" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Modificar cancion por ID" << endl;
        cout << "3. Dar de baja cancion" << endl;
        cout << "4. Dar de alta cancion" << endl;
        cout << "5. Buscar cancion por ID" << endl;
        cout << "6. Listar todas las canciones" << endl;
        cout << "7. Mostrar cantidad de canciones" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcionCancion = Validaciones::leerOpcionMenu(input, 0, 7);

        if (opcionCancion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcionCancion){
            case 1:
                cManager.cargarCancion();
                system("pause");
                break;

            case 2:
                cManager.modificarCancion();
                system("pause");
                break;

            case 3:
                cManager.borrarCancion();
                system("pause");
                break;

            case 4:
                cManager.darDeAltaCancion();
                system("pause");
                break;

            case 5:
                cManager.buscarPorId();
                system("pause");
                break;

            case 6:
                cManager.listarTodas();
                system("pause");
                break;

            case 7:
                cManager.mostrarCantidadCanciones();
                system("pause");
                break;

            case 0:
                cout << "Volviendo al menu anterior..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo" << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcionCancion != 0);
}

void menuArtistas() {
    ArtistaManager aManager;
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n===== MENU ARTISTAS =====" << endl;
        cout << "1. Agregar artista" << endl;
        cout << "2. Modificar artista" << endl;
        cout << "3. Listar artistas" << endl;
        cout << "4. Buscar artista por ID" << endl;
        cout << "5. Dar de baja artista" << endl;
        cout << "6. Dar de alta artista" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 6);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        int id;

        switch (opcion) {
            case 1:
                aManager.cargarArtista();
                system("pause");
                break;
            case 2:
                aManager.modificarArtista();
                system("pause");
                break;
            case 3:
                aManager.listarArtistas();
                system("pause");
                break;
            case 4: {
                int id = Validaciones::pedirIdValido("Ingrese ID del artista: ");
                aManager.buscarArtistaPorId(id);
                system("pause");
                break;
            }
            case 5: {
                int id = Validaciones::pedirIdValido("Ingrese ID a dar de baja: ");
                if (aManager.darDeBajaArtista(id)) {
                    cout << "Artista dado de baja." << endl;
                } else {
                    cout << "No se pudo realizar la baja. Intente nuevamente..." << endl;
                }
                system("pause");
                break;
            }
            case 6: {
                int id = Validaciones::pedirIdValido("Ingrese ID a dar de alta: ");
                if (aManager.darDeAltaArtista(id)) {
                    cout << "Artista dado de alta." << endl;
                } else {
                    cout << "No se pudo realizar la alta." << endl;
                }
                system("pause");
                break;
            }
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                system("pause");
        }


        cout << endl;
    } while (opcion != 0);
}

void menuSuscriptores() {
    SuscriptorManager sManager;
    int opcionSuscriptor = -1;
    std::string input;

    do {
        system("cls");
        cout << "****************** MENU SUSCRIPTORES ******************" << endl;
        cout << "1. Agregar Suscriptor" << endl;
        cout << "2. Modificar Suscriptor" << endl;
        cout << "3. Dar de baja Suscriptor" << endl;
        cout << "4. Dar de alta suscriptor" << endl;
        cout << "5. Listar todos los suscriptores" << endl;
        cout << "6. Buscar suscriptor por ID" << endl;
        cout << "7. Mostrar cantidad de suscriptores" << endl;
        cout << "0. Salir al menu principal" << endl;
        cout << "Seleccione una opcion (1-7): ";

        std::getline(std::cin, input);
        opcionSuscriptor = Validaciones::leerOpcionMenu(input, 0, 7);

        if (opcionSuscriptor == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcionSuscriptor){
            case 1:
                sManager.cargarSuscriptor();
                system("pause");
                break;
            case 2:
                sManager.modificarSuscriptor();
                system("pause");
                break;
            case 3:
                sManager.eliminarSuscriptor();
                system("pause");
                break;
            case 4:
                sManager.darDeAltaSuscriptor();
                system("pause");
                break;
            case 5:
                sManager.listarTodos();
                system("pause");
                break;
             case 6:
                sManager.buscarSuscriptorPorId();
                system("pause");
                break;
            case 7:
                sManager.mostrarCantidadSuscriptores();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcionSuscriptor != 0);
}

void menuAcceso() {
    AccesoManager aManager;
    int opcionAcceso = -1;
    std::string input;

    do {
        system("cls");
        cout << "****************** MENU ACCESOS ******************" << endl;
        cout << "1. Registrar Acceso" << endl;
        cout << "2. Mostrar todos los Accesos" << endl;
        cout << "3. Mostrar accesos por ID" << endl;
        cout << "0. Salir al menu principal" << endl;
        cout << "Seleccione una opcion (1-3): ";

        std::getline(std::cin, input);
        opcionAcceso = Validaciones::leerOpcionMenu(input, 0, 3);

        if (opcionAcceso == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcionAcceso){
            case 1:
                aManager.cargarAcceso();
                system("pause");
                break;
            case 2:
                aManager.mostrarAccesos();
                system("pause");
                break;
            case 3:
                aManager.mostrarAccesosPorIdSuscriptor();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcionAcceso != 0);
}

void menuMantenimiento() {
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n====== MANTENIMIENTO ======" << endl;
        cout << "1. Backup de suscriptores" << endl;
        cout << "2. Restaurar backup de suscriptores" << endl;
        cout << "0. Salir al menu principal" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 2);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcion) {
            case 1:
                hacerBackupSuscriptores();
                system("pause");
                break;
            case 2:
                recuperarBackupSuscriptores();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu anterior..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
                break;
        }

    } while(opcion != 0);
}

void menuReportes() {
    Reportes Reportes;
    int opcion = -1;
    std::string input;

    do {
        system("cls");
        cout << "\n========= MENU DE REPORTES =========" << endl;
        cout << "1. Artista mas escuchado" << endl;
        cout << "2. Suscriptor que mas escucho canciones" << endl;
        cout << "3. Cancion mas escuchada" << endl;
        cout << "4. Cantidad de accesos por suscriptor" << endl;
        cout << "5. Suscriptores dados de baja" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "Seleccione una opcion: ";

        std::getline(std::cin, input);
        opcion = Validaciones::leerOpcionMenu(input, 0, 5);

        if (opcion == -1) {
            cout << "Opcion invalida. Intente otra vez." << endl;
            system("pause");
            continue;
        }

        switch(opcion) {
            case 1:
                Reportes.ArtistaMasEscuchado();
                system("pause");
                break;
            case 2:
                Reportes.SuscriptorMasActivo();
                system("pause");
                break;
            case 3:
                Reportes.CancionMasEscuchada();
                system("pause");
                break;
            case 4:
                Reportes.CantidadAccesosPorSuscriptor();
                system("pause");
                break;
            case 5:
                Reportes.CantidadSuscriptoresDadosDeBaja();
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcion != 0);
}
