
#include "DtReservaGrupal.h"
#include "DtHuesped.h"

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

ostream &operator<<(ostream &os, DtReservaGrupal *reserva) {
//TODO: ACA DEBERIA DEVOLVER TODOS LOS INVITADOS ESTA EN EL LAB 0
    return os;
}

string DtReservaGrupal::getTipoReserva() {
    return "Grupal";
}
