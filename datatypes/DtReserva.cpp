#include <iostream>
#include "DtReserva.h"
#include "DtReservaGrupal.h"

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

DtFecha DtReserva::getCheckIn() const {
    return checkIn;
}

DtFecha DtReserva::getCheckOut() const {
    return checkOut;
}

DtEstado DtReserva::getEstado() const {
    return estado;
}

int DtReserva::getCosto() const {
    return costo;
}

ostream &operator<<(std::ostream &os, DtReserva *reserva) {
    os << "codigo: " << reserva->getCodigo() << ", check in: " << reserva->getCheckIn() << ", check out: "
       << reserva->getCheckOut() << ", estado: " << reserva->getEstadoToString() << ", costo $" << reserva->getCosto() << std::endl;

    if (dynamic_cast<DtReservaGrupal *>(reserva)) {
        os << dynamic_cast<DtReservaGrupal *>(reserva);
    }
    return os;
}

string DtReserva::getEstadoToString() const {
    switch (estado) {
        case Abierta:
            return "Abierta";
        case Cerrada:
            return "Cerrada";
        case Cancelada:
            return "Cancelada";
        default:
            return "Estado Invalido";
    }
}
DtReserva::~DtReserva() = default;
