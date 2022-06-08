
#include "DtReserva.h"

DtReserva::DtReserva(int codigo, DtFecha checkIn, DtFecha checkOut, DtEstado estadoInicial, int costo) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estadoInicial;
    this->costo = costo;
}

int DtReserva::getCodigo() const {
    return codigo;
}

DtFecha DtReserva::getCheckIn() {
    return checkIn;
}

DtFecha DtReserva::getCheckOut() {
    return checkOut;
}

DtEstado DtReserva::getEstado() {
    return estado;
}

int DtReserva::getCosto() const {
    return costo;
}
