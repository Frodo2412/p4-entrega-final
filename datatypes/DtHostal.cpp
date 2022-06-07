//
// Created by User on 7/6/2022.
//

#include "DtHostal.h"

DtHostal::DtHostal(string nom, string dir, int calif){
    nombre = nom;
    direccion = dir;
    calificacionProm = calif;
}

string DtHostal::getNombre(){
    return nombre;
}

string DtHostal::getDireccion(){
    return direccion;
}

int DtHostal::getCalificacionProm(){
    return calificacionProm;
}
