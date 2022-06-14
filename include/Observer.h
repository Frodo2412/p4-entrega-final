
#ifndef P4_ENTREGA_FINAL_OBSERVER_H
#define P4_ENTREGA_FINAL_OBSERVER_H

#include "../datatypes/DtNotificacion.h"

class Observer {
public:
    virtual void notify(DtNotificacion notif) = 0;
};


#endif //P4_ENTREGA_FINAL_OBSERVER_H
