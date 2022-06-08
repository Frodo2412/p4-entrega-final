
#include "Usuario.h"

#include <utility>
#include "DtUsuario.h"

DtUsuario Usuario::getDatos() {
    return {this->nombre, this->mail};
}

Usuario::Usuario(string nombre, string mail, string password) {
    this->nombre = std::move(nombre);
    this->mail = std::move(mail);
    this->password = std::move(password);
}
