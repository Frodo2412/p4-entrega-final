//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTRESERVA_H
#define P4_ENTREGA_FINAL_DTRESERVA_H

#include "DtFecha.h"
#include "DtEstado.h"

class DtReserva{
protected:
    int codigo;
    DtFecha* checkIn;
    DtFecha* checkOut;
    DtEstado* estado;
    int costo;

public:
    virtual ~DtReserva();

    int getCodigo();
    DtFecha* getCheckIn();
    DtFecha* getCheckOut();
    DtEstado* getEstado();
    virtual int getCosto() = 0;
};


#endif //P4_ENTREGA_FINAL_DTRESERVA_H
