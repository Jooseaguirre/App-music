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
        cout << "\n======= MENU PRINCIPAL =======" << endl;
        cout << "1. Menu Usuario" << endl;
        cout << "2. Menu Administrador" << endl;
        cout << "3. Salir" << endl;
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
                cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
        }
    } while (opcion != 3);
}

void menuUsuario() {
    int opcion;

    do {
        cout << "\n======= MENU USUARIO =======" << endl;
        cout << "1. Menu Login" << endl;
        cout << "2. Reproducir Cancion" << endl;
        cout << "3. Menu Reportes" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                menuLogin();
                break;
           case 2:
                Sesion::reproduccionCancion();
                break;
          /*  case 3:
                menuReportes();
                break;*/
            case 4:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
        }
    } while (opcion != 4);
}

void menuAdministrador() {
    int opcion;

    do {
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
                return;
            default:
                cout << "Opcion invalida. Intente otra vez." << endl;
        }
    } while (opcion != 6);
}


    void menuLogin() {
    SuscriptorManager sManager;
    int opcion;

    do {
        cout << "\n===== MENU LOGIN =====" << endl;
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Cerrar sesion" << endl;
        cout << "3. Mostrar ID suscriptor logueado" << endl;
        cout << "4. Volver al menú principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                Sesion::loginSuscriptor();
                break;

            }
            case 2:
                Sesion::cerrarSesion();
                cout << "Sesion cerrada." << endl;
                break;
            case 3:
                if (Sesion::estaLogueado()) {
                    cout << "Suscriptor logueado: " << Sesion::getIdSuscriptorActual() << endl;
                } else {
                    cout << "No hay ningún suscriptor logueado." << endl;
                }
                break;
            case 4:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
        }

    } while (opcion != 4);
}











void menuCanciones(){
    int opcionCancion;
    CancionManager cManager;
    do {
        cout << "****************** MENU CANCIONES ******************" << endl;
        cout << "1. Agregar cancion" << endl;
        cout << "2. Borrar cancion" << endl;
        cout << "3. Listar canciones" << endl;
        cout << "4. Cantidad de canciones" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionCancion;

        switch(opcionCancion){
            case 1:
                cManager.cargarCancion();
                break;
            case 2:
                cManager.borrarCancion();
                break;
            case 3:
                cManager.listarTodas();
                break;
            case 4:
                cManager.mostrarCantidadCanciones();
                break;
            case 0:
                 cout << "Saliendo del programa..." << endl;
                return;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo" << endl;

        }
        cout << endl << endl;

} while (opcionCancion !=0);

}

void menuArtistas() {
    ArtistaManager aManager;
    int opcion;

    do {
        cout << "\n===== MENU ARTISTAS =====" << endl;
        cout << "1. Agregar artista" << endl;
        cout << "2. Listar artistas" << endl;
        cout << "3. Buscar artista por ID" << endl;
        cout << "4. Dar de baja artista" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        int id;

        switch (opcion) {
            case 1:
                aManager.cargarArtista();
                system ("pause");
                break;
            case 2:
                aManager.listarArtistas();
                system ("pause");
                break;
            case 3:
                cout << "Ingrese ID del artista: ";
                cin >> id;
                aManager.buscarArtistaPorId(id);
                break;
            case 4:
                cout << "Ingrese ID a dar de baja: ";
                cin >> id;
                if (aManager.darDeBajaArtista(id)) {
                    cout << "Artista dado de baja." << endl;
                    system ("pause");
                } else {
                    cout << "No se pudo realizar la baja. Intente nuevamente..." << endl;
                }
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                return;
            default:
                cout << "Opcion inválida, intente nuevamente." << endl;
        }

        cout << endl;
    } while (opcion != 0);
}

void menuSuscriptores() {
    SuscriptorManager sManager;
    int opcionSuscriptor;

    do{
        cout << "****************** MENU SUSCRIPTORES ******************" << endl;
        cout << "1. Agregar Suscriptor" << endl;
        cout << "2. Modificar Suscriptor" << endl;
        cout << "3. Eliminar Suscriptor" << endl;
        cout << "4. Mostrar cantidad de Suscriptores" << endl;
        cout << "5. Listar todos los suscriptores" << endl;
        cout << "6. Salir al menu principal" << endl;
        cout << "Seleccione una opción (1-6): ";
        cin >> opcionSuscriptor;

        switch(opcionSuscriptor){
            case 1:
                sManager.cargarSuscriptor();
                break;
            case 2:
                sManager.modificarSuscriptor();
                break;
            case 3:
                sManager.eliminarSuscriptor();
                break;
            case 4:
                sManager.mostrarCantidadSuscriptores();
                break;
            case 5:
                sManager.listarTodos();
                break;
            case 6:
                 cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opcion invalida, Intente de nuevo." << endl;
        }
        cout << endl << endl;

        } while (opcionSuscriptor != 6);

        }

void menuAcceso() {
    AccesoManager aManager;
    int opcionAcceso;

    do {
        cout << "****************** MENU ACCESOS ******************" << endl;
        cout << "1. Registrar Acceso" << endl;
        cout << "2. Mostrar todos los Accesos" << endl;
        cout << "3. Salir al menu principal" << endl;
        cout << "Seleccione una opcion (1-3): ";
        cin >> opcionAcceso;

        switch(opcionAcceso){
        case 1:
            aManager.cargarAcceso();
            break;
        case 2:
            aManager.mostrarAccesos();
            break;
        case 3:
            cout << "Saliendo del programa" << endl;
            return;
        default:
            cout << "Opcion invalida, Intente de nuevo." << endl;
            }
        cout << endl << endl;

        } while (opcionAcceso !=3);
}




void menuMantenimiento() {
    int opcion;
    do {
        cout << "\n====== MANTENIMIENTO ======" << endl;
        cout << "1. Backup de suscriptores" << endl;
        cout << "2. Restaurar backup de suscriptores" << endl;
        cout << "3. Volver" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: hacerBackupSuscriptores(); break;
            case 2: recuperarBackupSuscriptores(); break;
            case 3: cout << "Volviendo al menu anterior..."; break;
            default: cout << "Opción invalida."; break;
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

