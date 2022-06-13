
#ifndef P4_ENTREGA_FINAL_DTHUESPED_H
#define P4_ENTREGA_FINAL_DTHUESPED_H

#include "DtUsuario.h"
#include <string>

using std::string;

class DtHuesped : public DtUsuario {
private:
    bool esFinger;

public:
    DtHuesped(string nombre, string email, bool esFinger);

    bool getEsFinger() const;

    friend ostream &operator<<(ostream &os, DtHuesped empleado);
};


#endif //P4_ENTREGA_FINAL_DTHUESPED_H
