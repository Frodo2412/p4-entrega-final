
#include <algorithm>
#include "HostalController.h"

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
    if (hostales.empty()) throw invalid_argument("No hay hostales disponibles.");
    list<DtHostal> infoHostales;
    for (auto &itr: hostales) {
        infoHostales.push_back(itr.second->getDatos());
    }
    return infoHostales;

}

list<DtResenia> HostalController::masInformacionSobreHostal(string nombre) {
    if (hostales.find(nombre) != hostales.end()) return hostales[nombre]->getDatosReseniasDeHostal();
    else throw std::invalid_argument("no se encontro un hostal con ese nombre");
}

list<DtEmpleado> HostalController::mostrarDesempleados() {
    UsuarioController *usuarioController = UsuarioController::getInstance();
    return usuarioController->getEmpleadosDesemplados(hostalAux);
}

void HostalController::cancelarContratoEmpleado() {
    delete empleadoAux;
    delete hostalAux;
}

void HostalController::seleccionarEmpleado(string email, DtCargo cargo) {
    UsuarioController *usuarioController = UsuarioController::getInstance();
    try {
        empleadoAux = usuarioController->getEmpleado(email);
        cargoAux = cargo;
    } catch (invalid_argument &ex) {
        throw ex;
    }
}

void HostalController::altaHostal(string nombre, string direccion, int telefono) {
    if (hostales.find(nombre) == hostales.end()) {
        hostalAux = new Hostal(nombre, direccion, telefono);
        hostales.insert({nombre, hostalAux});
    } else throw invalid_argument("Ya existe un hostal con ese nombre");
}

Hostal *HostalController::findHostal(Empleado *empleado) {
    UsuarioController *usuarioController = UsuarioController::getInstance();
    usuarioController->findEmpleado(
            empleado->getMail()); // La llamo nomas para verificar que exista, si no existe va a tirar una exception
    map<string, Hostal *>::iterator it;
    it = hostales.begin();
    while (it != hostales.end()) {
        if (it->second->trabajaEmpleadoEnHostal(empleado))
            return it->second;
        it++;
    }
    throw invalid_argument("El empleado elegido no tiene hostal.");
}

void HostalController::elegirHostal(string nombre) {
    if (hostales.find(nombre) != hostales.end()) hostalAux = hostales[nombre];
    else throw invalid_argument("No existe un hostal con ese nombre");
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

HostalController::HostalController() {
    hostales = {};
    empleadoAux = nullptr;
    hostalAux = nullptr;
    num = 0;
    precio = 0;
    capacidad = 0;
    cargoAux = DtCargo(0);
}

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

void HostalController::ingresarDatosHabitacion(int numero, int precioPorNoche, int capacidadMaxima) {
    this->num = numero;
    this->precio = precioPorNoche;
    this->capacidad = capacidadMaxima;
}

void HostalController::cancelarAltaHabitacion() {}

void HostalController::confirmarAltaHabitacion() {
    if (hostalAux->yaExisteHabitacion(num))
        throw invalid_argument("Ya existe una habitacion con ese numero en este hostal");
    else {
        auto *habitacion = new Habitacion(num, precio, capacidad);
        habitacion->setHostal(hostalAux);
        hostalAux->agregarHabitacionAHostal(habitacion);
    }
}

HostalController::~HostalController() {
    for (auto &itr: hostales)
        delete itr.second;
    delete hostalAux;
    delete empleadoAux;
    delete instancia;
}
//TODO: se libera memoria como dice el diagrama?