
#ifndef P4_ENTREGA_FINAL_DTHUESPED_H
#define P4_ENTREGA_FINAL_DTHUESPED_H

#include "DtUsuario.h"

class DtHuesped : public DtUsuario {
private:
    bool esFinger;

public:
    DtHuesped(string nombre, string email, bool esFinger);

    bool getEsFinger() const;

    friend ostream &operator<<(ostream &os, const DtHuesped *huesped);

    ~DtHuesped() override;
};


#endif //P4_ENTREGA_FINAL_DTHUESPED_H
