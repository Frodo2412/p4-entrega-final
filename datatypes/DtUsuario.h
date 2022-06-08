
#ifndef P4_ENTREGA_FINAL_DTUSUARIO_H
#define P4_ENTREGA_FINAL_DTUSUARIO_H

#include <string>

using std::string;

class DtUsuario {
protected:
    string nombre;
    string mail;

public:
    DtUsuario(string nombre, string email);

    string getNombre();

    string getEmail();
};


#endif //P4_ENTREGA_FINAL_DTUSUARIO_H
