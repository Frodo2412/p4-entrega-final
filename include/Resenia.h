
#ifndef P4_ENTREGA_FINAL_RESENIA_H
#define P4_ENTREGA_FINAL_RESENIA_H


#include "../datatypes/DtFecha.h"
#include "../datatypes/DtResenia.h"
#include "../datatypes/DtNotificacion.h"
#include "Comentario.h"
#include "Huesped.h"
#include "Hostal.h"

class Huesped;

class Comentario;

class Estadia;

class Resenia {
private:
    int calificacion;
    DtFecha fecha;
    string comentario;
    Comentario *maybeComentario;
    Estadia *maybeEstadia;
    Huesped *autor;
public:
    Resenia();

    Resenia(int calificacion, DtFecha fecha, string comentario, Estadia *estadia);

    ~Resenia();

    DtResenia getDatos();

    void destruirAsociaciones();

    void setComentario(Comentario *respuesta);

    Estadia *getEstadia();

    bool isComentada();

    void setAutor(Huesped *pAutor);

    DtNotificacion getNotificacion();
};


#endif //P4_ENTREGA_FINAL_RESENIA_H
