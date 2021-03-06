
#include "../include/Estadia.h"
#include <utility>

void Estadia::finalizarActiva() {
    if (isCerrada()) {
        Reloj *r = Reloj::getInstance();
        setCheckOut(r->getFechaActual());
    }
}

Estadia::Estadia(DtFecha checkIn, Huesped *reservante, map<string, Huesped *> invitados, Reserva *reserva) {
    this->checkIn = checkIn;
    this->huespedes = std::move(invitados);
    this->huespedes.insert(pair<string, Huesped *>(reservante->getMail(), reservante));
    this->reserva = reserva;
    this->maybeResenia = nullptr;
}

Estadia::Estadia(DtFecha checkIn, Huesped *reservante, Reserva *reserva) {
    this->checkIn = checkIn;
    this->huespedes.insert(pair<string, Huesped *>(reservante->getMail(), reservante));
    this->reserva = reserva;
    this->maybeResenia = nullptr;
}

void Estadia::setReserva(Reserva *res) {
    this->reserva = res;
}

bool Estadia::isCerrada() {
    return reserva->getEstado() == Cerrada;
}

void Estadia::setCheckOut(DtFecha fechaSalida) {
    this->checkOut = fechaSalida;
}


Resenia *Estadia::getResenia() {
    return maybeResenia;
}

DtEstadia Estadia::getDatos() {
    return {reserva->getHabitacion()->getHostal().getNombre(), reserva->getReservante()->getMail(),
            reserva->getHabitacion()->getNumero(), checkIn, checkOut, "", reserva->getCodigo()};
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

Reserva *Estadia::getReserva() {
    return reserva;
}

DtResenia Estadia::getDatosResenia() {
    if (maybeResenia != nullptr) return maybeResenia->getDatos();
    else throw invalid_argument("No hay resenia");

}

DtReserva *Estadia::getDatosReserva() {
    return reserva->getDatos();
}
