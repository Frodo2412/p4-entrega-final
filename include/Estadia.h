
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H

#include "Resenia.h"
#include "Reserva.h"
#include "Reloj.h"

#include <list>

class Resenia;

class Estadia {
private:
    Resenia *maybeResenia;
public:
    void finalizarActiva();

    Resenia *getResenia();

    list<DtResenia> getReseniasSinResponder();

    void destruirAsociaciones();
};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
