//
// Created by MontoroA on 7/6/2022.
//

#include "DtGrupal.h"

DtGrupal::DtGrupal(int code, DtFecha* chIn, DtFecha* chOut, DtEstado* state, int cost, int cant){
    codigo = code;
    checkIn = chIn;
    checkOut = chOut;
    estado = state;
    costo = cost;
    cantHuespedes = cant;
}

int DtGrupal::getCantHuespedes(){
    return cantHuespedes;
}

int DtGrupal::getCosto(){
    return costo;
}