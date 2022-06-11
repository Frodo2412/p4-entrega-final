//
// Created by unzip on 09/06/22.
//

#include "UsuarioController.h"
Empleado *UsuarioController::getEmpleado(string email) {
    return nullptr;
}
DtEmpleado UsuarioController::getDatos(Empleado *empleado) {
    return DtEmpleado("__cxx11::basic_string()", "__cxx11::basic_string()", Limpieza);
}
Empleado *UsuarioController::getEmpleado() {
    return nullptr;
}
list<DtEmpleado> UsuarioController::getEmpleados() {
    return list<DtEmpleado>();
}
list<DtHuesped> UsuarioController::getHuespedes() {
    return list<DtHuesped>();
}
Huesped *UsuarioController::findHuesped(string email) {
    return nullptr;
}
list<DtUsuario> UsuarioController::mostrarUsuarios() {
    return list<DtUsuario>();
}
DtUsuario UsuarioController::mostrarInformacionUsuario(string email) {
    return DtUsuario("__cxx11::basic_string()", "__cxx11::basic_string()");
}
Empleado *UsuarioController::findEmpleado(string email) {
    return nullptr;
}
void UsuarioController::especificarEsFinger(bool esFinger) {
}
void UsuarioController::especificarCargo(DtCargo cargo) {
}
void UsuarioController::comenzarAltaUsuario(string nombre, string email, string password) {
}
void UsuarioController::confirmarAltaUsuario() {
}
void UsuarioController::cancelarAltaUsuario() {
}
void UsuarioController::ingresarEmail(string email) {
}
UsuarioController *UsuarioController::getInstance() {
    return nullptr;
}
