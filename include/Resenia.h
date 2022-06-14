
#ifndef P4_ENTREGA_FINAL_RESENIA_H
#define P4_ENTREGA_FINAL_RESENIA_H


#include "Comentario.h"
#include "DtFecha.h"
#include "DtResenia.h"
//#include "Estadia.h"
#include "Huesped.h"

//Deberia esta pronto los includes a menos del dt

class Comentario;

class Estadia;

class Resenia {
private:
    int calificacion;
    DtFecha fecha;
    string comentario;
    Comentario *maybeComentario;
//    Estadia *maybeEstadia;
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

//    void setEstadia(Estadia *estadia);

    bool isComentada();


};


#endif //P4_ENTREGA_FINAL_RESENIA_H
