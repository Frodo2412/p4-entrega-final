
#include "../include/ReservaGrupal.h"
#include <cmath>
#include <utility>

bool ReservaGrupal::tieneHuespedAsociado(string email) {
    return huespedes.find(email) != huespedes.end();
}

DtReservaGrupal *ReservaGrupal::getDatos() {
    return new DtReservaGrupal(codigo, checkIn, checkOut, Abierta, getCosto(), int(huespedes.size()));
}

int ReservaGrupal::getCosto() {
    int cantFingers = 0;
    for (auto &it: huespedes)
        if (it.second->isFinger()) cantFingers++;
    int total = floor(habitacion->getPrecioPorNoche() * huespedes.size());
    return cantFingers >= 2 ? int(total * 0.7) : total;
}


Estadia *ReservaGrupal::createEstadia(DtFecha checkIn) {
    maybeEstadia = new Estadia(checkIn, huespedReservante, huespedes, this);
    return maybeEstadia;
}

ReservaGrupal::ReservaGrupal(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante, Habitacion *habitacion,
                             map<string, Huesped *> invitados) : Reserva(checkIn, checkOut, huespedReservante,
                                                                         habitacion) {
    huespedes = std::move(invitados);
}
