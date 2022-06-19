
#include "../include/Empleado.h"

Empleado::Empleado(string nombre, string mail, string password, DtCargo cargo) : Usuario(std::move(nombre),
                                                                                         std::move(mail),
                                                                                         std::move(password)) {
    this->cargo = cargo;
};

DtEmpleado *Empleado::getDatos() {
    return new DtEmpleado(this->nombre, this->mail, this->cargo);
};

void Empleado::setCargo(DtCargo cargo) {
    this->cargo = cargo;
};

DtCargo Empleado::getCargo() {
    return this->cargo;
}

DtEmpleado Empleado::getDatosEmpleado() {
    return {this->nombre, this->mail, this->cargo};
}

void Empleado::notify(DtNotificacion notif) {
    notificaciones.push_back(notif);
}

list<DtNotificacion> Empleado::getNotificaciones() {
    list<DtNotificacion> notisLeidas;
    notisLeidas.splice(notisLeidas.end(), notificaciones);
    if (notisLeidas.empty()) throw invalid_argument("El empleado no tiene notificaciones sin leer.");
    return notisLeidas;
}
