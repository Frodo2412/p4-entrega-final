
#ifndef P4_ENTREGA_FINAL_DTRESERVAGRUPAL_H
#define P4_ENTREGA_FINAL_DTRESERVAGRUPAL_H

#include "DtReserva.h"
#include "DtHuesped.h"
#include <list>

class DtReservaGrupal : public DtReserva {
private:
    int cantHuespedes;
public:
    DtReservaGrupal(int codigo, DtFecha chIn, DtFecha chOut, DtEstado estadoInicial, int costo, int cantidadHuespedes);

    int getCantidadHuespedes() const;

    string getTipoReserva() override;

    friend ostream &operator<<(ostream &os, DtReservaGrupal* reserva);
};


#endif //P4_ENTREGA_FINAL_DTRESERVAGRUPAL_H
