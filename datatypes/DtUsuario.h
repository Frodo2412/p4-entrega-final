
#ifndef P4_ENTREGA_FINAL_DTUSUARIO_H
#define P4_ENTREGA_FINAL_DTUSUARIO_H

#include <string>
#include <iostream>

using namespace std;

class DtUsuario {
private:
    string nombre;
    string mail;

public:
    DtUsuario(string nombre, string mail);

    virtual string getNombre() const;

    string getEmail() const;

    friend ostream &operator<<(ostream &os, const DtUsuario *usuario);

};

#endif //P4_ENTREGA_FINAL_DTUSUARIO_H
