
#ifndef P4_ENTREGA_FINAL_COMENTARIO_H
#define P4_ENTREGA_FINAL_COMENTARIO_H


#include <string>
#include "Resenia.h"
#include "DtComentario.h"

using namespace std;

class Comentario {
private:
    string texto;
    Resenia resenia;
public:
    Comentario(string texto, Resenia resenia);

    string getTexto();

    Resenia getResenia();

    DtComentario getDatos();
};

#endif //P4_ENTREGA_FINAL_COMENTARIO_H
