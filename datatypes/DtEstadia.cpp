//
// Created by MontoroA on 7/6/2022.
//

#include "DtEstadia.h"

DtEstadia::DtEstadia(string host, string huesp, int hab, DtFecha* ChIn, DtFecha* ChOut, string prom){
    hostal = host;
    huesped = huesp;
    habitacion = hab;
    checkIn = ChIn;
    checkOut = ChOut;
    promo = prom;
}

string DtEstadia::getHostal(){
    return hostal;
}

string DtEstadia::getHuesped(){
    return huesped;
}

int DtEstadia::getHabitacion(){
    return habitacion;
}

DtFecha* DtEstadia::getCheckIn(){
    return checkIn;
}

DtFecha* DtEstadia::getCheckOut(){
    return checkOut;
}

string DtEstadia::getPromo(){
    return promo;
}