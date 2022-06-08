
#ifndef P4_ENTREGA_FINAL_HABITACION_H
#define P4_ENTREGA_FINAL_HABITACION_H


#include "Hostal.h"
#include "Reserva.h"
#include "DtHabitacion.h"
#include "DtResenia.h"
#include "DtReserva.h"

#include <list>
#include <string>

using namespace std;

class Habitacion {
private:
    int numero;
    int precioPorNoche;
    int capacidad;
    Hostal *hostal;
    list<Reserva *> reservas;
public:
    Habitacion(int numero, int precioPorNoche, int capacidad);

    void setHostal(Hostal *hostalParameter);

    Hostal getHostal();

    DtHabitacion getDatos() const;

    list<DtReserva> getReservasAsociadas(const string& email);

    list<DtResenia> getReseniasSinResponder();

    bool checkIfCoincideHostal(Hostal hostal);

};


#endif //P4_ENTREGA_FINAL_HABITACION_H
