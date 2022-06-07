//
// Created by User on 7/6/2022.
//

#include "DtHostalExt.h"

DtHostalExt::DtHostalExt(string nom, string dir, int calif/*, coleccion DTResenia*/){
    nombre = nom;
    direccion = dir;
    calificacionProm = calif;

    //Asignacion del set(DTResenia), el cual deberia haber sido creado por la clase expert y pasado como param
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

//Implementacion ops vinculadas al uso del set(DTResenia)