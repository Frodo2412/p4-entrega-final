
#ifndef P4_ENTREGA_FINAL_HUESPED_H
#define P4_ENTREGA_FINAL_HUESPED_H

#include "../datatypes/DtHuesped.h"
#include "Reserva.h"
#include "Usuario.h"
//Deberian estar los imports a mneos de los DT

#include <list>
#include <map>

using namespace std;

class Reserva;

class Huesped : public Usuario {
private:
    bool esFinger;
    map<int ,Reserva *> reservas;

public:
    Huesped(string nombre, string email, string password, bool esFinger);

    ~Huesped();

    DtUsuario getDatos() override;

    DtHuesped getDatosHuesped();

    void agregarReserva(Reserva *reserva);

    bool isMail(const string &mail);

    void finalizarReservaActiva();

    bool isFinger();
};


#endif//P4_ENTREGA_FINAL_HUESPED_H
