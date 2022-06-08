
#include "DtHuesped.h"

#include <utility>

DtHuesped::DtHuesped(string nombre, string email, bool esFinger) : DtUsuario(std::move(nombre), std::move(email)) {
    this->esFinger = esFinger;
}


bool DtHuesped::getEsFinger() const {
    return esFinger;
}
