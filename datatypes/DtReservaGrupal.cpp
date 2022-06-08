
#include "DtReservaGrupal.h"

DtReservaGrupal::DtReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, DtEstado estadoInicial, int costo,
                                 int cantidadHuespedes)
        : DtReserva(codigo, checkIn,
                    checkOut,
                    estadoInicial, costo) {
    this->cantHuespedes = cantidadHuespedes;
}

int DtReservaGrupal::getCantidadHuespedes() const {
    return cantHuespedes;
}
