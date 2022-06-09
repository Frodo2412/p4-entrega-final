
#include "DtUsuario.h"

#include <utility>

DtUsuario::DtUsuario(string name, string email) {
    nombre = std::move(name);
    mail = std::move(email);
}

string DtUsuario::getNombre() {
    return nombre;
}

string DtUsuario::getEmail() {
    return mail;
}
