//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTEMPLEADO_H
#define P4_ENTREGA_FINAL_DTEMPLEADO_H

#include "DtCargo.h"
#include "DtUsuario.h"
#include <string>

using std::string;

class DtEmpleado: public DtUsuario {
private:
    DtCargo* cargo;

public:
    DtEmpleado(string, string, DtCargo*);
    ~DtEmpleado(){};

    DtCargo* getCargo();

};



#endif //P4_ENTREGA_FINAL_DTEMPLEADO_H
