
#include "Habitacion.h"
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
    map<int, Reserva *>::iterator itr;
    list<DtReserva *> reservasAsociadas;
    for (itr = reservas.begin(); itr != reservas.end(); itr++) {
        if (itr->second->isReservaCancelada() && itr->second->tieneHuespedAsociado(email)) {
            reservasAsociadas.push_back(itr->second->getDatos());
        }
    }
    return reservasAsociadas;
}

bool Habitacion::checkIfCoincideHostal(Hostal *otroHostal) {
    return hostal->checkIfSameHostal(otroHostal);
}

list<DtResenia> Habitacion::getReseniasSinResponder() {
    map<int, Reserva *>::iterator itr;
    list<DtResenia> resenias;
    for (itr = reservas.begin(); itr != reservas.end(); itr++) {
        if(itr->second->hasReseniaSinResponder()) {
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
    map<int, Reserva *>::iterator itr;
    list<DtResenia> resenias;
    for (itr = reservas.begin(); itr != reservas.end(); itr++) {
        if(itr->second->hasResenia()) {
            resenias.push_back(itr->second->getResenia()->getDatos());
        }
    }
    return resenias;
}
int Habitacion::getCalificacionPromedio() {
    list<DtResenia> resenias = getResenias();
    int calificacion = 0;
    for(const DtResenia& resenia : resenias) {
        calificacion += resenia.getCalificacion();
    }
    return floor(calificacion / resenias.size());

}
