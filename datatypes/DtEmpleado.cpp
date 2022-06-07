//
// Created by MontoroA on 7/6/2022.
//

#include "DtEmpleado.h"

DtEmpleado::DtEmpleado(string nom, string em, DtCargo* c){
    nombre = nom;
    mail = em;
    cargo = c;
}


Dtcargo* DtEmpleado::getCargo(){
    return cargo;
}
