//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTGRUPAL_H
#define P4_ENTREGA_FINAL_DTGRUPAL_H

#include "DtReserva.h"

class DtGrupal: public DtReserva{
private:
    int cantHuespedes;

public:
    DtGrupal(int, DtFecha*, DtFecha*, DtEstado*, int, int);
    ~DtGrupal() override;

    int getCosto() override;
    int getCantHuespedes();
};


#endif //P4_ENTREGA_FINAL_DTGRUPAL_H
