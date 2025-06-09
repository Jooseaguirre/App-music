# include<iostream>
# include<cstdlib>
# include "menu.h"
#include "cancionmanager.h"
#include "suscriptormanager.h"
#include "accesomanager.h"
#include "reportesmanager.h"
#include "artistamanager.h"
#include "artistasporcancionmanager.h"

using namespace std;


void menuPrincipal(){
    int opcion;
    do{
        cout << "\n======= MENU PRINCIPAL =======" << endl;
        cout << "1. Menu Canciones" << endl;
        cout << "2. Menu Artistas" << endl;
        cout << "3. Menu Suscriptores" << endl;
        cout << "4. Menu Accesos" << endl;
        cout << "5. Mantenimiento" << endl;
        cout << "6. Reportes" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1: menuCanciones();
            break;
            case 2: menuArtistas();
            break;
            case 3: menuSuscriptores();
            break;
            case 4: menuAcceso();
            break;
            /*case 5: menuMantenimiento();
            break;*/
            case 6: menuReportes();
            break;
            case 7: cout << "Saliendo del programa..." << endl;
            return;
            break;
            default: cout << "Opcion invalida. Intente otra vez." << endl;
        }

        }while (opcion != 7);


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

/* void menuMantenimiento() {
    BackupManager bkManager;
    int opcionMantenimiento;

    do{

        cout << "****************** MENÚ MANTENIMIENTO ******************" << endl;
        cout << "1. Realizar Backup" << endl;
        cout << "2. Recuperar desde Backup" << endl;
        cout << "3. Salir al menú principal" << endl;
        cout << "Seleccione una opción (1-2): ";
        cin >> opcionMantenimiento;

        switch(opcionMantenimiento){
            case 1:
                bkManager.realizarBackup();
                break;
            case 2:
                bkManager.recuperDatos();
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
            }
            cout << endl << endl;

            } while (opcionMantenimiento != 2);

            }
*/


void menuReportes() {
    ReportesManager rManager;
    int opcionReporte;


    do{

        cout << "****************** MENU REPORTES ******************" << endl;
        cout << "1. Artista mas escuchado" << endl;
        cout << "2. Usuario que mas horas escucho" << endl;
        cout << "0. Salir al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionReporte;

        switch(opcionReporte){
            case 1:
                rManager.artistaMasEscuchado();
                break;
            case 2:
                rManager.usuarioMasEscuchado();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                return;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;

            }
            cout << endl << endl;

            } while(opcionReporte != 0);

        }

/*void menuArtistasPorCancion() {
    ArtistasporcancionManager manager;
    int opcion;

    do {
        cout << "***** MENU ARTISTAS POR CANCION *****" << endl;
        cout << "1. Agregar relacion" << endl;
        cout << "2. Listar relaciones" << endl;
        cout << "3. Guardar en archivo" << endl;
        cout << "4. Cargar desde archivo" << endl;
        cout << "0. Volver" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                manager.agregarRelacion();
                break;
            case 2:
                manager.listarRegistros();
                break;
            case 3:
                manager.guardarEnArchivo("artistasporcancion.dat");
                break;
            case 4:
                manager.cargarDesdeArchivo("artistasporcancion.dat");
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}
*/
