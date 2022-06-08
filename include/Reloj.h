//
// Created by unzip on 07/06/22.
//

#ifndef P4_ENTREGA_FINAL_RELOJ_H
#define P4_ENTREGA_FINAL_RELOJ_H


#include "DtFecha.h"

class Reloj {
private:
    DtFecha fechaActual = DtFecha(1,1,1,2000);
    static Reloj * instancia;
    Reloj();
public:
    static Reloj getInstance();
    DtFecha getFechaActual();
    void modificarFechaDeSistema(int, int, int, int);
};


#endif //P4_ENTREGA_FINAL_RELOJ_H
