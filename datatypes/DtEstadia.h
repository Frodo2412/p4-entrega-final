//
// Created by MontoroA on 7/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTESTADIA_H
#define P4_ENTREGA_FINAL_DTESTADIA_H

#include <string>
#include "DtFecha.h"

using std::string;

class DtEstadia{
private:
    string hostal;
    string huesped; //String de huesped? cual?
    int habitacion;
    DtFecha* checkIn;
    DtFecha* checkOut;
    string promo;

public:
    DtEstadia(string, string, int, DtFecha*, DtFecha*, string);
    ~DtEstadia(){};

    string getHostal();
    string getHuesped();
    int getHabitacion();
    DtFecha* getCheckIn();
    DtFecha* getCheckOut();
    string getPromo();

};


#endif //P4_ENTREGA_FINAL_DTESTADIA_H
