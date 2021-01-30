#include "GestoreArticoli.h"
#include <list>
#include <iterator>
using namespace std;


void GestoreArticoli::aggiungiArticolo (Articolo a)
{articoli.push_back(a);}

int GestoreArticoli::sizeArticoli() const
{return articoli.size();}

list<Articolo> GestoreArticoli::listaArticoli() const
{return articoli;}

bool GestoreArticoli::idValido (string id) const  // metodo che restituisce false se l'id è già stato utilizzato
{
    for (auto a : articoli)
    {
        if (a.getID()==id)
            return false;
    }
    return true;
}

void GestoreArticoli:: annullaInserimento() // annulla l'ultimo inserimento
{
    if (articoli.size()>0)
        articoli.pop_back();
}

Articolo GestoreArticoli:: ultimoInserimento() const
{
        return articoli.back();
}

Articolo GestoreArticoli::ricercaID (string id) const  // restituisce l'articolo con un certo id (l'utilizzo di questo metodo avviene dopo il controllo effettuato dalla funzione "idValido" quindi assumo che l'articolo esista)
{
    Articolo articoloCercato;
     for (auto a : articoli)
     {
         if (a.getID()==id)
             articoloCercato=a;
     }
     return articoloCercato;}


void GestoreArticoli:: aggiungiAutoreArticolo (Autore a) // aggiunge un autore all'ultimo articolo
{
    if (articoli.begin() != articoli.end())
      articoli.back().aggiungiAutore(a);
}
void GestoreArticoli:: aggiungiKeywordArticolo (string k) // aggiunge una keyword all'ultimo articolo
{
    if (articoli.begin() != articoli.end()){
            articoli.back().aggiungiKeyword(k);
    }
}

bool GestoreArticoli:: articoloNonDoppione (Articolo a, Articolo b) const // verifica che tra gli articoli correlati di 'b' non ci sia l'articolo 'a'
{
    for (auto art: b.getCorrelati())
    {
        if (art==a)
            return false;
    }

    return true;
}

void GestoreArticoli:: aggiungiArticoloCorrelato (Articolo a) // sfruttando il metodo precedente si aggiunge un articolo correlato
{
    if (articoli.begin() != articoli.end() && articoloNonDoppione(a,articoli.back()))
      articoli.back().aggiungiArticolo(a);
}

list<Articolo> GestoreArticoli:: listaArticoliConferenza (string acr, string luogo) const  // restituisce una lista con tutti gli articoli relativi a una conferenza
{
    list<Articolo> nuovaLista;
    for (auto a : articoli)
    {
        if (a.getConferenzaRiferimento().getAcronimo()==acr && acr!="" && a.getConferenzaRiferimento().getLuogo()==luogo && luogo!="")
            nuovaLista.push_back(a);
    }

    return nuovaLista;
}
list<Articolo> GestoreArticoli:: listaArticoliRivista (string acr, string volume) const // restituisce una lista con tutti gli articoli di una rivista
{
    list<Articolo> nuovaLista;
    for (auto a : articoli)
    {
        if (a.getRivistaRiferimento().getAcronimo()==acr && acr!="" && a.getRivistaRiferimento().getVolume()==volume && volume!="")
            nuovaLista.push_back(a);
    }

    return nuovaLista;
}
list<Articolo> GestoreArticoli:: listaArticoliKeyword (string key) const // metodo che restituisce una lista di articoli contenenti una certa keyword
{
    list<Articolo> nuovaLista;
    for (auto a : articoli)
    {
        for (auto k : a.getKeyword())
        {
            if (k==key){
                nuovaLista.push_back(a);
                break;}
        }
    }

    return nuovaLista;
}

list<Articolo> GestoreArticoli:: listaAutoriArticolo (string id) const  // metodo che restiuisce una lista contenente tutti gli articoli di un certo autore
{
    list<Articolo> nuovaLista;
    for (auto a : articoli)
    {
        for (auto autore : a.getAutoriArticolo())
        {
            if (autore.getID()==id){
                nuovaLista.push_back(a);
                break;}
        }
    }

    return nuovaLista;
}


double GestoreArticoli:: mediaPrezzi(string idAutore) const  // restitusce la media dei prezzi di un autore
{
    double media=0;
    for (auto articolo : listaAutoriArticolo(idAutore))         // genero una lista degli articoli di un certo autore in modo tale da non dover fare controlli sugli articoli
    {
        media+=articolo.getPrezzo();
    }

    if((listaAutoriArticolo(idAutore)).size()>0)
        return media/=(listaAutoriArticolo(idAutore)).size();
    else
        return media;

}

double GestoreArticoli:: guadagnoKeyword (string key) const  // restituisce il guadagno complessivo di una keyword
{
    double guadagno=0;
    for (auto articolo: listaArticoliKeyword(key))          // genero una lista di articoli con una certa keyword in modo tale da non dover fare eventuali controlli
    {
        guadagno+=articolo.getPrezzo();
    }
    return guadagno;
}

bool keywordNonDoppiona (list<string> keylist, string key)  // semplice metodo per verificare che una keyword non sia doppiona
{
    for (auto k: keylist)
    {
        if (k==key)
            return false;
    }

    return true;
}

list<string> GestoreArticoli:: listaKeywordRedditizie () const // metodo che restitusce una lista di keyword redditizie
{
    list<string> keywordRedditizie;
    string keywordMigliore = "NESSUN RISULTATO";
    double massimo=0;

    for (auto Articoli: listaArticoli())
    {
        for (auto key: Articoli.getKeyword())
        {
            if (guadagnoKeyword(key)>massimo)
            {
                massimo=guadagnoKeyword(key);
                keywordMigliore=key;
            }
        }

    }

    keywordRedditizie.push_back(keywordMigliore);  // a questo punto ho la certezza di avere la keyword migliore, quindi potrei solamente trovarne altre con lo stesso guadagno totale

    for (auto Articoli: listaArticoli())
    {
        for (auto key: Articoli.getKeyword())
        {
            if (guadagnoKeyword(key)==guadagnoKeyword(keywordMigliore))
            {
                if (keywordNonDoppiona(keywordRedditizie, key))             // mi assicuro che la keyword non sia doppiona
                    keywordRedditizie.push_back(key);
            }
        }

    }

    return keywordRedditizie;

}

list<Articolo> GestoreArticoli:: prezzoAltoAutore (string id) const  // metodo che restituisce gli articoli dal prezzo più alto o l'articolo nel caso fosse unico
{
    list<Articolo> nuovaLista;
    Articolo migliore;
    double min=0;

    for (auto p: listaAutoriArticolo(id))
    {
        if (p.getPrezzo()>min)
        {
            min = p.getPrezzo();
            migliore = p;
        }
    }

    // adesso ho un articolo con il prezzo più alto, posso solamente trovarne altri con lo stesso prezzo

    for (auto p: listaAutoriArticolo(id))
    {
        if (p.getPrezzo()==migliore.getPrezzo())
        {
            nuovaLista.push_back(p);
        }
    }

    return nuovaLista;

}

bool precede (Articolo a1, Articolo a2)             // metodo per sfruttare il sort di "listaArticoliAutorePrezzo"
{    return a1.getPrezzo() < a2.getPrezzo();    }

list<Articolo> GestoreArticoli:: listaArticoliAutorePrezzo (string id) const        // metodo che restituisce gli articoli di un autore ordinati per prezzo crescente
{
    list<Articolo> nuovaLista = listaAutoriArticolo(id);                            // avendo già un metodo che genera una lista di articoli di un autore è immediata la soluzione
    nuovaLista.sort(precede);
    return nuovaLista;
}


bool precedeAnnoDecrescente (Articolo a1, Articolo a2)  // metodo per sfruttare il sort di "articoliKeywordAnnoDecrescentePrezzoCrescente"
{
    if (a1.getAnno() != a2.getAnno())
        return a1.getAnno() > a2.getAnno();
    if (a1.getPrezzo() != a2.getPrezzo())
        return a1.getPrezzo() < a2.getPrezzo();
    return a1.getAutoriArticolo().front().getCognome() < a2.getAutoriArticolo().front().getCognome();


}

list<Articolo> GestoreArticoli:: articoliKeywordAnnoDecrescentePrezzoCrescente (string key) const  // metodo che restitusce umna lista che segue questo ordine: anno decrescente, in caso di anno uguale si ordina per prezzo crescente, altrimenti per cognome
{
    list<Articolo> nuovaLista = listaArticoliKeyword(key);
    nuovaLista.sort(precedeAnnoDecrescente);
    return nuovaLista;
}


bool influenzaDiretta (Articolo A, Articolo B) // questa funzione sarà utilizzata per verificare il caso in cui un articolo B è influenzato da un articolo A senza ulteriori condizioni
{
    if (A==B)
        return false;
    for (auto correlato_b: B.getCorrelati())
    {
        if (correlato_b==A &&  B.getData()>A.getData())
            return true;
    }

    return false;
}

bool influenzaIndiretta (list<Articolo> listaArticoli, Articolo A, Articolo B)  // metodo più elaborato del precedente, serve a verificare che siano presenti delle influenze indirette (viene invocata solo se non viene trovata un'influenza diretta per evitare una ricerca inutile e dispendiosa)
{
    vector<Articolo> influenzati;
    for (auto C: listaArticoli)
    {
        if (influenzaDiretta(A,C))          // verifico prima ogni articolo influenzato direttamente con un articolo A
            influenzati.push_back(C);
    }

    for (unsigned i=0; i<influenzati.size(); i++)
    {
        if (influenzaDiretta(influenzati[i],B))     // verifico che gli articoli influenzati da A possano aver influenzato B
            return true;
    }

    return false;

}

list<Articolo> GestoreArticoli:: articoliInfluenzati (Articolo A) const     // metodo che restituscie gli articoli influenzati da un determianto articolo
{
    list<Articolo> influenzati;
    for (auto art: articoli)
    {
        if (influenzaDiretta(A,art))
            influenzati.push_back(art);
        else if (influenzaIndiretta(articoli, A, art))          // invocata solo se non è soddisfatto il primo if per evitare una ricerca dispendiosa
            influenzati.push_back(art);
    }

    return influenzati;
}

