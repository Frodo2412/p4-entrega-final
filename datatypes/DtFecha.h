
#ifndef P4_ENTREGA_FINAL_DTFECHA_H
#define P4_ENTREGA_FINAL_DTFECHA_H

#include <string>
#include <iostream>

using namespace std;

class DtFecha {
private:
    int hora;
    int dia;
    int mes;
    int anio;
public:
    DtFecha();

    DtFecha(int hora, int dia, int mes, int anio);

    int getHora() const;

    int getDia() const;

    int getMes() const;

    int getAnio() const;

    int operator-(DtFecha fecha) const;

    bool operator==(const DtFecha &rhs) const;

    friend ostream &operator<<(ostream &os, DtFecha fecha);
};


#endif //P4_ENTREGA_FINAL_DTFECHA_H
