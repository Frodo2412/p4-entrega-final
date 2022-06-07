//
// Created by User on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTHOSTALEXT_H
#define P4_ENTREGA_FINAL_DTHOSTALEXT_H

#include "DtResenia.h"

#include <string>

using std::string;

class DtHostalExt{
private:
    string nombre;
    string direccion;
    int calificacionProm;

    DtResenia** resenias;
public:
    DtHostalExt(string, string, int, DtResenia**);
    ~DtHostalExt(){};

    string getNombre();
    string getDireccion();
    int getCalificacionProm();

    DtResenia** getResenias();
};


#endif //P4_ENTREGA_FINAL_DTHOSTALEXT_H
