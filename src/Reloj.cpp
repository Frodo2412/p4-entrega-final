
#include "Reloj.h"

Reloj *Reloj::instancia = nullptr;

Reloj::Reloj() = default;

DtFecha Reloj::getFechaActual() {
    return this->fechaActual;
}

void Reloj::modificarFechaDeSistema(int anio, int mes, int dia, int hora) {
    this->fechaActual = DtFecha(hora, dia, mes, anio);
}

Reloj *Reloj::getInstance() {
    if (instancia == nullptr) instancia = new Reloj();
    return instancia;
}
