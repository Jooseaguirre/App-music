#include <iostream>
#include "menu.h"
#include "sesion.h"

using namespace std;

int main() {
    while (true) {
        if (Sesion::loginSuscriptor()) {
            menuPrincipal();
        } else {
            cout << "No se pudo iniciar sesion. Saliendo..." << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
