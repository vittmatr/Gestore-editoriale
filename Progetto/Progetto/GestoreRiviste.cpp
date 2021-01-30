#include "GestoreRiviste.h"
#include <list>
#include <iterator>
using namespace std;


void GestoreRiviste::aggiungiRivista(Rivista r)
{riviste.push_back(r);}

int GestoreRiviste::sizeRiviste () const
{return riviste.size();}

list<Rivista> GestoreRiviste::listaRiviste() const
{return riviste;}

bool GestoreRiviste:: rivistaValida (string acr, string vol) const  // semplice metodo per verificare la validità di una rivista
{
    for (auto i : riviste)
    {
        if (i.getAcronimo()==acr && i.getVolume()==vol && acr!="" && vol!="")
            return false;
    }
    return true;
}

void GestoreRiviste:: annullaInserimento ()
{
    if (riviste.size()>0)
        riviste.pop_back();

}

Rivista GestoreRiviste:: rivistaRiferimento (string acr, string vol) // restituisce la rivista che ha un certo acronimo e un certo volume
{
    Rivista nuovaRivista;
    for (auto c : riviste)
    {
        if (c.getAcronimo()==acr && c.getVolume()==vol)
            return c;
    }
    return nuovaRivista;
}

bool keywordValida (Rivista lista, string key)  // metodo che restituisce false quando una keyword è già presente, ciò permette di non inserire keyword duplicate
{
    for (auto k : lista.getKeywordCorrelate())
    {
        if (k==key)
            return false;
    }
    return true;
}

void GestoreRiviste:: aggiungiKeyRivista(string acr, string vol, string key) // sfruttando il metodo precedente viene aggiunta una keyword
{

    for (auto i=riviste.begin(); i!=riviste.end(); ++i)
    {
        if (keywordValida((*i),key) && (*i).getVolume()==vol && (*i).getAcronimo()==acr)
        (*i).aggiungiKeyword(key);
    }

}

vector<string> keywordRivista (Rivista r)  // metodo che restiruisce un vector con tutte le keyword contenute in una rivista, utile per il metodo delle riviste specialistiche
{
    vector<string> lista;

      for (auto k: r.getKeywordCorrelate())
     {
         lista.push_back(k);
      }

   return lista;
}

bool verificaRivistaSpecialistica (vector<string> R1, vector<string> R2)
{
    if (R2.size()<R1.size() || R2.size()==0 || R1.size()==0) // se R2 ha meno keyword di R1 abbiamo già la sicurezza che R1 non è specialistica
        return false;

    bool keyPresente=true;

    for (auto key_R1=R1.begin(); key_R1!=R1.end(); ++key_R1){
        keyPresente=false;
            for (auto key_R2=R2.begin(); key_R2!=R2.end(); ++key_R2){
                if ((*key_R1)==(*key_R2))
                    keyPresente=true;
            }
       if (!keyPresente)                                   // se anche una sola keyword non è presente la rivista non è sicuramente specialistica
           return false;
    }

        return true;
}

bool duplicatiSpecialisticaAssenti (list<Rivista> specialistiche, Rivista R1)  // metodo utile per evitare di inserire più volte una rivista specialistica nel metodo delle riviste specialistiche
{
    for (auto r: specialistiche)
    {
        if (R1==r)
            return false;
    }

    return true;
}

list<Rivista> GestoreRiviste:: rivisteSpecialistiche () const
{
    list<Rivista> specialistiche;
    for (auto R1: riviste){
        for (auto R2: riviste){
                if (R1!=R2 && verificaRivistaSpecialistica(keywordRivista(R1),keywordRivista(R2)) && duplicatiSpecialisticaAssenti(specialistiche, R1))  // sfruttando il metodo per non aggiungere duplicati e il metodo per verificare che la rivista sia specialistica vengono aggiunte le riviste che soddisfano i criteri
                    specialistiche.push_back(R1);
        }
    }

    return specialistiche;
}
