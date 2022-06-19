
#include "DtEmpleado.h"

#include <utility>

DtEmpleado::DtEmpleado(string nombre, string email, DtCargo cargo) : DtUsuario(std::move(nombre), std::move(email)) {
    this->cargo = cargo;
}


DtCargo DtEmpleado::getCargo() const {
    return cargo;
}

ostream &operator<<(ostream &os, const DtEmpleado *empleado) {
    os << "nombre: " << empleado->getNombre() << ", mail: " << empleado->getEmail() << ", cargo: "
       << empleado->cargoToString();
    return os;
}

string DtEmpleado::cargoToString() const {
    switch (cargo) {
        case Administracion:
            return "Administracion";
        case Limpieza:
            return "Limpieza";
        case Recepcion:
            return "Recepcion";
        case Infraestructura:
            return "Infraestructura";
        default:
            return "Cargo Invalido";
    }
}
