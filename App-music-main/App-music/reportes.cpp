#include "reportes.h"
#include "accesoarchivo.h"
#include "cancionxartistaarchivo.h"
#include "artistaarchivo.h"
#include <iostream>

#include "suscriptorarchivo.h"

#include "cancionarchivo.h"

void Reportes::ArtistaMasEscuchado() {
    AccesoArchivo archivoAcceso;
    CancionXArtistaArchivo archivoRelacion;
    ArtistaArchivo archivoArtista;

    const int MAX_ARTISTAS = 9999;
    int idsArtistas[MAX_ARTISTAS];
    int contador[MAX_ARTISTAS];

    for (int i = 0; i < MAX_ARTISTAS; i++) {
        idsArtistas[i] = -1;
        contador[i] = 0;
    }

    int totalAccesos = archivoAcceso.getCantidadRegistros();

    for (int i = 0; i < totalAccesos; i++) {
        Acceso acc = archivoAcceso.leer(i);
        int idCancion = acc.getIdCancion();
        int totalRel = archivoRelacion.cantidadRegistros();

        for (int j = 0; j < totalRel; j++) {
            CancionXArtista rel = archivoRelacion.leer(j);
            if (rel.getIdCancion() == idCancion) {
                int idArtista = rel.getIdArtista();

                int pos = -1;
                for (int k = 0; k < MAX_ARTISTAS; k++) {
                    if (idsArtistas[k] == idArtista) {
                        pos = k;
                        break;
                    }
                }

                if (pos == -1) {
                    for (int k = 0; k < MAX_ARTISTAS; k++) {
                        if (idsArtistas[k] == -1) {
                            idsArtistas[k] = idArtista;
                            contador[k] = 1;
                            break;
                        }
                    }
                } else {
                    contador[pos]++;
                }
            }
        }
    }

    int maxReproducciones = 0;
    for (int i = 0; i < MAX_ARTISTAS; i++) {
        if (idsArtistas[i] != -1 && contador[i] > maxReproducciones) {
            maxReproducciones = contador[i];
        }
    }

    std::cout << "\nARTISTA(S) MÁS ESCUCHADO(S) ============================\n";
    if (maxReproducciones > 0) {
        for (int i = 0; i < MAX_ARTISTAS; i++) {
            if (idsArtistas[i] != -1 && contador[i] == maxReproducciones) {
                Artista art = archivoArtista.leerPorId(idsArtistas[i]);
                std::cout << art.getNombre() << ": " << maxReproducciones << " reproducciones\n";
            }
        }
    } else {
        std::cout << "No hay registros de reproducciones.\n";
    }
}


void Reportes::SuscriptorMasActivo() {
    AccesoArchivo     archivoAcceso;
    SuscriptorArchivo archivoSuscriptor;

    const int MAX_SUSCRIPTORES = 99999;
    int idsSuscriptores[MAX_SUSCRIPTORES];
    int contador[MAX_SUSCRIPTORES];

    for (int i = 0; i < MAX_SUSCRIPTORES; i++) {
        idsSuscriptores[i] = -1;
        contador[i]        =  0;
    }

    int totalAccesos = archivoAcceso.getCantidadRegistros();

    for (int i = 0; i < totalAccesos; i++) {
        Acceso acc   = archivoAcceso.leer(i);
        int idSub    = acc.getIdSuscriptor();

        int pos = -1;
        for (int k = 0; k < MAX_SUSCRIPTORES; k++) {
            if (idsSuscriptores[k] == idSub) { pos = k; break; }
        }

        if (pos == -1) {
            for (int k = 0; k < MAX_SUSCRIPTORES; k++) {
                if (idsSuscriptores[k] == -1) {
                    idsSuscriptores[k] = idSub;
                    contador[k]        = 1;
                    break;
                }
            }
        } else {
            contador[pos]++;
        }
    }

    int maxAccesos = 0;
    for (int i = 0; i < MAX_SUSCRIPTORES; i++) {
        if (idsSuscriptores[i] != -1 && contador[i] > maxAccesos) {
            maxAccesos = contador[i];
        }
    }

    std::cout << "\nSUSCRIPTOR(ES) MÁS ACTIVO(S) ============================\n";
    if (maxAccesos > 0) {
        for (int i = 0; i < MAX_SUSCRIPTORES; i++) {
            if (idsSuscriptores[i] != -1 && contador[i] == maxAccesos) {
                Suscriptor sub = archivoSuscriptor.buscarPorId(idsSuscriptores[i]);
                std::cout << sub.getNombre()
                          << " (ID " << idsSuscriptores[i] << "): "
                          << maxAccesos << " accesos\n";
            }
        }
    } else {
        std::cout << "No hay accesos registrados.\n";
    }
}


void Reportes::CancionMasEscuchada() {
    AccesoArchivo  archivoAcceso;
    CancionArchivo archivoCancion;

    const int MAX_CANCIONES = 999999;
    int idsCanciones[MAX_CANCIONES];
    int contador[MAX_CANCIONES];

    for (int i = 0; i < MAX_CANCIONES; i++) {
        idsCanciones[i] = -1;
        contador[i]     =  0;
    }

    int totalAccesos = archivoAcceso.getCantidadRegistros();

    for (int i = 0; i < totalAccesos; i++) {
        Acceso acc   = archivoAcceso.leer(i);
        int idSong   = acc.getIdCancion();

        int pos = -1;
        for (int k = 0; k < MAX_CANCIONES; k++) {
            if (idsCanciones[k] == idSong) { pos = k; break; }
        }

        if (pos == -1) {
            for (int k = 0; k < MAX_CANCIONES; k++) {
                if (idsCanciones[k] == -1) {
                    idsCanciones[k] = idSong;
                    contador[k]     = 1;
                    break;
                }
            }
        } else {
            contador[pos]++;
        }
    }

    int maxRepros = 0;
    for (int i = 0; i < MAX_CANCIONES; i++) {
        if (idsCanciones[i] != -1 && contador[i] > maxRepros) {
            maxRepros = contador[i];
        }
    }

    std::cout << "\nCANCIÓN MÁS ESCUCHADA(S) ============================\n";
    if (maxRepros > 0) {
        for (int i = 0; i < MAX_CANCIONES; i++) {
            if (idsCanciones[i] != -1 && contador[i] == maxRepros) {
                Cancion song = archivoCancion.buscarPorId(idsCanciones[i]);
                std::cout << song.getNombre()
                          << " (ID " << idsCanciones[i] << "): "
                          << maxRepros << " reproducciones\n";
            }
        }
    } else {
        std::cout << "No hay reproducciones registradas.\n";
    }
}



void Reportes::CantidadAccesosPorSuscriptor() {
    AccesoArchivo     archivoAcceso;
    SuscriptorArchivo archivoSuscriptor;

    const int MAX_SUSCRIPTORES = 5000;
    int idsSuscriptores[MAX_SUSCRIPTORES];
    int contador[MAX_SUSCRIPTORES];

    for (int i = 0; i < MAX_SUSCRIPTORES; i++) {
        idsSuscriptores[i] = -1;
        contador[i] = 0;
    }

    int totalAccesos = archivoAcceso.getCantidadRegistros();

    for (int i = 0; i < totalAccesos; i++) {
        Acceso acc = archivoAcceso.leer(i);
        int idSub = acc.getIdSuscriptor();

        int pos = -1;
        for (int k = 0; k < MAX_SUSCRIPTORES; k++) {
            if (idsSuscriptores[k] == idSub) {
                pos = k;
                break;
            }
        }

        if (pos == -1) {
            for (int k = 0; k < MAX_SUSCRIPTORES; k++) {
                if (idsSuscriptores[k] == -1) {
                    idsSuscriptores[k] = idSub;
                    contador[k] = 1;
                    break;
                }
            }
        } else {
            contador[pos]++;
        }
    }

    std::cout << "\nCANTIDAD DE ACCESOS POR SUSCRIPTOR ============================\n";

    for (int i = 0; i < MAX_SUSCRIPTORES; i++) {
        if (idsSuscriptores[i] != -1) {
            Suscriptor sub = archivoSuscriptor.buscarPorId(idsSuscriptores[i]);
            std::cout << sub.getNombre() << " (ID " << idsSuscriptores[i] << "): "
                      << contador[i] << " accesos\n";
        }
    }
}


void Reportes::CantidadSuscriptoresDadosDeBaja() {
    SuscriptorArchivo archivoSuscriptor;
    int totalSuscriptores = archivoSuscriptor.getCantidadRegistros();
    int cantidadBaja = 0;

    std::cout << "\nSUSCRIPTORES DADOS DE BAJA ============================\n";

    for (int i = 0; i < totalSuscriptores; i++) {
        Suscriptor sub = archivoSuscriptor.leer(i);

        if (sub.getActivo() == false) {
            std::cout << sub.getNombre() << " (ID " << sub.getIdSuscriptor() << ") - Dado de baja\n";
            cantidadBaja++;
        }
    }

    std::cout << "\nTotal de suscriptores dados de baja: " << cantidadBaja << "\n";
}
