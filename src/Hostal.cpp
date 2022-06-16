#include "../include/Hostal.h"

#include <cmath>
#include <utility>

Hostal::Hostal(string nombreNuevo, string direccionNuevo, int telefonoNuevo) {
    nombre = std::move(nombreNuevo);
    direccion = std::move(direccionNuevo);
    telefono = telefonoNuevo;
    habitaciones = {};
    empleados = {};
}

DtHostal Hostal::getDatos() {
    int calificacionPromedio = getCalificacionPromedio();
    return {this->nombre, this->direccion, calificacionPromedio};
}

DtHostalExt Hostal::getDatosExt() {
    int calificacionPromedio = getCalificacionPromedio();
    list<DtResenia> resenias = getDatosReseniasDeHostal();
    return {nombre, direccion, calificacionPromedio, resenias};
}

string Hostal::getNombre() {
    return nombre;
}


void Hostal::agregarHabitacionAHostal(Habitacion *hab) {
    habitaciones.insert({hab->getNumero(), hab});
}

void Hostal::agregarEmpleadoAHostal(Empleado *e) {
    empleados.insert({e->getMail(), e});
}

bool Hostal::trabajaEmpleadoEnHostal(Empleado *e) {
    if (empleados.find(e->getMail()) == empleados.end()) return false;
    else return true;

}


list<DtHabitacion> Hostal::getInfoDeHabitaciones() {
    map<int, Habitacion *>::iterator itr;
    list<DtHabitacion> lista;
    for (itr = habitaciones.begin(); itr != habitaciones.end(); itr++)
        lista.push_back(itr->second->getDatos());
    return lista;
}

Habitacion *Hostal::getHabitacion(int numero) {
    if (habitaciones.find(numero) != habitaciones.end()) return habitaciones[numero];
    else throw invalid_argument("No existe la habitacion indicada en este hostal.");
}

list<DtReserva *> Hostal::getReservasNoCanceladas(const string &email) {
    list<DtReserva *> infoReservas;
    for (auto &itr: habitaciones)
        infoReservas.splice(infoReservas.end(), itr.second->getReservasAsociadas(email));
    if (infoReservas.empty()) throw invalid_argument("Este huesped no tiene reservas en el hostal.");
    return infoReservas;
}


bool Hostal::checkIfSameHostal(Hostal *otroHostal) {
    return nombre == otroHostal->getNombre();
}

list<DtResenia> Hostal::getReseniasSinResponder() {
    map<int, Habitacion *>::iterator itrMap;
    list<DtResenia> lista;
    for (itrMap = habitaciones.begin(); itrMap != habitaciones.end(); itrMap++) {
        lista.splice(lista.end(), itrMap->second->getReseniasSinResponder());
    }
    return lista;
}

int Hostal::getCalificacionPromedio() {
    if (habitaciones.empty()) return 0;
    else {
        int calificacionPromedio = 0;
        for (auto &it: habitaciones)
            calificacionPromedio += it.second->getCalificacionPromedio();
        return floor(calificacionPromedio / habitaciones.size());
    }
}

list<DtResenia> Hostal::getDatosReseniasDeHostal() {
    map<int, Habitacion *>::iterator itrMap;
    list<DtResenia> lista;
    for (itrMap = habitaciones.begin(); itrMap != habitaciones.end(); itrMap++) {
        lista.splice(lista.end(), itrMap->second->getResenias());
    }
    return lista;
}

bool Hostal::yaExisteHabitacion(int numero) {
    return habitaciones.find(numero) != habitaciones.end();
}
