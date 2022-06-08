//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTUSUARIO_H
#define P4_ENTREGA_FINAL_DTUSUARIO_H

#include <string>

using std::string;

class DtUsuario {
protected:
    string nombre;
    string mail;

public:
    DtUsuario(string nombre, string mail);
    ~DtUsuario();

    string getNombre();
    string getMail();
    string getDatos();
};


#endif //P4_ENTREGA_FINAL_DTUSUARIO_H
