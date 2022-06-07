//
// Created by User on 7/6/2022.
//

#include "DtHostalExt.h"

DtHostalExt::DtHostalExt(string nom, string dir, int calif, DtResenia** ress){
    nombre = nom;
    direccion = dir;
    calificacionProm = calif;

    resenias = ress;
}

string DtHostalExt::getNombre(){
    return nombre;
}

string DtHostalExt::getDireccion(){
    return direccion;
}

int DtHostalExt::getCalificacionProm(){
    return calificacionProm;
}

DtResenia** DtHostalExt::getResenias(){
    return resenias;
}