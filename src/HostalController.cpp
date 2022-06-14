//
// Created by unzip on 09/06/22.
//

#include "HostalController.h"

void HostalController::ingresarDatosHabitacion(int numero, int cantidad, int precio) {
    numeroAux = numero;
    cantidadAux = cantidad;
    precioAux = precio;
    auto *hab = new Habitacion(numero, cantidad, precio);
    habitaciones.insert(pair<int, Habitacion *>(numero, hab));
}

void HostalController::confirmarAltaHabitacion() {
    auto *hab = new Habitacion(numeroAux, cantidadAux, precioAux);
    hab->setHostal(hostalAux);
    habitaciones.insert(pair<int, Habitacion *>(hab->getNumero(), hab));
    hostalAux->agregarHabitacionAHostal(hab);
}


Empleado *HostalController::getEmpleado() {
    return nullptr;
}
Hostal *HostalController::getHostal() {
    return nullptr;
}
DtResenia HostalController::getCalificacion() {
    return DtResenia(0, " __cxx11::basic_string()", "__cxx11::basic_string()", DtFecha(), 1);
}
list<Hostal *> HostalController::getHostales() {
    return list<Hostal *>();
}
list<DtHostal> HostalController::mostrarHostales() {
    return list<DtHostal>();
}
list<DtResenia> HostalController::masInformacionSobreHostal(string nombre) {
    return list<DtResenia>();
}
list<DtEmpleado> HostalController::mostrarDesempleados() {
    return list<DtEmpleado>();
}
void HostalController::cancelarContratoEmpleado() {
}
void HostalController::seleccionarEmpleado(string email, DtCargo cargo) {
    UsuarioController *usuarioController = UsuarioController::getInstance();
    empleadoAux = usuarioController->getEmpleado(email);
    cargoAux = cargo;
}
void HostalController::altaHostal(string nombre, string direccion, int telefono) {
}
Hostal *HostalController::findHostal(Empleado *empleado) {
    return nullptr;
}
void HostalController::elegirHostal(string nombre) {
}
void HostalController::cancelarAltaHabitacion() {
}
HostalController *HostalController::getInstance() {
    return nullptr;
}
void HostalController::confirmarContratoEmpleado() {
    empleadoAux->setCargo(cargoAux);
    hostalAux->agregarEmpleadoAHostal(empleadoAux);
}

//TODO: Implementar
list<DtHostal> HostalController::mostrarTop3Hostales() {
    return list<DtHostal>();
}
DtHostalExt HostalController::informacionHostal() {
    return {hostalAux->getNombre(), hostalAux->getDireccion(), hostalAux->getCalificacionPromedio(), hostalAux->getResenias()};
}
