//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTRESERVAINDIVIDUAL_H
#define P4_ENTREGA_FINAL_DTRESERVAINDIVIDUAL_H

#include "DtReserva.h"

class DtReservaIndividual : public DtReserva {
public:
    DtReservaIndividual(int codigo, DtFecha checkIn, DtFecha checkOut, DtEstado estadoInicial, int costo);
};


#endif //P4_ENTREGA_FINAL_DTRESERVAINDIVIDUAL_H
