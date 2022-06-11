
#include "Reserva.h"

Estadia *Reserva::getEstadia() {
    return maybeEstadia;
}

bool Reserva::isReservaCancelada() {
    return estado == DtEstado::Cancelada;
}

DtReserva Reserva::getDatos() {
    return {1, DtFecha(1, 1, 1, 1), DtFecha(1, 1, 1, 1), DtEstado::Cancelada, 1};
}

