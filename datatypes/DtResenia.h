
#ifndef P4_ENTREGA_FINAL_DTRESENIA_H
#define P4_ENTREGA_FINAL_DTRESENIA_H

#include "DtFecha.h"
#include <string>

using std::string;

class DtResenia {
private:
    int calificacion;
    string resenia;
    string comentario;
    DtFecha fecha;

public:
    DtResenia(int calificacion, string resenia, string comentario, DtFecha fecha);

    int getCalificacion() const;

    string getResenia();

    string getComentario();

    DtFecha getFecha();

    bool operator==(const DtResenia &rhs) const;
};

#endif //P4_ENTREGA_FINAL_DTRESENIA_H
