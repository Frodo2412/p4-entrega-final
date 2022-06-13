//
// Created by MontoroA on 7/6/2022.
//

#include "DtReservaIndividual.h"

DtReservaIndividual::DtReservaIndividual(int codigo, DtFecha checkIn, DtFecha checkOut, DtEstado estadoInicial,
                                         int costo) : DtReserva(codigo, checkIn, checkOut, estadoInicial, costo) {}

string DtReservaIndividual::getTipoReserva() {
    return "Individual";
}
