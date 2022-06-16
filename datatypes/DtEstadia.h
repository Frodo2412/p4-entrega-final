
#ifndef P4_ENTREGA_FINAL_DTESTADIA_H
#define P4_ENTREGA_FINAL_DTESTADIA_H

#include <string>
#include "DtFecha.h"

using std::string;

class DtEstadia {
private:
    int codigo;
    string nombreHostal;
    string emailHuesped;
    int numeroHabitacion;
    DtFecha checkIn;
    DtFecha checkOut;
    string promo;

public:
    DtEstadia(string nombreHostal, string emailHuesped, int numeroHabitacion, DtFecha checkIn,
              DtFecha checkOut, string codigoPromo, int codigo);

    int getCodigo() const;

    string getHostal();

    string getHuesped();

    int getHabitacion() const;

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    string getPromo();

    friend ostream &operator<<(ostream &os, DtEstadia estadia);

};


#endif //P4_ENTREGA_FINAL_DTESTADIA_H
