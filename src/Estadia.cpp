
#include "Estadia.h"

void Estadia::finalizarActiva() {

}

Resenia *Estadia::getResenia() {
    return maybeResenia;
}

bool Estadia::hasReseniaSinResponder() {
    if (hasResenia()) {
        return !maybeResenia->isComentada();
    } else {
        return false;
    }
}

void Estadia::destruirAsociaciones() {}


bool Estadia::hasResenia() {
    return maybeResenia != nullptr;
}
