#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <iostream>
#include <string>
#include <list>
#include "Autore.h"
#include "Conferenza.h"
#include "Rivista.h"
using namespace std;

class Articolo {

public:
    void setID (string id) {identificativo=id;}
    void setTitolo (string t) {titolo=t;}
    void setPrezzo (double p) {prezzo=p;}
    void setNumeroPagine (int n) {numeroPagine=n;}
    void setConferenzaRiferimento (Conferenza c) {conferenzaRiferimento=c;}
    void setRivistaRiferimento (Rivista r) {rivistaRiferimento=r;}
    void aggiungiArticolo (Articolo a) {correlati.push_back(a);}
    void aggiungiAutore (Autore a) {autoriArticolo.push_back(a);}
    void aggiungiKeyword (string k) {keyword.push_back(k);}
    void aggiungiAnno (int a) {anno=a;}
    string getID () const {return identificativo;}
    string getTitolo () const {return titolo;}
    Rivista getRivistaRiferimento () const {return rivistaRiferimento;}
    Conferenza getConferenzaRiferimento() const {return conferenzaRiferimento;}
    int getNumeroPagine () const {return numeroPagine;}
    int getAnno () const {return anno;}
    list<Autore> getAutoriArticolo () const {return autoriArticolo;}
    list<string> getKeyword () const {return keyword;}
    double getPrezzo () const {return prezzo;}
    list<Articolo> getCorrelati () const {return correlati;}
    string getData () const
    {
        if (conferenzaRiferimento.getNome()!="")
            return conferenzaRiferimento.getData();
        else
            return rivistaRiferimento.getData();

    }

    friend ostream& operator<<(ostream& o, const Articolo& a)
    {
        o << "Titolo: \"" << a.titolo << "\" (id: " << a.identificativo << ") numero di pagine: " << a.numeroPagine << " di prezzo € " << a.prezzo;
        if (a.autoriArticolo.begin() != a.autoriArticolo.end()){
        o << endl << "Autori: ";
        for (auto i=a.autoriArticolo.begin(); i!=a.autoriArticolo.end(); ++i){
            auto j=i;
            j++;
            if (j!=a.autoriArticolo.end())
             o << (*i).getNome() << " " << (*i).getCognome() << ", ";
            else
             o << (*i).getNome() << " " << (*i).getCognome() <<".";
        }
                                                              }
        if (a.keyword.begin() != a.keyword.end()){
        o << endl << "Keyword: ";
        for (auto i=a.keyword.begin(); i!=a.keyword.end(); ++i){
            auto j=i;
            j++;
            if (j!=a.keyword.end())
             o << *i << ", ";
            else
             o << *i <<".";
        }
                                                               }
        if (a.correlati.begin() != a.correlati.end()){
        o << endl << "Articoli correlati: ";
        for (auto i=a.correlati.begin(); i!=a.correlati.end(); ++i){
            auto j=i;
            j++;
            if (j!=a.correlati.end())
             o << (*i).getTitolo() << " ,";
            else
             o << (*i).getTitolo() << ".";
        }
                                                               }
        if (a.conferenzaRiferimento.getNome()!="")
            o << endl << "(Relativo alla conferenza [" << a.conferenzaRiferimento.getNome() << "] anno: " << a.anno << ")";
        if (a.rivistaRiferimento.getNome()!="")
            o << endl << "(Relativo alla rivista [" << a.rivistaRiferimento.getNome() << "] anno: " << a.anno << ")";

        return o;
    }


    bool operator==(const Articolo& right) const {
        return identificativo==right.identificativo;
}

    bool operator!=(const Articolo& right) const {
        return identificativo!=right.identificativo;
    }


private:
    string identificativo;
    string titolo;
    int numeroPagine;
    list<Autore> autoriArticolo;
    list<string> keyword;
    double prezzo;
    list<Articolo> correlati;
    Conferenza conferenzaRiferimento;
    Rivista rivistaRiferimento;
    int anno;

};

#endif // ARTICOLO_H
