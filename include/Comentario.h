
#ifndef P4_ENTREGA_FINAL_COMENTARIO_H
#define P4_ENTREGA_FINAL_COMENTARIO_H


#include <string>
#include "Resenia.h"
#include "../datatypes/DtComentario.h"
//En teoria no deberia haber mas include excepto los DtTypes necessarios
//No agregamos lo de puntero a reseña porque nunca lo usamos

using namespace std;

class Comentario {
private:
    string texto;
public:
    Comentario();

    explicit Comentario(string texto);

    string getTexto();

    DtComentario getDatos();
};

#endif //P4_ENTREGA_FINAL_COMENTARIO_H
