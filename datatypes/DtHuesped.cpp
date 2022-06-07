//
// Created by MontoroA on 7/6/2022.
//

#include "DtHuesped.h"

DtHuesped::DtHuesped(string nom, string em, bool esF){
    nombre = nom;
    mail = em;
    esFinger = esF;
}


bool DtHuesped::getEsFinger(){
    return esFinger;
}

string DtHuesped::getMail(){
    return mail;
}