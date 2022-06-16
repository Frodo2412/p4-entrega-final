
#include "DtHabitacion.h"

DtHabitacion::DtHabitacion(int numero, int capacidad, int precio) {
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

int DtHabitacion::getNumero() const {
    return numero;
}

int DtHabitacion::getCapacidad() const {
    return capacidad;
}

int DtHabitacion::getPrecio() const {
    return precio;
}

ostream &operator<<(ostream &os, DtHabitacion habitacion) {
    cout << "Habitacion " << habitacion.getNumero() << ":" << endl;
    cout << "-Capacidad: " << habitacion.getCapacidad() << endl;
    cout << "-Costo por noche: " << habitacion.getPrecio() << endl;
}
