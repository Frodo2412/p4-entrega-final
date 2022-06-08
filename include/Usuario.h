//
// Created by guillermorey on 6/7/22.
//

#ifndef P4_ENTREGA_FINAL_USUARIO_H
#define P4_ENTREGA_FINAL_USUARIO_H


#include "DtUsuario.h"

class Usuario {
protected:
    string nombre;
    string mail;
    string password;

public:
    Usuario(string nombre, string mail, string password);

    virtual DtUsuario *getDatos() = 0;
};


#endif //P4_ENTREGA_FINAL_USUARIO_H
