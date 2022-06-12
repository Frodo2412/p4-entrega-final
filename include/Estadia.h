
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H

#include "Resenia.h"
#include "Reserva.h"
#include "Reloj.h"


class Resenia;

class Estadia {
private:
    Resenia *maybeResenia;
public:
    void finalizarActiva();

    Resenia *getResenia();

    bool hasResenia();

    bool hasReseniaSinResponder();

    void destruirAsociaciones();
};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
