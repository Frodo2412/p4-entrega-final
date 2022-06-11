//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_NOTIFICACIONCONTROLLER_H
#define P4_ENTREGA_FINAL_NOTIFICACIONCONTROLLER_H

#include "../infrastructure/INotificacionController.h"

//TODO: Implementar
class NotificacionController : public INotificacionController {
private:
    list<Observer *> observers;
    Resenia *reseniaAux;
    Estadia *estadiaAux;
    Hostal *hostalAux;
    Comentario *comentarioAux;
    NotificacionController *instancia;

public:
    list<DtEmpleado> mostrarEmpleados() override;
    void suscribirANotificaciones(string email) override;
    void consultaDeNotificaciones(string email) override;
    void eliminarSubscripcion(string email) override;
    void notificar() override;
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
