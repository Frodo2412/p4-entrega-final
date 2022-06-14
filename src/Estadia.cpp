
#include "Estadia.h"
#include <utility>

void Estadia::finalizarActiva() {
    if (isAbierta()) {
        Reloj *r = Reloj::getInstance();
        setCheckOut(r->getFechaActual());
    }
}

Estadia::Estadia(DtFecha checkIn, Huesped *reservante, map<string, Huesped *> invitados, Reserva *reserva) {
    this->checkIn = checkIn;
    this->huespedes = invitados;
    this->huespedes[reservante->getMail()] = reservante;
    this->reserva = reserva;
    this->maybeResenia = nullptr;
}

Estadia::Estadia(DtFecha checkIn, Huesped *reservante, Reserva *reserva) {
    this->checkIn = checkIn;
    this->huespedes[reservante->getMail()] = reservante;
    this->reserva = reserva;

}

void Estadia::setReserva(Reserva *res) {
    this->reserva = res;
}

bool Estadia::isAbierta() {
    return reserva->getEstado() == Abierta;
}

void Estadia::setCheckOut(DtFecha fechaSalida) {
    this->checkOut = fechaSalida;
}


Resenia *Estadia::getResenia() {
    return maybeResenia;
}

DtEstadia Estadia::getDatos() {
    return {reserva->getHabitacion()->getHostal().getNombre(), reserva->getReservante()->getMail(),
            reserva->getHabitacion()->getNumero(), checkIn, checkOut, ""};
}

void Estadia::setResenia(Resenia *resenia) {
    this->maybeResenia = resenia;

}


bool Estadia::hasReseniaSinResponder() {
    if (hasResenia()) {
        return !maybeResenia->isComentada();
    } else {
        return false;
    }
}

bool Estadia::hasResenia() {
    return maybeResenia != nullptr;
}
