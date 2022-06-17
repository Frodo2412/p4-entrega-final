
#include "../include/Reserva.h"
#include "../include/ReservaController.h"

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

void Reserva::finalizarReservaActiva() {
    if (maybeEstadia != nullptr) maybeEstadia->finalizarActiva();
}

DtResenia Reserva::getReseniaSinResponder() {
    if (hasReseniaSinResponder()) return maybeEstadia->getResenia()->getDatos();
    else throw invalid_argument("No hay resenia sin responder");
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
    this->maybeEstadia = nullptr;
    this->estado = DtEstado::Abierta;
    this->codigo = 0;
}

bool Reserva::hasResenia() {
    return maybeEstadia != nullptr && maybeEstadia->hasResenia();
}

int Reserva::getCodigo() const {
    return codigo;
}

DtEstado Reserva::getEstado() {
    return estado;
}

Reserva::~Reserva() = default;
