//
// Created by unzip on 09/06/22.
//

#include <algorithm>
#include "HostalController.h"

using namespace std;
typedef std::pair<std::string, Hostal *> hostalesPair;

Empleado *HostalController::getEmpleado() {
    return nullptr;
}

Hostal *HostalController::getHostal() {
    return nullptr;
}

DtResenia HostalController::getCalificacion() {
    return DtResenia(0, " __cxx11::basic_string()", "__cxx11::basic_string()", DtFecha());
}

list<Hostal *> HostalController::getHostales() {
    return list<Hostal *>();
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
    return list<DtResenia>();
}

list<DtEmpleado> HostalController::mostrarDesempleados() {
    IUsuarioController *usuarioController = UsuarioController::getInstance();
    return usuarioController->getEmpleadosDesemplados(hostalAux);
}

void HostalController::cancelarContratoEmpleado() {
    delete empleadoAux;
    delete hostalAux;
}

Empleado *HostalController::seleccionarEmpleado(string email, DtCargo cargo) {
    IUsuarioController *usuarioController = UsuarioController::getInstance();
    return usuarioController->getEmpleado(email);
}

void HostalController::altaHostal(string nombre, string direccion, int telefono) {
}
Hostal* HostalController::findHostal(Empleado *empleado) {
    return nullptr;
}

void HostalController::elegirHostal(string nombre) {
    hostalAux = hostales[nombre];
}

//void HostalController::cancelarAltaHabitacion() {
//    delete hostalAux;
//}
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

list<DtHostal *> HostalController::mostrarTop3Hostales() {
    vector<hostalesPair> vec;
    std::copy(hostales.begin(), hostales.end(), std::back_inserter<std::vector<hostalesPair>>(vec));
    std::sort(vec.begin(), vec.end(),
              [](const hostalesPair &l, const hostalesPair &r) {
                  if (l.second->getCalificacionPromedio() > r.second->getCalificacionPromedio()) {
                      return l.second > r.second;
                  }
                  return l < r;
              });
    list<DtHostal *> top3;
    int it = 0;
    while(it < 3 && vec[it].second != nullptr) {
        top3.push_back(vec[it].second);

        it++;
    }
}

HostalController::HostalController() = default;