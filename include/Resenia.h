
#ifndef P4_ENTREGA_FINAL_RESENIA_H
#define P4_ENTREGA_FINAL_RESENIA_H


#include "DtFecha.h"
#include "Estadia.h"
#include "DtResenia.h"
#include "Comentario.h"

class Comentario;

class Resenia {
private:
    int calificacion;
    DtFecha fecha;
    string comentario;
    Comentario *maybeComentario;
    Estadia *maybeEstadia;
public:
    Resenia();

    Resenia(int calificacion, DtFecha fecha, string comentario);

    ~Resenia();

    DtResenia getDatos();

    int getCalificacion() const;

    DtFecha getFecha();

    string getComentario();

    void destruirAsociaciones();

    void setComentario(Comentario *respuesta);

    void setEstadia(Estadia *estadia);

    bool checkIfComentada();


};


#endif //P4_ENTREGA_FINAL_RESENIA_H
