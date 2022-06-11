
#include "DtUsuario.h"

#include <utility>

DtUsuario::DtUsuario(string name, string email) {
    nombre = std::move(name);
    mail = std::move(email);
}

string DtUsuario::getNombre() const {
    return nombre;
}

string DtUsuario::getEmail() const {
    return mail;
}

std::ostream &operator<<(std::ostream &os, const DtUsuario usuario) {
    os << "nombre: " << usuario.getNombre() << ", mail: " << usuario.getEmail();
    return os;
}
