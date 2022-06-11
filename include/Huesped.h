
#ifndef P4_ENTREGA_FINAL_HUESPED_H
#define P4_ENTREGA_FINAL_HUESPED_H

#include "../datatypes/DtHuesped.h"
#include "Reserva.h"
#include "Usuario.h"
//Deberian estar los imports a mneos de los DT

#include <list>

using namespace std;

class Reserva;

class Huesped : public Usuario {
private:
    bool esFinger;
    list<Reserva *> reservas;

public:
    Huesped(string nombre, string email, string password, bool esFinger);

    ~Huesped();

    DtUsuario getDatos() override;

    void agregarReserva(Reserva *reserva);

    bool isMail(const string &mail);

    void finalizarReservaActiva();
};


#endif//P4_ENTREGA_FINAL_HUESPED_H
