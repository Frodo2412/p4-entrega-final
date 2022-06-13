
#ifndef P4_ENTREGA_FINAL_USUARIO_H
#define P4_ENTREGA_FINAL_USUARIO_H

#include "../datatypes/DtUsuario.h"

class Usuario {
protected:
    string nombre;
    string mail;
    string password;

public:
    Usuario(string nombre, string mail, string password);

    string getNombre();

    string getMail();

    string getPassword();

    virtual DtUsuario getDatos() = 0;
};


#endif //P4_ENTREGA_FINAL_USUARIO_H
