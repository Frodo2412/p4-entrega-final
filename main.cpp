#include "DtFecha.h"
#include "DtComentario.h"
#include "DtEmpleado.h"
#include "DtEstadia.h"
#include "DtHabitacion.h"
#include "DtHostal.h"
#include "DtHostalExt.h"
#include "DtHuesped.h"
#include "DtNotificacion.h"
#include "DtReserva.h"
#include "DtReservaGrupal.h"
#include "DtReservaIndividual.h"

#include <iostream>

using namespace std;

int main() {

    cout << " - DtFecha:" << endl;
    DtFecha fecha(1, 1, 1, 1901);
    cout << fecha << endl;

    cout << " - DtComentario:" << endl;
    DtComentario comentario("Hola Mundo");
    cout << comentario.getTexto() << endl;

    cout << " - DtEmpleado:" << endl;
    DtEmpleado empleado("Juan", "juan@gmail.com", DtCargo::Administracion);
    cout << empleado.getNombre() << endl;
    cout << empleado.getEmail() << endl;
    cout << empleado.getCargo() << endl;

    cout << " - DtEstadia:" << endl;
    DtEstadia estadia("Hostal", "juan@gmail.com", 1, DtFecha(1, 1, 1, 1901), DtFecha(1, 1, 1, 1901), "Promo");
    cout << estadia.getHostal() << endl;
    cout << estadia.getHuesped() << endl;
    cout << estadia.getHabitacion() << endl;
    cout << estadia.getCheckIn() << endl;
    cout << estadia.getCheckOut() << endl;
    cout << estadia.getPromo() << endl;

    cout << " - DtHabitacion" << endl;
    DtHabitacion habitacion(1, 1, 1);
    cout << habitacion.getNumero() << endl;
    cout << habitacion.getCapacidad() << endl;
    cout << habitacion.getPrecio() << endl;

    cout << " - DtHostal" << endl;
    DtHostal hostal("Hostal", "El Viejo Pancho 1234", 3);
    cout << hostal.getNombre() << endl;
    cout << hostal.getDireccion() << endl;
    cout << hostal.getCalificacionProm() << endl;

    DtResenia resenia1(1, "Hola", "Juan", DtFecha(1, 1, 1, 1901)),
            resenia2(2, "Hola", "Juan", DtFecha(1, 1, 1, 1901)),
            resenia3(3, "Hola", "Juan", DtFecha(1, 1, 1, 1901));
    list<DtResenia> resenias({resenia1, resenia2, resenia3});
    cout << " - DtHostalExt" << endl;
    DtHostalExt hostalExt("HostalExt", "El Viejo Pancho 1234", 3, resenias);
    cout << hostal.getNombre() << endl;
    cout << hostal.getDireccion() << endl;
    cout << hostal.getCalificacionProm() << endl;

    cout << " - DtHuesped:" << endl;
    DtHuesped huesped("Pedro", "pedro@gmail.com", true);
    cout << huesped.getNombre() << endl;
    cout << huesped.getEmail() << endl;
    cout << huesped.getEsFinger() << endl;

    cout << " - DtNotificacion:" << endl;
    DtNotificacion notificacion(1, DtFecha(1, 1, 1, 1901), "Estaba rica la torta", "Noo en que te sentaste", "Pedro");
    cout << notificacion.getCalificacion() << endl;
    cout << notificacion.getFecha() << endl;
    cout << notificacion.getResenia() << endl;
    cout << notificacion.getComentario() << endl;
    cout << notificacion.getAutor() << endl;

    cout << " - DtResenia:" << endl;
    DtResenia resenia(1, "Hola", "Juan", DtFecha(1, 1, 1, 1901));
    cout << resenia.getCalificacion() << endl;
    cout << resenia.getResenia() << endl;
    cout << resenia.getComentario() << endl;
    cout << resenia.getFecha() << endl;

    cout << " - DtReserva:" << endl;
    DtReserva reserva(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1);
    cout << reserva.getCodigo() << endl;
    cout << reserva.getCheckIn() << endl;
    cout << reserva.getCheckOut() << endl;
    cout << reserva.getEstado() << endl;
    cout << reserva.getCosto() << endl;

    cout << " - DtReservaGrupal:" << endl;
    DtReservaGrupal reservaGrupal(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1, 1);
    cout << reservaGrupal.getCodigo() << endl;
    cout << reservaGrupal.getCheckIn() << endl;
    cout << reservaGrupal.getCheckOut() << endl;
    cout << reservaGrupal.getEstado() << endl;
    cout << reservaGrupal.getCosto() << endl;
    cout << reservaGrupal.getCantidadHuespedes() << endl;

    cout << " - DtReservaIndividual:" << endl;
    DtReservaIndividual reservaIndividual(1, DtFecha(1, 1, 1, 1901), DtFecha(2, 1, 1, 1901), DtEstado::Abierta, 1);
    cout << reservaIndividual.getCodigo() << endl;
    cout << reservaIndividual.getCheckIn() << endl;
    cout << reservaIndividual.getCheckOut() << endl;
    cout << reservaIndividual.getEstado() << endl;
    cout << reservaIndividual.getCosto() << endl;

    cout << " - DtUsuario:" << endl;
    DtUsuario usuario("Juan", "juan@gmail.com");
    cout << usuario.getNombre() << endl;
    cout << usuario.getEmail() << endl;


    return 0;
}