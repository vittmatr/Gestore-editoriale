#include <list>
#include "GestoreConferenze.h"
#include <iterator>
using namespace std;


void GestoreConferenze:: aggiungiConferenza (Conferenza c)
{conferenze.push_back(c);}

void GestoreConferenze:: aggiungiOrganizzatore (string o)
{conferenze.back().aggiungiOrganizzatore(o);}

int GestoreConferenze::sizeConferenze () const
{return conferenze.size();}

list<Conferenza> GestoreConferenze:: listaConferenze() const
{return conferenze;}

bool GestoreConferenze:: conferenzaValida (string acr, string luogo) const  // verifica che la conferenza esista tramite l'acronimo e il luogo
{
    for (auto i : conferenze)
    {
        if (i.getAcronimo()==acr && i.getLuogo()==luogo && acr!="" && luogo!="")
            return false;
    }
    return true;
}


void GestoreConferenze:: annullaInserimento ()
{
    if (conferenze.size()>0)
        conferenze.pop_back();
}

Conferenza GestoreConferenze:: conferenzaRiferimento (string acr, string luogo) const  // metodo che restituisce la conferenza che risponde ai parametri, presupponendo che la sua esistenza sia stata preventivamente verificata con il metodo "conferenzaValida"
{
    Conferenza nuovaConferenza;
    for (auto c : conferenze)
    {
        if (c.getAcronimo()==acr && c.getLuogo()==luogo)
            nuovaConferenza=c;
    }
    return nuovaConferenza;
}

bool keywordValida (Conferenza lista_keyword, string key)  // verifica che una keyword non sia già stata inserita
{
    for (auto k : lista_keyword.getKeywordCorrelate())
    {
        if (k==key)
            return false;
    }
    return true;
}

void GestoreConferenze:: aggiungiKeyConferenza (string acr, string luogo, string key)  // metodo per aggiungere una keyword a una specifica conferenza
{
    for (auto i=conferenze.begin(); i != conferenze.end(); ++i)
    {
        if (keywordValida((*i), key) && (*i).getAcronimo()==acr && (*i).getLuogo()==luogo)  // mediante il metodo "keywordValida" si evitano keyword doppione
            (*i).aggiungiKeyword(key);
    }
}

bool simili (Conferenza C1, Conferenza C2)
{
    int keywordRichieste;
    int keywordTrovate=0;

    if (C1.getKeywordCorrelate().size()==0 || C2.getKeywordCorrelate().size()==0)   // se una conferenza non ha keyword possiamo già dire con certezza che non possono essere simili
        return false;

    if (C1.getKeywordCorrelate().size()*80%100!=0){            // per gestire il caso in cui si debba arrotondare all'intero successivo
        keywordRichieste=C1.getKeywordCorrelate().size()*0.8;
        keywordRichieste++;
    } else
        keywordRichieste=C1.getKeywordCorrelate().size()*0.8;

    for (auto key_c1: C1.getKeywordCorrelate())
    {
        for (auto key_c2: C2.getKeywordCorrelate())
        {
            if (key_c1==key_c2)
                keywordTrovate++;
        }
    }

    if (keywordTrovate>=keywordRichieste)
        return true;
    else
        return false;

}

list<Conferenza> GestoreConferenze:: conferenzeSimili (Conferenza C) const  // metodo che restituisce le conferenze simili sfruttando il metodo "simili"
{
    list<Conferenza> confSimili;
    for (auto c1: conferenze)
    {
            if (C!=c1 && simili(C, c1))
                confSimili.push_back(c1);
    }

    return confSimili;
}
