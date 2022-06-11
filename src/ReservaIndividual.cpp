
#include "ReservaIndividual.h"

bool ReservaIndividual::tieneHuespedAsociado(string email) {
    return huespedReservante->isMail(email);
}

ReservaIndividual::ReservaIndividual(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante,
                                     Habitacion *habitacion) : Reserva(checkIn, checkOut, huespedReservante,
                                                                       habitacion) {}

DtReservaIndividual *ReservaIndividual::getDatos() {
    return new DtReservaIndividual(codigo, checkIn, checkOut, estado, getCosto());
}

int ReservaIndividual::getCosto() {
    return habitacion->getPrecioPorNoche() * (checkOut - checkIn);
}
