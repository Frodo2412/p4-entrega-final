
#include "DtFecha.h"
#include <iostream>

using namespace std;

DtFecha::DtFecha() = default;

DtFecha::DtFecha(int hora, int dia, int mes, int anio) {
    if (hora < 0 || hora > 23)
        throw invalid_argument("Hora invalida");
    if (dia < 0 || dia > 30)
        throw invalid_argument("Dia invalido");
    if (mes < 0 || 12 < mes)
        throw invalid_argument("Mes invalido");
    if (anio < 1901)
        throw invalid_argument("Anio invalido");
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DtFecha::getHora() const {
    return hora;
}

int DtFecha::getDia() const {
    return dia;
}

int DtFecha::getMes() const {
    return mes;
}

int DtFecha::getAnio() const {
    return anio;
}

int DtFecha::operator-(DtFecha *f) const {
    int f1 = this->dia + this->mes * 30 + this->anio * 365;
    int f2 = f->getDia() + f->getMes() * 30 + f->getAnio() * 365;

    return f1 - f2;
}

ostream &operator<<(ostream &os, const DtFecha fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << ", " << fecha.getHora() << "hrs";
    return os;
}
