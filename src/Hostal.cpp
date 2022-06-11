
#include "../include/Hostal.h"
Hostal::Hostal(string nombre, string direccion, int telefono) {
}
DtHostal Hostal::getDatos() {
    return DtHostal(nombre, direccion, getCalificacionPromedio());
}
Habitacion *Hostal::getHabitacion(int codigo) {
    return nullptr;
}
void Hostal::agregarHabitacionAHostal(Habitacion *habitacion) {
}
void Hostal::agregarEmpleadoAHostal(Empleado *empleado) {
}
bool Hostal::trabajaEmpleadoEnHostal(Empleado *empleado) {
}
bool Hostal::esEsteHostal(Hostal *otroHostal) {
    return false;
}
Hostal *Hostal::getHostalSiTrabaja(Empleado *empleado) {
    return nullptr;
}
DtHostalExt Hostal::getDatosExt() {
    return DtHostalExt(nombre, direccion, getCalificacionPromedio(), getDatosReseniasDeHostal());
}
bool Hostal::habitacionPerteneceAHostal(Habitacion *habitacion) {
    return false;
}
int Hostal::getCalificacionPromedio() {
    return 0;
}
list<DtResenia> Hostal::getDatosReseniasDeHostal() {
    return list<DtResenia>();
}

bool Hostal::operator==(Hostal hostal) {
    return false;
}
