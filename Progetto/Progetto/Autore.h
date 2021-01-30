#ifndef AUTORE_H
#define AUTORE_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Autore {

public:
    Autore () {}
    Autore(string n, string c): nome(n), cognome(c) {}
    Autore(string id, string n, string c, list<string> a): identificativo (id), nome(n), cognome(c), afferenze (a) {}
    void setID (string id) {identificativo=id;}
    void setNome (string n) {nome=n;}
    void setCognome (string c) {cognome=c;}
    void aggiungiAfferenza (string a) {afferenze.push_back(a);}
    string getNome () const {return nome;}
    string getCognome() const {return cognome;}
    string getID() const {return identificativo;}
    list<string> getAfferenze () const {return afferenze;}



    friend ostream& operator<<(ostream& o, const Autore& a)
    {
        o << "Nome e Cognome: " << a.nome << " " << a.cognome;

        if (a.afferenze.begin() != a.afferenze.end())
            o << endl <<  "Ha lavorato con: ";

        for (auto i=a.afferenze.begin(); i!=a.afferenze.end(); ++i)
        {
            auto j=i;
            j++;
            if (j!=a.afferenze.end())
            o  << *i << ", ";
            else
            o  << *i << ".";
        }
        return o;
    }

private:
    string identificativo;
    string nome;
    string cognome;
    list<string> afferenze;


};



#endif // AUTORE_H
