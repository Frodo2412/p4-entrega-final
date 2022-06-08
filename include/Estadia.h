
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H


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
