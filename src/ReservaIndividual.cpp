
#include "ReservaIndividual.h"

bool ReservaIndividual::tieneHuespedAsociado(string email) {
    return huespedReservante->isMail(email);
}
