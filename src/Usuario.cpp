//
// Created by guillermorey on 6/7/22.
//

#include "Usuario.h"
#include "DtUsuario.h"

DtUsuario Usuario::getDatos() {
    return DtUsuario(this->nombre, this->mail);
}

Usuario::Usuario(string nombre, string mail, string password) {
    this->nombre = nombre;
    this->mail = mail;
    this->password = password;
}

Usuario::~Usuario() {}
