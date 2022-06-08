
#ifndef P4_ENTREGA_FINAL_DTHOSTALEXT_H
#define P4_ENTREGA_FINAL_DTHOSTALEXT_H

#include "DtResenia.h"
#include "DtHostal.h"

#include <string>
#include <list>

using std::string;

class DtHostalExt : public DtHostal {
private:
    list<DtResenia> resenias;
public:
    DtHostalExt(string nombre, string direccion, int calificacionPromedio, list<DtResenia> resenias);

    list<DtResenia> getResenias();
};


#endif //P4_ENTREGA_FINAL_DTHOSTALEXT_H
