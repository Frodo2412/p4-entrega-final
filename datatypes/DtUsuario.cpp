
#include "DtUsuario.h"

DtUsuario::DtUsuario(string name, string email) {
    nombre = name;
    mail = email;
}

string DtUsuario::getNombre() {
    return nombre;
}

string DtUsuario::getEmail() {
    return mail;
}
