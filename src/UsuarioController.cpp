
#include "UsuarioController.h"

Empleado *UsuarioController::getEmpleado(string email) {
    Empleado *empleado;
    if (empleados.find(email) != empleados.end())
        empleado = empleados[email];
    else
        empleado = nullptr;
    return empleado;
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
    Huesped *huesped;
    if (huespedes.find(email) != huespedes.end())
        huesped = huespedes[email];
    else
        huesped = nullptr;
    return huesped;
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
    Empleado *empleado;
    if (empleados.find(email) != empleados.end())
        empleado = empleados[email];
    else
        empleado = nullptr;
    return empleado;
}

Usuario *UsuarioController::findUsuario(string email) {
    Usuario *usuario;
    if (usuarios.find(email) != usuarios.end())
        usuario = usuarios[email];
    else
        usuario = nullptr;
    return usuario;
}

void UsuarioController::especificarEsFinger(bool esFinger) {
    esFingerAux = esFinger;
}

void UsuarioController::especificarCargo(DtCargo cargo) {
    cargoAux = cargo;
}

void UsuarioController::comenzarAltaUsuario(string nombre, string email, string password) {
    nombreAux = nombre;
    emailAux = email;
    passwordAux = password;
}

void UsuarioController::confirmarAltaUsuario() {
    if (cargoAux != DtCargo::PlaceHolder) {
        empleadoAux = new Empleado(nombreAux, emailAux, passwordAux, cargoAux);
        empleados.insert({emailAux, empleadoAux});
        usuarios.insert({emailAux, empleadoAux});
    } else {
        huespedAux = new Huesped(nombreAux, emailAux, passwordAux, esFingerAux);
        huespedes.insert({emailAux, huespedAux});
        usuarios.insert({emailAux, huespedAux});
    }
}

void UsuarioController::cancelarAltaUsuario() {
    delete empleadoAux;
    delete huespedAux;
    cargoAux = DtCargo::PlaceHolder;
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

UsuarioController::UsuarioController() {
    usuarios = {};
    empleados = {};
    huespedes = {};
    empleadoAux = nullptr;
    huespedAux = nullptr;
    cargoAux = DtCargo::PlaceHolder;
    nombreAux = "";
    emailAux = "";
    passwordAux = "";
    esFingerAux = false;
}


list<DtEmpleado> UsuarioController::getEmpleados() {
    map<string, Empleado *>::iterator itr;
    list<DtEmpleado> lista;
    for (itr = empleados.begin(); itr != empleados.end(); itr++) {
        lista.push_back(itr->second->getDatosEmpleado());
    }
    return lista;
}
