//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_INOTIFICACIONCONTROLLER_H
#define P4_ENTREGA_FINAL_INOTIFICACIONCONTROLLER_H

#include "DtNotificacion.h"
#include "Estadia.h"
#include "HostalController.h"
#include "Observer.h"
#include "Reloj.h"
#include "Resenia.h"
#include "ReservaController.h"
#include "UsuarioController.h"

#include <list>

class INotificacionController {
public:
    virtual list<DtEmpleado> mostrarEmpleados() = 0;
    virtual void suscribirANotificaciones(string email) = 0;
    virtual list<DtNotificacion>  consultaDeNotificaciones(string email) = 0;    //Cambio de tipo (no es void)
    virtual void eliminarSubscripcion(string email) = 0;
    virtual void notificar(DtNotificacion notif) = 0;
    virtual Resenia *getResenia() = 0;
    virtual Estadia *getEstadia() = 0;
    virtual list<DtEstadia> mostrarEstadiasFinalizadas(string email) = 0;
    virtual list<DtHostal> mostrarHostales() = 0;
    virtual list<DtResenia> mostrarComentariosSinResponder(string email) = 0;
    virtual void elegirComentario(int idReserva) = 0;
    virtual void elegirHostal(string nombre) = 0;
    virtual void enviarComentario(string comentario) = 0;
    virtual void ingresarCalificacion(int calificacion, string comentario) = 0;
    virtual void agregarObserver(Observer *observer) = 0;
    virtual void eliminarObserver(Observer *observer) = 0;
    virtual void notifyObservers(DtNotificacion notif) = 0;
    virtual list<DtResenia> getCalificaciones(Hostal hostal) = 0;
};

#endif//P4_ENTREGA_FINAL_INOTIFICACIONCONTROLLER_H
