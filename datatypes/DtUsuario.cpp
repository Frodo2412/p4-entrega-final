
#include "DtUsuario.h"

DtUsuario::DtUsuario(string nombre, string email) {
    this->nombre = nombre;
    this->mail = email;
}

string DtUsuario::getNombre() {
    return nombre;
}

DtUsuario::DtUsuario(string nombre, string mail) {
    this->nombre = nombre;
    this->mail = mail;
}

string DtUsuario::getMail() {
    return this->mail;
}

DtUsuario::~DtUsuario() {}
