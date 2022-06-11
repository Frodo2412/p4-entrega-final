//
// Created by unzip on 09/06/22.
//

#ifndef P4_ENTREGA_FINAL_CONTROLLERFACTORY_H
#define P4_ENTREGA_FINAL_CONTROLLERFACTORY_H


#include "HostalController.h"
#include "UsuarioController.h"
#include "ReservaController.h"
#include "NotificacionController.h"

class ControllerFactory {
private:
    static ControllerFactory* instance;
    ControllerFactory();
public:
    IUsuarioController* getUsuarioController();
    IHostalController* getHostalController();
    IReservaController* getReservaController();
    INotificacionController* getNotificacionController();
    ControllerFactory* getInstance();
};

#endif//P4_ENTREGA_FINAL_CONTROLLERFACTORY_H
