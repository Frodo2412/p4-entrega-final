//
// Created by unzip on 07/06/22.
//

#include "Reloj.h"
//TODO: Modificar para hacer un DTFecha con valores iniciales
Reloj::Reloj() {
    this->fechaActual = DTFecha();
}

}

DtFecha Reloj::getFechaActual() {
    return this->fechaActual;
}

void Reloj::modificarFechaDeSistema(int anio, int mes, int dia, int hora) {
    this->fechaActual = DTFecha(anio, mes, dia, hora);
}

Reloj Reloj::getInstance() {
    if (instancia == nullptr) {
        instancia = new Reloj();
    }
    return instancia;
}
