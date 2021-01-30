#ifndef GESTORE_H
#define GESTORE_H

#include "Autore.h"
#include "Conferenza.h"
#include "Rivista.h"
#include "Articolo.h"
#include <list>
using namespace std;

class GestoreAutori {

public:
    void aggiungiAutore (Autore a);
    void aggiungiAffereza (string a);
    int sizeAutori () const;
    bool idValido (string id) const;
    Autore ricercaID (string id) const;
    list<Autore> listaAutori () const;
    void annullaInserimento ();


private:
    list<Autore> autori;
};


#endif // GESTORE_H
