
#ifndef P4_ENTREGA_FINAL_HABITACION_H
#define P4_ENTREGA_FINAL_HABITACION_H


#include "Hostal.h"
#include "Reserva.h"
#include "../datatypes/DtHabitacion.h"
#include "../datatypes/DtResenia.h"
#include "../datatypes/DtReserva.h"

#include <list>
#include <map>
#include <string>

using namespace std;

class Reserva;

class Hostal;

class Habitacion {
private:
    int numero;
    int precioPorNoche;
    int capacidad;
    Hostal *hostal;
    map<int,Reserva *> reservas;
public:
    Habitacion(int numero, int precioPorNoche, int capacidad);

    void setHostal(Hostal *hostalParameter);

    Hostal getHostal();

    int getPrecioPorNoche() const;

    DtHabitacion getDatos() const;

    list<DtReserva *> getReservasAsociadas(const string& email);

    list<DtResenia> getReseniasSinResponder();

    list<DtResenia> getResenias();

    int getCalificacionPromedio();

    bool checkIfCoincideHostal(Hostal *hostal);

    int getNumero() const;

    void addReserva(Reserva *pReserva);
};


#endif //P4_ENTREGA_FINAL_HABITACION_H