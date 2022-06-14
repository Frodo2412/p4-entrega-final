
#include "ReservaGrupal.h"
#include <cmath>

bool ReservaGrupal::tieneHuespedAsociado(string email) {
    return huespedes.find(email) != huespedes.end();
}

DtReservaGrupal *ReservaGrupal::getDatos() {
    return new DtReservaGrupal(codigo, checkIn, checkOut, Abierta, getCosto(), huespedes.size());
}

int ReservaGrupal::getCosto() {
    int cantFingers = 0;
    map<string, Huesped *>::iterator it;
    for (it = huespedes.begin(); it != huespedes.end(); it++)
        if (it->second->isFinger()) cantFingers++;
    int total = floor(habitacion->getPrecioPorNoche() * huespedes.size());
    return cantFingers >= 2 ? total * 0.7 : total;
}



Estadia ReservaGrupal::createEstadia(DtFecha checkIn) {
    return Estadia(checkIn,huespedReservante,huespedes, this);
}