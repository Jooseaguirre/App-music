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

using namespace std;




void menuPrincipal() {
    int opcion;

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
        cin >> opcion;

        switch(opcion) {
            case 1:
                menuUsuario();
                break;
            case 2:
                menuAdministrador();
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
    int opcion;

    do {
        system("cls");
        cout << "\n======= MENU USUARIO =======" << endl;
        cout << "1. Reproducir Cancion" << endl;
        cout << "2. Menu Reportes" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                Sesion::reproduccionCancion();
                system("pause");
                break;
            case 2:
                /* case 3:
                menuReportes();
                break; */
                break;
            case 3:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
                system("pause");
        }
    } while (opcion != 3);
}

void menuAdministrador() {
    int opcion;

    do {
        system("cls");
        cout << "\n======= MENU ADMINISTRADOR =======" << endl;
        cout << "1. Menu Canciones" << endl;
        cout << "2. Menu Suscriptores" << endl;
        cout << "3. Menu Artistas" << endl;
        cout << "4. Menu Accesos" << endl;
        cout << "5. Mantenimiento" << endl;
        cout << "6. Volver al menú principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
            case 6:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
                system("pause");
        }
    } while (opcion != 6);
}

void menuLogin() {
    SuscriptorManager sManager;
    int opcion;

    do {
        system("cls");
        cout << "\n===== MENU LOGIN =====" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Cerrar sesion" << endl;
        cout << "3. Mostrar ID suscriptor logueado" << endl;
        cout << "4. Volver al menú principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
            case 4:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                system("pause");
        }

    } while (opcion != 4);
}

void menuCanciones(){
    int opcionCancion;
    CancionManager cManager;
    do {
        system("cls");
        cout << "****************** MENU CANCIONES ******************" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Borrar cancion" << endl;
        cout << "3. Listar canciones" << endl;
        cout << "4. Cantidad de canciones" << endl;
        cout << "5. Dar de alta canciones" << endl;
        cout << "6. Buscar cancion por ID" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionCancion;

        switch(opcionCancion){
            case 1:
                cManager.cargarCancion();
                system("pause");
                break;
            case 2:
                cManager.borrarCancion();
                system("pause");
                break;
            case 3:
                cManager.listarTodas();
                system("pause");
                break;
            case 4:
                cManager.mostrarCantidadCanciones();
                system("pause");
                break;
            case 5:
                cManager.darDeAltaCancion();
                system("pause");
                break;
            case 6:
                cManager.buscarPorId();
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
    int opcion;

    do {
        system("cls");
        cout << "\n===== MENU ARTISTAS =====" << endl;
        cout << "1. Agregar artista" << endl;
        cout << "2. Listar artistas" << endl;
        cout << "3. Buscar artista por ID" << endl;
        cout << "4. Dar de baja artista" << endl;
        cout << "5. Dar de alta artista" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        int id;

        switch (opcion) {
            case 1:
                aManager.cargarArtista();
                system("pause");
                break;
            case 2:
                aManager.listarArtistas();
                system("pause");
                break;
            case 3:
                cout << "Ingrese ID del artista: ";
                cin >> id;
                aManager.buscarArtistaPorId(id);
                system("pause");
                break;
            case 4:
                cout << "Ingrese ID a dar de baja: ";
                cin >> id;
                if (aManager.darDeBajaArtista(id)) {
                    cout << "Artista dado de baja." << endl;
                } else {
                    cout << "No se pudo realizar la baja. Intente nuevamente..." << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Ingrese ID a dar de alta: ";
                cin >> id;
                if (aManager.darDeAltaArtista(id)){
                    cout << "Artista dado de alta" << endl;
                } else {
                    cout << "No se pudo realizar la alta." << endl;
                }
                system("pause");
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion inválida, intente nuevamente." << endl;
                system("pause");
        }

        cout << endl;
    } while (opcion != 0);
}

void menuSuscriptores() {
    SuscriptorManager sManager;
    int opcionSuscriptor;

    do {
        system("cls");
        cout << "****************** MENU SUSCRIPTORES ******************" << endl;
        cout << "1. Agregar Suscriptor" << endl;
        cout << "2. Modificar Suscriptor" << endl;
        cout << "3. Eliminar Suscriptor" << endl;
        cout << "4. Dar de alta suscriptor" << endl;
        cout << "5. Listar todos los suscriptores" << endl;
        cout << "6. Buscar suscriptor por ID" << endl;
        cout << "7. Mostrar cantidad de suscriptores" << endl;
        cout << "8. Salir al menu principal" << endl;
        cout << "Seleccione una opcion (1-7): ";
        cin >> opcionSuscriptor;

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
            case 8:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcionSuscriptor != 8);
}

void menuAcceso() {
    AccesoManager aManager;
    int opcionAcceso;

    do {
        system("cls");
        cout << "****************** MENU ACCESOS ******************" << endl;
        cout << "1. Registrar Acceso" << endl;
        cout << "2. Mostrar todos los Accesos" << endl;
        cout << "3. Mostrar accesos por ID" << endl;
        cout << "4. Salir al menu principal" << endl;
        cout << "Seleccione una opcion (1-3): ";
        cin >> opcionAcceso;

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
            case 4:
                cout << "Volviendo al menu principal..." << endl;
                system("pause");
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
                system("pause");
        }
        cout << endl << endl;

    } while (opcionAcceso != 4);
}

void menuMantenimiento() {
    int opcion;
    do {
        system("cls");
        cout << "\n====== MANTENIMIENTO ======" << endl;
        cout << "1. Backup de suscriptores" << endl;
        cout << "2. Restaurar backup de suscriptores" << endl;
        cout << "3. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                hacerBackupSuscriptores();
                system("pause");
                break;
            case 2:
                recuperarBackupSuscriptores();
                system("pause");
                break;
            case 3:
                cout << "Volviendo al menu anterior..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
                break;
        }

    } while(opcion != 3);
}


/*void menuReportes() {
    int opcion;
    do {
        cout << "\n========= MENU DE REPORTES =========" << endl;
        cout << "1. Artista más escuchado" << endl;
        cout << "2. Suscriptor que más escuchó canciones" << endl;
        cout << "3. Cancion más escuchada" << endl;
        cout << "4. Cantidad de accesos por suscriptor" << endl;
        cout << "5. Suscriptores dados de baja" << endl;
        cout << "6. Volver al menu anterior" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: reporteArtistaMasEscuchado(); break;
            case 2: reporteSuscriptorMasActivo(); break;
            case 3: reporteCancionMasEscuchada(); break;
            case 4: reporteCantidadAccesosPorSuscriptor(); break;
            case 5: reporteSuscriptoresDadosDeBaja(); break;
            case 6: cout << "Volviendo..." << endl; break;
            default: cout << "Opción invalida." << endl;
        }
    } while (opcion != 6);
}
*/

