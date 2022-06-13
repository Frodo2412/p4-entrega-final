
#include "Usuario.h"

#include <utility>

Usuario::Usuario(string nombre, string mail, string password) {
    this->nombre = std::move(nombre);
    this->mail = std::move(mail);
    this->password = std::move(password);
}
string Usuario::getNombre() {
    return nombre;
}
string Usuario::getMail() {
    return mail;
}
string Usuario::getPassword() {
    return password;
}
