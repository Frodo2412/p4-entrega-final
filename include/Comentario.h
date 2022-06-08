//
// Created by unzip on 08/06/22.
//

#ifndef P4_ENTREGA_FINAL_COMENTARIO_H
#define P4_ENTREGA_FINAL_COMENTARIO_H


#include <string>
#include "DtComentario.h"
#include "Resenia.h"

using namespace std;

class Comentario {
private:
    string texto;
    Resenia *resenia;
public:
    explicit Comentario(string);

    DtComentario getDatos();

    void setReseña(Resenia *);

    string getTexto();

    Resenia *getResenia();

};


#endif //P4_ENTREGA_FINAL_COMENTARIO_H
