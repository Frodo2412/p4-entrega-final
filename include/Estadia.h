
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H

#include "Resenia.h"
#include "Reserva.h"
#include "Reloj.h"
//En teoria no deberia haber mas include excepto los DtTypes necessarios

class Resenia;

#include "Resenia.h"

class Resenia;

class Estadia {
private:
    Resenia *maybeResenia;
public:
    void finalizarActiva();

    Resenia *getResenia();

};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
