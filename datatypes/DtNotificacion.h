
#ifndef P4_ENTREGA_FINAL_DTNOTIFICACION_H
#define P4_ENTREGA_FINAL_DTNOTIFICACION_H

#include "DtFecha.h"
#include <string>

using namespace std;

class DtNotificacion {
private:
    int calificacion;
    DtFecha fecha;
    string resenia;
    string comentario;
    string autor;

public:
    DtNotificacion(int calificacion, DtFecha fecha, string resenia, string comentario, string autor);

    int getCalificacion();

    DtFecha getFecha();

    string getResenia();

    string getComentario();

    string getAutor();

};


#endif //P4_ENTREGA_FINAL_DTNOTIFICACION_H
