
#include "DtUsuario.h"

DtUsuario::DtUsuario(string name, string email) {
    nombre = name;
    mail = email;
}

string DtUsuario::getNombre() const {
    return nombre;
}

string DtUsuario::getEmail() const {
    return mail;
}

std::ostream &operator<<(std::ostream &os, const DtUsuario usuario) {
    os << "nombre: " << usuario.getNombre() << "mail: " << usuario.getEmail();
    return os;
}
