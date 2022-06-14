//
// Created by unzip on 09/06/22.
//

#include "UsuarioController.h"

Empleado *UsuarioController::getEmpleado(string email) {
    return empleados[email];
}

list<DtEmpleado> UsuarioController::getEmpleadosDesemplados(Hostal *hostal) {
    map<string, Empleado *>::iterator itr;
    list<DtEmpleado> lista;
    for (itr = empleados.begin(); itr != empleados.end(); itr++) {
        if (!hostal->trabajaEmpleadoEnHostal(itr->second)) {
            lista.push_back(itr->second->getDatosEmpleado());
        }
    }
    return lista;
}

list<DtHuesped> UsuarioController::getHuespedes() {
    map<string, Huesped *>::iterator itr;
    list<DtHuesped> lista;
    for (itr = huespedes.begin(); itr != huespedes.end(); itr++) {
        lista.push_back(itr->second->getDatosHuesped());
    }
    return lista;
}
Huesped *UsuarioController::findHuesped(string email) {
    return huespedes[email];
}
list<DtUsuario> UsuarioController::mostrarUsuarios() {
    map<string, Usuario *>::iterator itr;
    list<DtUsuario> lista;
    for (itr = usuarios.begin(); itr != usuarios.end(); itr++) {
        lista.push_back(itr->second->getDatos());
    }
    return lista;
}
DtUsuario UsuarioController::mostrarInformacionUsuario(string email) {
    return usuarios[email]->getDatos();
}
Empleado *UsuarioController::findEmpleado(string email) {
    return empleados[email];
}
void UsuarioController::especificarEsFinger(bool esFinger) {
    esFingerAux = esFinger;
}
void UsuarioController::especificarCargo(DtCargo cargo) {
    cargoAux = &cargo;
}
void UsuarioController::comenzarAltaUsuario(string nombre, string email, string password) {
    nombreAux = nombre;
    emailAux = email;
    passwordAux = password;
}
void UsuarioController::confirmarAltaUsuario() {
    if (cargoAux != nullptr) {
        empleadoAux = new Empleado(nombreAux, emailAux, passwordAux, *cargoAux);
        empleados.insert(pair<string, Empleado *>(emailAux, empleadoAux));
        usuarios.insert(pair<string, Usuario *>(emailAux, empleadoAux));
    } else {
        huespedAux = new Huesped(nombreAux, emailAux, passwordAux, esFingerAux);
        huespedes.insert(pair<string, Huesped *>(emailAux, huespedAux));
        usuarios.insert(pair<string, Usuario *>(emailAux, huespedAux));
    }
}
void UsuarioController::cancelarAltaUsuario() {
    delete empleadoAux;
    delete huespedAux;
    cargoAux = nullptr;
    nombreAux = "";
    emailAux = "";
    passwordAux = "";
    esFingerAux = false;
}
void UsuarioController::ingresarEmail(string email) {
    emailAux = email;
}
UsuarioController *UsuarioController::getInstance() {
    if (instancia == nullptr) {
        instancia = new UsuarioController();
    }
    return instancia;
}
UsuarioController::~UsuarioController() {
    map<string, Empleado *>::iterator itr;
    for (itr = empleados.begin(); itr != empleados.end(); itr++) {
        delete itr->second;
    }
    map<string, Huesped *>::iterator it;
    for (it = huespedes.begin(); it != huespedes.end(); it++) {
        delete it->second;
    }
}

UsuarioController *UsuarioController::instancia = nullptr;

UsuarioController::UsuarioController() = default;


list<DtEmpleado> UsuarioController::getEmpleados() {
    map<string, Empleado *>::iterator itr;
    list<DtEmpleado> lista;
    for (itr = empleados.begin(); itr != empleados.end(); itr++) {
        lista.push_back(itr->second->getDatosEmpleado());
    }
    return lista;
}
