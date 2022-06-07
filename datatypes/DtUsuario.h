//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTUSUARIO_H
#define P4_ENTREGA_FINAL_DTUSUARIO_H

#include <string>

using std::string;

class DtUsuario {
private:
    string nombre;
    string mail;

public:
    DtUsuario() = 0;
    ~DtUsuario(){};

    string getNombre();
    string getMail();
};


#endif //P4_ENTREGA_FINAL_DTUSUARIO_H
