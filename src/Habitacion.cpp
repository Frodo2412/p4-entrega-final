
#include "../include/Habitacion.h"
#include <cmath>

Habitacion::Habitacion(int numero, int precioPorNoche, int capacidad) {
    this->numero = numero;
    this->precioPorNoche = precioPorNoche;
    this->capacidad = capacidad;
    this->hostal = nullptr;
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

list<DtReserva *> Habitacion::getReservasAsociadas(const string &email) {
    list<DtReserva *> reservasAsociadas;
    for (auto itr: reservas)
        if ((!itr.second->isReservaCancelada()) && itr.second->tieneHuespedAsociado(email))
            reservasAsociadas.push_back(itr.second->getDatos());
    return reservasAsociadas;
}

bool Habitacion::checkIfCoincideHostal(Hostal *otroHostal) {
    return hostal->checkIfSameHostal(otroHostal);
}

list<DtResenia> Habitacion::getReseniasSinResponder() {
    map<int, Reserva *>::iterator itr;
    list<DtResenia> resenias;
    for (itr = reservas.begin(); itr != reservas.end(); itr++) {
        if (itr->second->hasReseniaSinResponder()) {
            resenias.push_back(itr->second->getReseniaSinResponder());
        }
    }
    return resenias;
}

int Habitacion::getPrecioPorNoche() const {
    return precioPorNoche;
}

int Habitacion::getNumero() const {
    return numero;
}

list<DtResenia> Habitacion::getResenias() {
    list<DtResenia> infoResenias;
    for (auto &itr: reservas)
        if (itr.second->hasResenia())
            infoResenias.push_back(itr.second->getResenia()->getDatos());
    return infoResenias;
}

int Habitacion::getCalificacionPromedio() {
    list<DtResenia> resenias = getResenias();
    if (resenias.empty()) return 0;
    else {
        int calificacion = 0;
        for (const auto &resenia: resenias)
            calificacion += resenia.getCalificacion();
        return floor(calificacion / resenias.size());
    }
}

void Habitacion::addReserva(Reserva *pReserva) {
    reservas.insert({pReserva->getCodigo(), pReserva});
}
