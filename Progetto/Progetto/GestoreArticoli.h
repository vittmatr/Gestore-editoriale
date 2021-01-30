#ifndef GESTOREARTICOLI_H
#define GESTOREARTICOLI_H

#include "Autore.h"
#include "Conferenza.h"
#include "Rivista.h"
#include "Articolo.h"
#include <list>
#include <vector>
using namespace std;

class GestoreArticoli {

public:
    void aggiungiArticolo (Articolo a);
    void aggiungiArticoloCorrelato (Articolo a);
    bool articoloNonDoppione (Articolo a, Articolo b) const;
    void aggiungiAutoreArticolo (Autore a);
    void aggiungiKeywordArticolo (string k);
    int sizeArticoli() const;
    bool idValido (string id) const;
    void annullaInserimento ();
    Articolo ultimoInserimento () const;
    Articolo ricercaID (string id) const;
    list<Articolo> listaArticoli() const;
    list<Articolo> listaArticoliConferenza (string acr, string luogo) const;
    list<Articolo> listaArticoliRivista (string acr, string volume) const;
    list<Articolo> listaArticoliKeyword (string key) const;
    list<Articolo> listaAutoriArticolo (string id) const;
    double mediaPrezzi(string idAutore) const;
    list<string> listaKeywordRedditizie () const;
    double guadagnoKeyword (string key) const;
    list<Articolo> prezzoAltoAutore (string id) const;
    list<Articolo> listaArticoliAutorePrezzo (string id) const;
    list<Articolo> articoliKeywordAnnoDecrescentePrezzoCrescente (string key) const;
    list<Articolo> articoliInfluenzati (Articolo A) const;




private:
    list<Articolo> articoli;
};


#endif // GESTOREARTICOLI_H
