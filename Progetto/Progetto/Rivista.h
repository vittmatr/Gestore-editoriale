#ifndef RIVISTA_H
#define RIVISTA_H

#include <string>
#include <iostream>
#include <list>
using namespace std;

class Rivista {

public:
    void setNome (string n) {nome=n;}
    void setAcronimo (string c) {acronimo=c;}
    void setData (string d) {data=d;}
    void setEditore (string e) {editore=e;}
    void setVolume (string v) {volume=v;}
    void aggiungiKeyword (string key) {keywordCorrelate.push_back(key);}
    string getNome () const {return nome;}
    string getAcronimo () const {return acronimo;}
    string getData () const {return data;}
    string getEditore () const {return editore;}
    string getVolume () const {return volume;}
    list<string> getKeywordCorrelate () const {return keywordCorrelate;}
    Rivista& riferimento () {return *this;}


    friend ostream& operator<<(ostream& o, const Rivista& r)
    {
        o << "Nome: \"" << r.nome << "\" (" << r.acronimo << ") " << endl;
        o << "Data: " << r.data << " , Editore: " << r.editore << " VOL: " << r.volume << ".";


        if (r.keywordCorrelate.begin()!= r.keywordCorrelate.end()){
        o << endl << "Keyword : " ;
        for (auto key=r.keywordCorrelate.begin(); key != r.keywordCorrelate.end(); ++key)
        {
            auto j=key;
            j++;
            if (j!=r.keywordCorrelate.end())
             o << *key << ", ";
            else
                o << *key << ".";
        }
                                                                  }

        return o;
    }

    bool operator== (const Rivista& r) const
    {
        return nome==r.nome && acronimo==r.acronimo && data==r.data && editore==r.editore && volume==r.volume && keywordCorrelate==r.keywordCorrelate;
    }

    bool operator!= (const Rivista& r) const
    {
        return nome!=r.nome || acronimo!=r.acronimo || data!=r.data || editore!=r.editore || volume!=r.volume || keywordCorrelate!=r.keywordCorrelate;
    }

private:
    string nome;
    string acronimo;
    string data;
    string editore;
    string volume;
    list<string> keywordCorrelate;

};

#endif // RIVISTA_H
