
#include "DtEstadia.h"

#include <utility>

DtEstadia::DtEstadia(string nombreHostal, string emailHuesped, int numeroHabitacion, DtFecha checkIn,
                     DtFecha checkOut, string codigoPromo, int codigo) {
    this->nombreHostal = std::move(nombreHostal);
    this->emailHuesped = std::move(emailHuesped);
    this->numeroHabitacion = numeroHabitacion;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    promo = std::move(codigoPromo);
    this->codigo = codigo;
}

string DtEstadia::getHostal() {
    return nombreHostal;
}

string DtEstadia::getHuesped() {
    return emailHuesped;
}

int DtEstadia::getHabitacion() const {
    return numeroHabitacion;
}

DtFecha DtEstadia::getCheckIn() {
    return checkIn;
}

DtFecha DtEstadia::getCheckOut() {
    return checkOut;
}

string DtEstadia::getPromo() {
    return promo;
}
int DtEstadia::getCodigo() const {
    return codigo;
}
