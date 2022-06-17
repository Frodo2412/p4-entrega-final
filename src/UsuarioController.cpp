
#include "../include/UsuarioController.h"

Empleado *UsuarioController::getEmpleado(string email) {
    Empleado *empleado;
    if (empleados.find(email) != empleados.end())
        return empleados[email];
    else throw invalid_argument("No existe un empleado con ese mail");
}

list<DtEmpleado> UsuarioController::getEmpleadosDesemplados(Hostal *hostal) {
    list<DtEmpleado> infoEmpleados;
    for (auto &itr: empleados)
        if (!hostal->trabajaEmpleadoEnHostal(itr.second))
            infoEmpleados.push_back(itr.second->getDatosEmpleado());
    if (infoEmpleados.empty()) throw invalid_argument("No existen empleados que no trabajen en " + hostal->getNombre());
    return infoEmpleados;
}

list<DtHuesped> UsuarioController::getHuespedes() {
    if (huespedes.empty()) throw invalid_argument("No existen huespedes en el sistema.");
    list<DtHuesped> lista;
    for (auto &itr: huespedes)
        lista.push_back(itr.second->getDatosHuesped());
    return lista;
}

Huesped *UsuarioController::findHuesped(string email) {
    if (huespedes.find(email) != huespedes.end()) return huespedes[email];
    else throw invalid_argument("No existe un huesped con el mail ingresado.");
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
    if (usuarios.find(email) == usuarios.end()) throw invalid_argument("No existe un usuario con ese mail.");
    return usuarios[email]->getDatos();
}

Empleado *UsuarioController::findEmpleado(string email) {
    if (empleados.find(email) != empleados.end()) return empleados[email];
    else throw invalid_argument("No existe un empleado con el mail ingresado.");
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
        cargoAux = DtCargo::PlaceHolder;
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
    if (empleados.empty()) throw invalid_argument("No hay empleados disponibles.");
    list<DtEmpleado> lista;
    for (auto &itr: empleados)
        lista.push_back(itr.second->getDatosEmpleado());
    return lista;
}
