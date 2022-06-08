
#ifndef P4_ENTREGA_FINAL_DTCOMENTARIO_H
#define P4_ENTREGA_FINAL_DTCOMENTARIO_H

#include <string>

using namespace std;

class DtComentario {
private:
    string texto;

public:
    explicit DtComentario(string texto);

    string getTexto();
};


#endif //P4_ENTREGA_FINAL_DTCOMENTARIO_H
