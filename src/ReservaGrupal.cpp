
#include "ReservaGrupal.h"

bool ReservaGrupal::tieneHuespedAsociado(string email) {
    for (auto huesped: huespedes)
        if (huesped->isMail(email))
            return true;
    return false;
}

DtReservaGrupal *ReservaGrupal::getDatos() {
    return new DtReservaGrupal(codigo, checkIn, checkOut, Abierta, getCosto(), huespedes.size());
}

int ReservaGrupal::getCosto() {
    int cantFingers = 0;
    for (auto huesped: huespedes)
        if (huesped->isFinger()) cantFingers++;

    int total = habitacion->getPrecioPorNoche() * huespedes.size();
    if (cantFingers >= 2) return total * 0.7;
    else return total;
}
