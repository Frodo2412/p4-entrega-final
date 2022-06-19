
#include "DtHuesped.h"

#include <utility>

DtHuesped::DtHuesped(string nombre, string email, bool esFinger) : DtUsuario(std::move(nombre), std::move(email)) {
    this->esFinger = esFinger;
}


bool DtHuesped::getEsFinger() const {
    return esFinger;
}

std::ostream &operator<<(std::ostream &os, const DtHuesped *huesped) {
    os << "nombre: " << huesped->getNombre() << ", mail: " << huesped->getEmail();
    if (huesped->getEsFinger()) {
        os << ", Es Finger";
    } else {
        os << ", No Es Finger";
    }
    return os;
}
DtHuesped::~DtHuesped() = default;
