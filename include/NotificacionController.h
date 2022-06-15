
#ifndef P4_ENTREGA_FINAL_NOTIFICACIONCONTROLLER_H
#define P4_ENTREGA_FINAL_NOTIFICACIONCONTROLLER_H

#include "../infrastructure/INotificacionController.h"
#include <list>


class NotificacionController : public INotificacionController {
private:
    list<Observer *> observers;
    Resenia *reseniaAux;
    Estadia *estadiaAux;
    Hostal *hostalAux;
    Comentario *comentarioAux;
    static NotificacionController *instancia;

    string mailAux;
    list<Resenia *> resenias;
public:
    void seleccionarEstadia(int codigoReserva) override;

    list<DtEmpleado> mostrarEmpleados() override;

    void suscribirANotificaciones(string email) override;

    list<DtNotificacion> consultaDeNotificaciones(
            string email) override;    //Cambio de tipo (no es void), en DC es DtResenia pero es mas sencillo un DtNotificacion
    void eliminarSubscripcion(string email) override;

    void notificar(DtNotificacion notif) override;

    Resenia *getResenia() override;

    Estadia *getEstadia() override;

    list<DtEstadia> mostrarEstadiasFinalizadas(string email) override;

    list<DtHostal> mostrarHostales() override;

    list<DtResenia> mostrarComentariosSinResponder(string email) override;

    void elegirComentario(int idReserva) override;

    void elegirHostal(string nombre) override;

    void enviarComentario(string comentario) override;

    void ingresarCalificacion(int calificacion, string comentario) override;

    void agregarObserver(Observer *observer) override;

    void eliminarObserver(Observer *observer) override;

    void notifyObservers(DtNotificacion notif) override;

    static NotificacionController *getInstance();
};


#endif//P4_ENTREGA_FINAL_NOTIFICACIONCONTROLLER_H
