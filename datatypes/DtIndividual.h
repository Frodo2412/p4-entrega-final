//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTINDIVIDUAL_H
#define P4_ENTREGA_FINAL_DTINDIVIDUAL_H

#include "DtReserva.h"

class DtIndividual: public DtReserva{
public:
    DtIndividual(int, DtFecha*, DtFecha*, DtEstado*, int);
    ~DtIndividual() override;

    int getCosto() override;
};


#endif //P4_ENTREGA_FINAL_DTINDIVIDUAL_H
