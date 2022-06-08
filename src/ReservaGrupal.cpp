
#include "ReservaGrupal.h"

bool ReservaGrupal::tieneHuespedAsociado(string email) {
    for (auto huesped: huespedes)
        if (huesped->isMail(email))
            return true;
    return false;
}
