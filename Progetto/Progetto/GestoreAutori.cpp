#include "GestoreAutori.h"
#include <list>
#include <iterator>
using namespace std;



void GestoreAutori::aggiungiAutore(Autore a)
{
    for (auto i=autori.begin(); i != autori.end(); ++i){
        for (auto j=i; j!= autori.end(); ++j)
        {
            if (i->getID()==j->getID() && i!=j)
                return ;

        }
    }
autori.push_back(a);
}

void GestoreAutori::aggiungiAffereza (string a)
{autori.back().aggiungiAfferenza(a);  }

int GestoreAutori::sizeAutori () const
{return autori.size();}

bool GestoreAutori:: idValido (string id) const // verifica che che l'identificativo non sia già stato utilizzato
{
    for (auto a : autori)
    {
        if (a.getID()==id)
            return false;
    }
    return true;
}

list<Autore> GestoreAutori::listaAutori () const
{return autori;}

Autore GestoreAutori::ricercaID (string id) const // restituisce l'autore con l'indentificativo corrispondente ad "id"
{
    Autore autoreCercato;
    for (auto a : autori)
    {
        if (a.getID()==id)
            autoreCercato=a;
    }
    return autoreCercato;
}

void GestoreAutori:: annullaInserimento()
{
    if (autori.size()>0)
        autori.pop_back();
}

