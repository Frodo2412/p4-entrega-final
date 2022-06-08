
#ifndef P4_ENTREGA_FINAL_DTRESERVA_H
#define P4_ENTREGA_FINAL_DTRESERVA_H

#include "DtFecha.h"
#include "DtEstado.h"

class DtReserva {
protected:
    int codigo;
    DtFecha checkIn;
    DtFecha checkOut;
    DtEstado estado;
    int costo;

public:
    DtReserva(int codigo, DtFecha checkIn, DtFecha checkOut, DtEstado estadoInicial, int costo);

    int getCodigo() const;

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    DtEstado getEstado();

    int getCosto() const;
};


#endif //P4_ENTREGA_FINAL_DTRESERVA_H
