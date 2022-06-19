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
    if (habitaciones.empty()) throw invalid_argument(nombre + " no tiene habitaciones disponibles.");
    list<DtHabitacion> lista;
    for (auto &itr: habitaciones)
        lista.push_back(itr.second->getDatos());
    return lista;
}

Habitacion *Hostal::getHabitacion(int numero) {
    if (habitaciones.find(numero) != habitaciones.end()) return habitaciones[numero];
    else throw invalid_argument("No existe la habitacion indicada en este hostal.");
}

list<DtReserva *> Hostal::getReservasNoCanceladas(const string &email) {
    list<DtReserva *> infoReservas;
    for (auto &itr: habitaciones) {
        list<DtReserva *> reservasDeUsuario = itr.second->getReservasAsociadas(email);
        infoReservas.insert(infoReservas.end(), reservasDeUsuario.begin(), reservasDeUsuario.end());
    }
    if (infoReservas.empty()) throw invalid_argument("Este huesped no tiene reservas en el hostal.");
    return infoReservas;
}


bool Hostal::checkIfSameHostal(Hostal *otroHostal) {
    return nombre == otroHostal->getNombre();
}

list<DtResenia> Hostal::getReseniasSinResponder() {
    list<DtResenia> lista = list<DtResenia>();
    for (auto const &habitacion: habitaciones) {
        list<DtResenia> ofHabitacion = habitacion.second->getReseniasSinResponder();
        lista.insert(lista.end(), ofHabitacion.begin(), ofHabitacion.end());
    }
    return lista;
}

int Hostal::getCalificacionPromedio() {
    if (habitaciones.empty()) return 0;
    else {
        int calificacionPromedio = 0;
        int habitacionesConResenia = 0;
        for (auto &it: habitaciones) {
            if (it.second->hasResenias()) {
                habitacionesConResenia++;
                calificacionPromedio += it.second->getCalificacionPromedio();
            }
        }
        if (habitacionesConResenia > 0) return calificacionPromedio / habitacionesConResenia;
        else return 0;
    }
}

list<DtResenia> Hostal::getDatosReseniasDeHostal() {
    list<DtResenia> lista;
    for (auto const &habitacion: habitaciones) {
        auto resenias = habitacion.second->getResenias();
        lista.insert(lista.end(), resenias.begin(), resenias.end());
    }
    return lista;
}

bool Hostal::yaExisteHabitacion(int numero) {
    return habitaciones.find(numero) != habitaciones.end();
}
