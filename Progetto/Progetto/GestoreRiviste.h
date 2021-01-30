#ifndef GESTORERIVISTE_H
#define GESTORERIVISTE_H

#include "Conferenza.h"
#include "Rivista.h"
#include "Articolo.h"
#include <list>
#include <vector>
using namespace std;

class GestoreRiviste {

public:
    void aggiungiRivista(Rivista r);
    int sizeRiviste () const;
    bool rivistaValida (string acr, string vol) const;
    list<Rivista> listaRiviste() const;
    void annullaInserimento ();
    void aggiungiKeyRivista(string acr, string vol, string key);
    Rivista rivistaAcronimo (string acr) const;
    Rivista rivistaRiferimento (string acr, string vol);
    list<Rivista> rivisteSpecialistiche () const;





private:
    list<Rivista> riviste;
};



#endif // GESTORERIVISTE_H
