//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTHUESPED_H
#define P4_ENTREGA_FINAL_DTHUESPED_H

#include "DtUsuario.h"
#include <string>

using std::string;

class DtHuesped: public DtUsuario{
private:
    bool esFinger;

public:
    DtHuesped(string, string, bool);
    ~DtHuesped(){};

    bool getEsFinger();
};


#endif //P4_ENTREGA_FINAL_DTHUESPED_H
