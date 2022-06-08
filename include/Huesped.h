
#ifndef P4_ENTREGA_FINAL_HUESPED_H
#define P4_ENTREGA_FINAL_HUESPED_H


#include "Usuario.h"
#include "Reserva.h"
#include "DtHuesped.h"

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

    DtHuesped *getDatos() override;

    void agregarReserva(Reserva *reserva);

    bool isMail(const string &mail);

    void finalizarReservaActiva();
};


#endif //P4_ENTREGA_FINAL_HUESPED_H
