
#include "Habitacion.h"

Habitacion::Habitacion(int numero, int precioPorNoche, int capacidad) {
    this->numero = numero;
    this->precioPorNoche = precioPorNoche;
    this->capacidad = capacidad;
    this->hostal = nullptr;
    this->reservas = list<Reserva *>();
}

void Habitacion::setHostal(Hostal *hostalParameter) {
    this->hostal = hostalParameter;
}

Hostal Habitacion::getHostal() {
    return *hostal;
}

DtHabitacion Habitacion::getDatos() const {
    return {numero, capacidad, precioPorNoche};
}

list<DtReserva> Habitacion::getReservasAsociadas(const string &email) {
    list<DtReserva> reservasAsociadas = list<DtReserva>();
    for (Reserva *reserva: reservas)
        if (reserva->isReservaCancelada() && reserva->tieneHuespedAsociado(email))
            reservasAsociadas.push_back(reserva->getDatos());
    return reservasAsociadas;
}

bool Habitacion::checkIfCoincideHostal(Hostal hostal) {
    return *this->hostal == hostal;
}

list<DtResenia> Habitacion::getReseniasSinResponder() {
    list<DtResenia> reseniasSinResponder = list<DtResenia>();
    for (Reserva *reserva: reservas) {
        Resenia *resenia = reserva->getEstadia()->getResenia();
        if (resenia->isComentada())
            reseniasSinResponder.push_back(reserva->getEstadia()->getResenia()->getDatos());
    }
    return reseniasSinResponder;
}


