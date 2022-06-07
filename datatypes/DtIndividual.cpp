//
// Created by MontoroA on 7/6/2022.
//

#include "DtIndividual.h"

DtIndividual::DtIndividual(int code, DtFecha* chIn, DtFecha* chOut, DtEstado* state, int cost){
    codigo = code;
    checkIn = chIn;
    checkOut = chOut;
    estado = state;
    costo = cost;
}

int DtIndividual::getCosto(){
    return costo;
}