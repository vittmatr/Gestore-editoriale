#ifndef GESTORECONFERENZE_H
#define GESTORECONFERENZE_H


#include "Autore.h"
#include "Conferenza.h"
#include "Rivista.h"
#include "Articolo.h"
#include <list>
using namespace std;

class GestoreConferenze {

public:
    void aggiungiConferenza (Conferenza c);
    void aggiungiOrganizzatore (string o);
    int sizeConferenze () const;
    list<Conferenza> listaConferenze() const;
    bool conferenzaValida (string acr, string luogo) const;
    void annullaInserimento ();
    void aggiungiKeyConferenza (string acr, string luogo, string key);
    Conferenza conferenzaRiferimento (string acr, string luogo) const;
    list<Conferenza> conferenzeSimili (Conferenza C) const;


private:
    list<Conferenza> conferenze;
};



#endif // GESTORECONFERENZE_H
