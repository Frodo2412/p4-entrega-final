//
// Created by MontoroA on 6/6/2022.
//

#ifndef P4_ENTREGA_FINAL_DTFECHA_H
#define P4_ENTREGA_FINAL_DTFECHA_H

#include <string>

class DtFecha{
private:
    int hora;
    int dia;
    int mes;
    int anio;

public:
    DtFecha(int, int, int, int);
    ~DtFecha(){};

    int getHora();
    int getDia();
    int getMes();
    int getAnio();

    int operator-(DtFecha*);

    std::string format();
};


#endif //P4_ENTREGA_FINAL_DTFECHA_H
