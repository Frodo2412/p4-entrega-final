//
// Created by unzip on 09/06/22.
//

#include <algorithm>
#include "HostalController.h"
#include "NotificacionController.h"

using namespace std;
typedef std::pair<std::string, Hostal *> hostalesPair;

Empleado *HostalController::getEmpleado() {
    return empleadoAux;
}

Hostal *HostalController::getHostal() {
    return hostalAux;
}

list<Hostal *> HostalController::getHostales() {
    list<Hostal *> hostalesList = list<Hostal *>();
    for (auto &hostal: hostales)
        hostalesList.push_back(hostal.second);
    return hostalesList;
}

list<DtHostal> HostalController::mostrarHostales() {
    map<string, Hostal *>::iterator itr;
    list<DtHostal> lista;
    for (itr = hostales.begin(); itr != hostales.end(); itr++) {
        lista.push_back(itr->second->getDatos());
    }
    return lista;

}

list<DtResenia> HostalController::masInformacionSobreHostal(string nombre) {
    if (hostales[nombre] != nullptr)
        return hostales[nombre]->getDatosReseniasDeHostal();
    else
        throw std::invalid_argument("no se encontro un hostal con ese nombre");
}

list<DtEmpleado> HostalController::mostrarDesempleados() {
    IUsuarioController *usuarioController = UsuarioController::getInstance();
    return usuarioController->getEmpleadosDesemplados(hostalAux);
}

void HostalController::cancelarContratoEmpleado() {
    delete empleadoAux;
    delete hostalAux;
}

void HostalController::seleccionarEmpleado(string email, DtCargo cargo) {
    IUsuarioController *usuarioController = UsuarioController::getInstance();
    empleadoAux = usuarioController->getEmpleado(email);
    cargoAux = cargo;
}

void HostalController::altaHostal(string nombre, string direccion, int telefono) {
    if (hostales[nombre] == nullptr) {
        hostalAux = new Hostal(nombre, direccion, telefono);
        hostales.insert({nombre, hostalAux});
    } else {
        cout << "ya existe un hostal con ese nombre" << endl;
    }
}

Hostal *HostalController::findHostal(Empleado *empleado) {
//TODO: en el diagrama aparece que tengo que ver si existe un
// empleado con ese nombre pero hostalController no tiene lista
// de empleados y en el miro no hay ningun getinstance a usuariocontroller
    map<string, Hostal *>::iterator it;
    it = hostales.begin();
    bool found = false;
    Hostal *hostal;
    while (it != hostales.end() && !found) {
        if (it->second->trabajaEmpleadoEnHostal(empleado)) {
            hostal = it->second;
            found = true;
        }
        it++;
    }
    if (found)
        return hostal;
    else
        return nullptr;
}

void HostalController::elegirHostal(string nombre) {
    hostalAux = hostales[nombre];
}

HostalController *HostalController::getInstance() {
    if (instancia == nullptr) {
        instancia = new HostalController();
    }
    return instancia;
}

void HostalController::confirmarContratoEmpleado() {
    empleadoAux->setCargo(cargoAux);
    hostalAux->agregarEmpleadoAHostal(empleadoAux);
}

HostalController *HostalController::instancia = nullptr;

HostalController::HostalController() = default;

list<DtHostal> HostalController::mostrarTop3Hostales() {
    vector<hostalesPair> vec;
    std::copy(hostales.begin(), hostales.end(), std::back_inserter<std::vector<hostalesPair>>(vec));
    std::sort(vec.begin(), vec.end(),
              [](const hostalesPair &l, const hostalesPair &r) {
                  if (l.second->getCalificacionPromedio() > r.second->getCalificacionPromedio()) {
                      return l.second > r.second;
                  }
                  return l < r;
              });
    list<DtHostal> top3;
    int it = 0;
    while (it < 3 && vec[it].second != nullptr) {
        auto top = DtHostal(vec[it].second->getDatos());
        top3.push_back(top);
        it++;
    }
    return top3;
}

DtHostalExt HostalController::informacionHostal() {
    return hostalAux->getDatosExt();
}

void HostalController::ingresarDatosHabitacion(int num, int precio, int capacidad) {
    this->num = num;
    this->precio = precio;
    this->capacidad = capacidad;
}

void HostalController::cancelarAltaHabitacion() {}

void HostalController::confirmarAltaHabitacion() {
    auto *habitacion = new Habitacion(num, precio, capacidad);
    habitacion->setHostal(hostalAux);
    hostalAux->agregarHabitacionAHostal(habitacion);
}

HostalController::~HostalController() {
    map<string, Hostal *>::iterator itr;
    for (itr = hostales.begin(); itr != hostales.end(); itr++)
        delete itr->second;
    delete hostalAux;
    delete empleadoAux;
    delete instancia;
}
//TODO: se libera memoria como dice el diagrama?