
#include "DtHostal.h"

#include <utility>

DtHostal::DtHostal(string nombre, string direccion, int calificacionPromedio) {
    this->nombre = std::move(nombre);
    this->direccion = std::move(direccion);
    this->calificacionPromedio = calificacionPromedio;
}

string DtHostal::getNombre() {
    return nombre;
}

string DtHostal::getDireccion() {
    return direccion;
}

int DtHostal::getCalificacionProm() const {
    return calificacionPromedio;
}
