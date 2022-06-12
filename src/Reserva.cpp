
#include "Reserva.h"
#include "ReservaController.h"
#include <cassert>

Estadia *Reserva::getEstadia() {
    return maybeEstadia;
}

bool Reserva::isReservaCancelada() {
    return estado == DtEstado::Cancelada;
}

Huesped *Reserva::getReservante() {
    return huespedReservante;
}

void Reserva::setEstado(DtEstado estado) {
    this->estado = estado;
}

void Reserva::setReservante(Huesped *huesped) {
    this->huespedReservante = huesped;
}

void Reserva::configReserva(Huesped *huespedReservante) {
    setReservante(huespedReservante);
    setCodigoGenerado();
}

// TODO: Cuando este el constructor de Estadia hacer este metodo
Estadia Reserva::createEstadia(DtFecha fecha) {
    return Estadia();
}

void Reserva::finalizarReservaActiva() {
    Estadia *est = getEstadia();
    if (est != nullptr) est->finalizarActiva();
}

DtResenia Reserva::getReseniaSinResponder() {
    assert(hasReseniaSinResponder());
    return maybeEstadia->getResenia()->getDatos();
}



bool Reserva::hasReseniaSinResponder() {
    return maybeEstadia != nullptr && maybeEstadia->hasReseniaSinResponder();
}

Resenia *Reserva::getResenia() {
    if (maybeEstadia != nullptr) return maybeEstadia->getResenia();
    else return nullptr;
}

bool Reserva::checkIfSameHostal(Hostal *otroHostal) {
    return habitacion->checkIfCoincideHostal(otroHostal);
}

Habitacion *Reserva::getHabitacion() {
    return habitacion;
}

void Reserva::setCodigoGenerado() {
    ReservaController *controller = ReservaController::getInstance();
    this->codigo = controller->getNextCodigoReserva();
}

Reserva::Reserva(DtFecha checkIn, DtFecha checkOut, Huesped *huespedReservante, Habitacion *habitacion) {
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->huespedReservante = huespedReservante;
    this->habitacion = habitacion;
    setCodigoGenerado();
    this->maybeEstadia = nullptr;
    this->estado = DtEstado::Abierta;
}
bool Reserva::hasResenia() {
    return maybeEstadia != nullptr && maybeEstadia->hasResenia();
}
