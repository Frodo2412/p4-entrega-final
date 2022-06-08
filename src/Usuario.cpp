
#include "Usuario.h"

#include <utility>
#include "DtUsuario.h"

Usuario::Usuario(string nombre, string mail, string password) {
    this->nombre = std::move(nombre);
    this->mail = std::move(mail);
    this->password = std::move(password);
}
