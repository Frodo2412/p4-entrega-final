//
// Created by User on 6/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTRESENIA_H
#define P4_ENTREGA_FINAL_DTRESENIA_H

#include "DtFecha.h"
#include <string>

using std::string;

class DtResenia {
private:
    int calificacion;
    string resenia;
    string comentario;

    DtFecha* fecha;

public:
    DtResenia(int, string, string, DtFecha*);
    ~DtResenia(){};

    int getCalificacion();
    string getResenia();
    string getComentario();
    DtFecha* getFecha();
};

#endif //P4_ENTREGA_FINAL_DTRESENIA_H
