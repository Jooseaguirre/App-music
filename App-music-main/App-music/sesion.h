#pragma once

class Sesion {
private:
    static int _idSuscriptorActual;

public:
    static void iniciarSesion(int idSuscriptor);
    static void cerrarSesion();
    static bool loginSuscriptor();
    static int getIdSuscriptorActual();
    static bool estaLogueado();
    static void reproduccionCancion();
    static bool esAdministrador();
};
