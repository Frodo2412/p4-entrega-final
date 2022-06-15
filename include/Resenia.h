
#ifndef P4_ENTREGA_FINAL_RESENIA_H
#define P4_ENTREGA_FINAL_RESENIA_H


#include "Comentario.h"
#include "DtFecha.h"
#include "DtResenia.h"
#include "DtNotificacion.h"
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
    Estadia *estadia;
public:
    Resenia();

    Resenia(int calificacion, DtFecha fecha, string comentario, Estadia* estadia);

    ~Resenia();

    DtResenia getDatos();

    int getCalificacion() const;

    void setEstadia(Estadia* estadia);

    DtFecha getFecha();

    string getComentario();

    void destruirAsociaciones();

    void setComentario(Comentario *respuesta);

    Estadia *getEstadia();

    bool isComentada();

    void setAutor(Huesped *aut);

//    bool isFrom(Hostal hostal);

    DtNotificacion getNotificacion();
};


#endif //P4_ENTREGA_FINAL_RESENIA_H
