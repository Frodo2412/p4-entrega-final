//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTNOTIFICACION_H
#define P4_ENTREGA_FINAL_DTNOTIFICACION_H

#include "DtFecha.h"
#include <string>

using std::string;

class DtNotificacion {
private:
    int calificacion;
    DtFecha* fecha;
    string resenia;
    string comentario;
    string autor;

public:
    DtNotificacion(int, DtFecha*, string, string, string);
    ~DtNotificacion();

    int getCalificacion();
    DtFecha* getFecha();
    string getResenia();
    string getComentario();
    string getAutor();

};


#endif //P4_ENTREGA_FINAL_DTNOTIFICACION_H
