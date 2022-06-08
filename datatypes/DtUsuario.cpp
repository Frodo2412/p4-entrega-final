//
// Created by User on 7/6/2022.
//

#include "DtUsuario.h"

string DtUsuario::getNombre(){
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
