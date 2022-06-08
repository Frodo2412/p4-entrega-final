
#include "DtUsuario.h"

DtUsuario::DtUsuario(string nombre, string email) {
    this->nombre = nombre;
    this->mail = email;
}

string DtUsuario::getNombre() {
    return nombre;
}

string DtUsuario::getEmail() {
    return mail;
}
