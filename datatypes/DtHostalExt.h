//
// Created by User on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTHOSTALEXT_H
#define P4_ENTREGA_FINAL_DTHOSTALEXT_H

#include "DtResenia.h"
#include "DtComentario.h"

#include <string>

using std::string;

class DtHostalExt {
private:
    string nombre;
    string direccion;
    int calificacionProm;

    //Implementacion de coleccion de DTResenia como un ICollection

public:
    DtHostalExt(string, string, int/*, coleccion DTResenia*/);
    ~DtHostalExt(){};

    string getNombre();
    string getDireccion();
    int getCalificacionProm();

    //Ops vinculadas al uso del set(DTResenia)
};


#endif //P4_ENTREGA_FINAL_DTHOSTALEXT_H
