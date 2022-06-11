//
// Created by unzip on 09/06/22.
//

#include "ControllerFactory.h"

ControllerFactory * ControllerFactory::instance = nullptr;

ControllerFactory::ControllerFactory() = default;

IUsuarioController *ControllerFactory::getUsuarioController() {
    return UsuarioController::getInstance();
}
IHostalController *ControllerFactory::getHostalController() {
    return HostalController::getInstance();
}
IReservaController *ControllerFactory::getReservaController() {
    return ReservaController::getInstance();
}
INotificacionController *ControllerFactory::getNotificacionController() {
    return NotificacionController::getInstance();
}
ControllerFactory *ControllerFactory::getInstance() {
    if (instance == nullptr) {
        instance = new ControllerFactory();
    }
    return instance;
}
