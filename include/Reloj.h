//
// Created by unzip on 07/06/22.
//

#ifndef P4_ENTREGA_FINAL_RELOJ_H
#define P4_ENTREGA_FINAL_RELOJ_H


class Reloj {
private:
    DTfecha fechaActual;
    Reloj instancia = nullptr;
    Reloj();
public:
    Reloj getInstance();
    DtFecha getFechaActual();
    void modificarFechaDeSistema(int, int, int, int);
};

};


#endif //P4_ENTREGA_FINAL_RELOJ_H
