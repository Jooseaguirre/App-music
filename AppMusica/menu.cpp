# include<iostream>
# include<cstdlib>
# include "menu.h"


using namespace std;


void menuPrincipal(){
    int opcion;
    do{
        cout << "\n======= MENU PRINCIPAL =======" << endl;
        cout << "1. Menu Canciones" << endl;
        cout << "2. Menu Suscriptores" << endl;
        cout << "3. Menu Accesos" << endl;
        cout << "4. Mantenimiento" << endl;
        cout << "5. Reportes" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1: menuCanciones();
            break;
            case 2: menuSuscriptores();
            break;
            case 3: menuAccesos();
            break;
            case 4: menuMantenimiento();
            break;
            case 5: menuReportes();
            break;
            case 6: cout << "Saliendo del programa..." << endl;
            return;
            break;
            default: cout << "Opcion invalida. Intente otra vez." << endl;
        }

        }while (opcion != 6);


    }

void menuCanciones(){
    int opcionCancion;
    cancionManager cManager;
    do {
        cout << "****************** MENÚ CANCIONES ******************" << endl;
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
                cManager.listarCanciones();
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

void menuSuscriptores() {
    SuscriptorManager sManager;
    int opcionSuscriptor;

    do{
        cout << "****************** MENÚ SUSCRIPTORES ******************" << endl;
        cout << "1. Agregar Suscriptor" << endl;
        cout << "2. Modificar Suscriptor" << endl;
        cout << "3. Mostrar cantidad de Suscriptores" << endl;
        cout << "4. Listar todos los suscriptores" << endl;
        cout << "5. Salir al menú principal" << endl;
        cout << "Seleccione una opción (1-5): ";
        cin >> opcionSuscriptor;

        switch(opcionSuscriptor){
            case 1:
                sManager.cargarSuscriptor();
                break;
            case 2:
                sManager.modificarSuscriptores();
                break;
            case 3:
                sManager.mostrarCantidadSuscriptores();
                break;
            case 4:
                sManager.listarTodos();
                break;
            case 5:
                 cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opcion invalida, Intente de nuevo." << endl;
        }
        cout << endl << endl;

        } while (opcionSuscriptor != 5);

        }

void menuAcceso() {
    AccesoManager aManager;
    int opcionAcceso;

    do {
        cout << "****************** MENÚ ACCESOS ******************" << endl;
        cout << "1. Registrar Acceso" << endl;
        cout << "2. Mostrar todos los Accesos" << endl;
        cout << "3. Salir al menú principal" << endl;
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

void menuReportes() {
    ReportesManager rManager;
    int opcionReporte;


    do{

        cout << "****************** MENÚ REPORTES ******************" << endl;
        cout << "1. Artista más escuchado" << endl;
        cout << "2. Usuario que más escuchó" << endl;
        cout << "3. Salir al menú principal" << endl;
        cout << "Seleccione una opción (1-2): ";
        cin >> opcionReporte:

        switch(opcionReporte){
            case 1:
                rManager.artistaMasEscuchado();
            case 2:
                rManager.usuarioMasEscuchado();
            case 3:
                cout << "Saliendo del programa..." << endl;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;

            }
            cout << endl << endl;

            } while(opcionReporte != 3)

        }


