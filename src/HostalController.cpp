//
// Created by unzip on 09/06/22.
//

#include "HostalController.h"
Empleado *HostalController::getEmpleado() {
    return nullptr;
}
Hostal *HostalController::getHostal() {
    return nullptr;
}
DtResenia HostalController::getCalificacion() {
    return DtResenia(0," __cxx11::basic_string()", "__cxx11::basic_string()", DtFecha());
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
Empleado *HostalController::seleccionarEmpleado(string email, DtCargo cargo) {
    return nullptr;
}
void HostalController::altaHostal(string nombre, string direccion, int telefono) {
}
Hostal* HostalController::findHostal(Empleado *empleado) {
    return nullptr;
}
void HostalController::elegirHostal(string nombre) {
}
void HostalController::cancelarAltaHabitacion() {
}
HostalController *HostalController::getInstance() {
    return nullptr;
}
