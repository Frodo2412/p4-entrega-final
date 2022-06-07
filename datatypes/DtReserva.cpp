//
// Created by MontoroA on 7/6/2022.
//

#include "DtReserva.h"

int DtReserva:getCodigo(){
    return codigo;
}

DtFecha* DtReserva:getCheckIn(){
    return checkIn;
}

DtFecha* DtReserva:getCheckOut(){
    return checkOut;
}

DtEstado* DtReserva:getEstado(){
    return estado;
}

int DtReserva:getCosto(){
    return costo;
}