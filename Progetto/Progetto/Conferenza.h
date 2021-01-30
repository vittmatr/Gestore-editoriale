#ifndef CONFERENZA_H
#define CONFERENZA_H


#include <iostream>
#include <string>
#include <list>
#include <QMainWindow>
using namespace std;

class Conferenza {

public:
    Conferenza () {}
    void setNome (string n) {nome=n;}
    void setAcronimo (string c) {acronimo=c;}
    void setLuogo (string l) {luogo=l;}
    void setData (string d) {data=d;}
    void aggiungiOrganizzatore (string o) {organizzatori.push_back(o);}
    void setPartecipanti (int n) {partecipanti=n;}
    void aggiungiKeyword (string key) {keywordCorrelate.push_back(key);}
    string getNome () const {return nome;}
    string getAcronimo() const {return acronimo;}
    string getLuogo() const {return luogo;}
    string getData() const {return data;}
    list<string> getKeywordCorrelate () const {return keywordCorrelate;}
    int getPartecipanti() const {return partecipanti;}
    list<string> getOrganizzatori () const {return organizzatori;}

    friend ostream& operator<<(ostream& o, const Conferenza& c)
    {
       o << "Conferenza \"" << c.nome << "\" (" << c.acronimo << ") con " << c.partecipanti << " partecipanti" << endl;
       o << "Presso: " << c.luogo << " in data: " << c.data;

        if (c.organizzatori.begin() !=  c.organizzatori.end())
            o << endl <<  "Organizzato da: ";
         for (auto i=c.organizzatori.begin(); i != c.organizzatori.end(); ++i){
              auto j=i;
              j++;
              if (j!=c.organizzatori.end())
              o  << *i << ", ";
              else
              o  << *i <<".";
          }

        if (c.keywordCorrelate.begin()!= c.keywordCorrelate.end()){
            o << endl << "Keyword : " ;
         for (auto key=c.keywordCorrelate.begin(); key != c.keywordCorrelate.end(); ++key){
               auto j=key;
               j++;
               if (j!=c.keywordCorrelate.end())
                o << *key << ", ";
               else
                   o << *key << ".";
           }
                                                                  }

        return o;

    }

    bool operator== (const Conferenza& c) const
    {
        return nome==c.nome && acronimo==c.acronimo && luogo==c.luogo && organizzatori==c.organizzatori && data==c.data && keywordCorrelate==c.keywordCorrelate && partecipanti==c.partecipanti;
    }

    bool operator!= (const Conferenza& c) const
    {
        return nome!=c.nome || acronimo!=c.acronimo || luogo!=c.luogo || organizzatori!=c.organizzatori || data!=c.data || keywordCorrelate!=c.keywordCorrelate || partecipanti!=c.partecipanti;
    }

private:
    string nome;
    string acronimo;
    string luogo;
    list<string> organizzatori;
    string data;
    int partecipanti;
    list<string> keywordCorrelate;


};




#endif // CONFERENZA_H
