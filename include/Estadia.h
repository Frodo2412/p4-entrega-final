
#ifndef P4_ENTREGA_FINAL_ESTADIA_H
#define P4_ENTREGA_FINAL_ESTADIA_H

#include "Resenia.h"
#include "Reserva.h"
#include "Reloj.h"
//En teoria no deberia haber mas include excepto los DtTypes necessarios

class Resenia;

#include "Resenia.h"
#include "DtFecha.h"
#include "Huesped.h"
#include <list>
#include <string>



using namespace std;
class Resenia;
class Reserva;
class Huesped;


class Estadia {
private:
    DtFecha checkIn, checkOut;
    Resenia *maybeResenia;
    string promo;
    Reserva *reserva;
    list<Huesped *> huespedes;
    list<
public:
    void finalizarActiva();

    Resenia *getResenia();

};


#endif //P4_ENTREGA_FINAL_ESTADIA_H
