
#ifndef P4_ENTREGA_FINAL_DTUSUARIO_H
#define P4_ENTREGA_FINAL_DTUSUARIO_H

#include <string>

using std::string;

class DtUsuario {
private:
    string nombre;
    string mail;

public:
    DtUsuario(string nombre, string mail);

    string getNombre();
    string getEmail();
};


#endif //P4_ENTREGA_FINAL_DTUSUARIO_H
