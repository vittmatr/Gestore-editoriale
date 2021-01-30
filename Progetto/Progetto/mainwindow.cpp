#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Autore.h"
#include "Conferenza.h"
#include "Rivista.h"
#include "Articolo.h"
#include "GestoreAutori.h"
#include "GestoreConferenze.h"
#include "GestoreRiviste.h"
#include "GestoreArticoli.h"
#include <string>
#include <sstream>
#include <list>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap logounical (":/img/img/logounical.png");
    ui->LOGOUNICAL->setPixmap(logounical);
    QPixmap freccia (":/img/img/freccia.png");
    QPixmap sezionerapida (":/img/img/SezioneRapida.png");
    QPixmap sezionerapida2 (":/img/img/sezioneRapida2.png");
    QPixmap sezionegestione (":/img/img/sezionegestione.png");
    QPixmap sezionegestione2 (":/img/img/sezionegestione2.png");
    QPixmap homePage (":/img/img/homepage.png");
    QPixmap homePage2 (":/img/img/homepage2.png");
    QPixmap inserimentoDati (":/img/img/inserimento_dati.png");
    ui->freccia->setPixmap(freccia);
    ui->LOGOUNICAL_2->setPixmap(logounical);
    ui->freccia_2->setPixmap(freccia);
    ui->SezioneRapida->setPixmap(sezionerapida);
    ui->SezioneRapida_2->setPixmap(sezionerapida2);
    ui->sezione_gestione->setPixmap(sezionegestione);
    ui->sezione_gestione2->setPixmap(sezionegestione2);
    ui->homepage->setPixmap(homePage);
    ui->inserimentoDati1->setPixmap(inserimentoDati);
    ui->inserimentoDati2->setPixmap(inserimentoDati);
    ui->inserimentoDati3->setPixmap(inserimentoDati);
    ui->inserimentoDati4->setPixmap(inserimentoDati);
    ui->bottoneGestione->setToolTip("Passa alla sezione della gestione");
    ui->bottoneInserimento->setToolTip("Passa alla sezione dell'inserimento dati");

    connect(ui->altreOperazioni, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->altreOperazioni_2, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->altreOperazioni_3, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->altreOperazioni_4, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida1, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida2, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida3, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida4, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida5, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->sezione_rapida6, &QPushButton::clicked, this, &MainWindow::on_altreOperazioni);
    connect(ui->homeInserimento, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_2, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_2, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_3, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_3, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_4, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_4, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_5, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_5, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeGestore_6, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_6, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_7, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_7, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_8, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_8, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_9, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_9, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_10, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_10, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->homeGestore_11, &QPushButton::clicked, this, &MainWindow::on_backGestore);
    connect(ui->homeInserimento_11, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->home_inserimento, &QPushButton::clicked, this, &MainWindow::on_backInserimento);
    connect(ui->home_gestione, &QPushButton::clicked, this, &MainWindow::on_backGestore);


    Articoli = new GestoreArticoli;
    Conferenze = new GestoreConferenze;
    Autori = new GestoreAutori;
    Riviste = new GestoreRiviste;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete Articoli;
    delete Conferenze;
    delete Autori;
    delete Riviste;
}

void MainWindow:: on_backInserimento()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneInserimento);
}

void MainWindow:: on_backGestore()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneGestione);
}

void MainWindow:: on_altreOperazioni()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneRapida);
}

void MainWindow::on_bottoneAutore_clicked()  // aggiunta di un autore
{
    QString nameAutore =  ui->nomeAutore->displayText();
    QString surnameAutore =  ui->cognomeAutore->displayText();
    QString IDAutore =  ui->idAutore->displayText();

    ui->listaAut->clear();

    Autore nuovo;
    nuovo.setNome(nameAutore.toStdString());
    nuovo.setCognome(surnameAutore.toStdString());
    nuovo.setID(IDAutore.toStdString());

    if (Autori->idValido(IDAutore.toStdString())){
    Autori->aggiungiAutore(nuovo);

    QString stampa = QString::number (Autori->sizeAutori()) + ") " + nameAutore + " " + surnameAutore + " " + IDAutore;

    ui->nomeAutore->clear();
    ui->cognomeAutore->clear();
    ui->idAutore->clear();

    ui->listaAut->addItem(stampa);
    ui->listaAutori_2->addItem(QString::number (Autori->sizeAutori()) + ") "  + surnameAutore + " [ID: " + IDAutore + "]");
    }
    else
    { QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un identificativo diverso!", QMessageBox::Ok, this);
        messaggio.exec();}

}

void MainWindow::on_bottoneAfferenza_clicked()  // aggiunta afferenza a un autore
{
    QString aff = ui->afferenza->displayText();

    if (Autori->sizeAutori()==0){
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Devi prima inserire un autore per aggiungere l'afferenza!", QMessageBox::Ok, this);
        messaggio.exec();}
    else if (aff=="") {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un'afferenza!", QMessageBox::Ok, this);
        messaggio.exec();}
    else
         {
         Autori->aggiungiAffereza(aff.toStdString());
         ui->afferenza->clear();
         }

}

void MainWindow::on_bottoneConferenze_clicked()     // aggiunta conferenza
{
    QString nomeConf = ui->nomeConferenza->displayText();
    QString acronimoConf = ui->acronimoConferenza->displayText();
    QString luogoConf = ui->luogoConferenza->displayText();

    ui->listaOrg->clear();

    Conferenza nuovaConferenza;
    nuovaConferenza.setNome(nomeConf.toStdString());
    nuovaConferenza.setAcronimo(acronimoConf.toStdString());
    nuovaConferenza.setLuogo(luogoConf.toStdString());
    QString date = (ui->dataConferenza->selectedDate()).toString(Qt::DateFormat::ISODate);
    nuovaConferenza.setData(date.toStdString());
    nuovaConferenza.setPartecipanti(ui->numeroPartecipanti->value());
    if (Conferenze->conferenzaValida(nuovaConferenza.getAcronimo(), nuovaConferenza.getLuogo()))
    Conferenze->aggiungiConferenza(nuovaConferenza);
    else {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile inserire " + QString::fromStdString(nuovaConferenza.getNome()) + " perché la conferenza esiste già.", QMessageBox::Ok, this);
        messaggio.exec();
             }

    QString stampa = QString::number (Conferenze->sizeConferenze()) + ") " + nomeConf + " " + acronimoConf + " presso " + luogoConf + " n. Partecipanti: " + QString::number(ui->numeroPartecipanti->value()) + " in data " + date;
    ui->listaOrg->addItem(stampa);
    ui->listaRapidaConferenze->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + nomeConf + " [" + acronimoConf + "] presso " + luogoConf);
    ui->listaRapidaConferenze_2->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + nomeConf + " [" + acronimoConf + "] presso " + luogoConf);
    ui->listaRapidaConferenze_3->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + nomeConf + " [" + acronimoConf + "] presso " + luogoConf);
    ui->nomeConferenza->clear();
    ui->luogoConferenza->clear();
    ui->acronimoConferenza->clear();
    ui->numeroPartecipanti->setValue(0);

}

void MainWindow::on_bottoneOrganizzatori_clicked()      // aggiunta organizzatore conferenza
{
    QString organizzatore = ui->organizzatore->displayText();
    if (Conferenze->sizeConferenze()==0){
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Devi prima inserire una conferenza per aggiungere un organizzatore!", QMessageBox::Ok, this);
        messaggio.exec();}
    else if (organizzatore=="") {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un organizzatore!", QMessageBox::Ok, this);
        messaggio.exec();}
    else
         {
         Conferenze->aggiungiOrganizzatore(organizzatore.toStdString());
         ui->organizzatore->clear();
         }

}


void MainWindow::on_bottoneRivista_clicked()        // aggiunta di una rivista
{

    Rivista nuovaRivista;
    nuovaRivista.setNome((ui->nomeRivista->displayText()).toStdString());
    nuovaRivista.setAcronimo((ui->acronimoRivista->displayText()).toStdString());
    nuovaRivista.setEditore((ui->editoreRivista->displayText()).toStdString());
    QString date = (ui->dataRivista->selectedDate()).toString(Qt::DateFormat::ISODate);
    nuovaRivista.setData(date.toStdString());
    nuovaRivista.setVolume((ui->volumeRivista->displayText()).toStdString());
    if (Riviste->rivistaValida(nuovaRivista.getVolume(), nuovaRivista.getAcronimo()))
    Riviste->aggiungiRivista(nuovaRivista);
    else {
            QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile inserire " + QString::fromStdString(nuovaRivista.getNome()) + " perché la rivista esiste già!", QMessageBox::Ok, this);
            messaggio.exec();
             }

    QString stampa = QString::number (Riviste->sizeRiviste()) + ") " + ui->nomeRivista->displayText() + " " + ui->acronimoRivista->displayText() + " " + ui->editoreRivista->displayText() + " (vol." + ui->volumeRivista->displayText() + ") " + date;
      ui->listaRivista->addItem(stampa);
      ui->listaRapidaRiviste->addItem(QString::number (Riviste->sizeRiviste()) + ") " + ui->nomeRivista->displayText() + " " + ui->acronimoRivista->displayText() + " vol.[" + ui->volumeRivista->displayText() + "] ");
      ui->listaRapidaRiviste_2->addItem(QString::number (Riviste->sizeRiviste()) + ") " + ui->nomeRivista->displayText() + " " + ui->acronimoRivista->displayText() + " vol.[" + ui->volumeRivista->displayText() + "] ");
      ui->nomeRivista->clear();
      ui->acronimoRivista->clear();
      ui->editoreRivista->clear();
      ui->volumeRivista->clear();


}

void MainWindow::on_aggiornaAutori_clicked()
{
    ui->listaAggiornaAutori->clear();
    int index = 1;
    for (auto a : Autori->listaAutori())
    {
        stringstream stream;
        stream << a;
        string str = stream.str();
        ui->listaAggiornaAutori->addItem(QString::number(index) + ") " + QString::fromStdString(str));
        index++;
    }
}

void MainWindow::on_aggiornaConferenze_clicked()
{
    ui->listaAggiornataConferenze->clear();
    int index = 1;
    for (auto c : Conferenze->listaConferenze())
    {
        stringstream stream;
        stream << c;
        string str = stream.str();
        ui->listaAggiornataConferenze->addItem(QString::number(index) + ") " + QString::fromStdString(str));
        index++;
    }
}

void MainWindow::on_aggiornaRiviste_clicked()
{
    ui->listaAggiornamentoRiviste->clear();
    int index = 1;
    for (auto c : Riviste->listaRiviste())
    {
        stringstream stream;
        stream << c;
        string str = stream.str();
        ui->listaAggiornamentoRiviste->addItem(QString::number(index) + ") " + QString::fromStdString(str));
        index++;
    }
}

int anno (string data)          // metodo per estrarre l'anno da una data
{
    int annoInt = stoi (data);
    return annoInt;
}


void MainWindow::on_bottoneArticolo_clicked()       // aggiunta di un articolo
{

    if ((ui->identificativoArticolo->displayText()).toStdString()=="")
    {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un identificativo!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else if (((ui->rivistaRiferimentoAcronimo->displayText()).toStdString()=="" && (ui->rivistaRiferimentoVolume->displayText()).toStdString()=="") && ((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString()=="" && (ui->conferenzaRiferimentoLuogo->displayText()).toStdString()==""))
    {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un riferimento a una rivista o una conferenza!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else if (((ui->rivistaRiferimentoAcronimo->displayText()).toStdString()!="" || (ui->rivistaRiferimentoVolume->displayText()).toStdString()!="") &&  ((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString()!="" || (ui->conferenzaRiferimentoLuogo->displayText()).toStdString()!=""))
    {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci solamente una rivista o una conferenza!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else if (Conferenze->conferenzaValida((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString(),(ui->conferenzaRiferimentoLuogo->displayText()).toStdString()) && Riviste->rivistaValida((ui->rivistaRiferimentoAcronimo->displayText()).toStdString(),(ui->rivistaRiferimentoVolume->displayText()).toStdString()))
    {
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Nessuna conferenza o rivista trovata!", QMessageBox::Ok, this);
        messaggio.exec();
     }
   else if (Articoli->idValido((ui->identificativoArticolo->displayText()).toStdString())){
        Articolo nuovoArticolo;
        ui->listaArticoli->clear();
        nuovoArticolo.setTitolo((ui->titoloArticolo->displayText()).toStdString());
        nuovoArticolo.setID((ui->identificativoArticolo->displayText()).toStdString());

        if (!Conferenze->conferenzaValida((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString(),(ui->conferenzaRiferimentoLuogo->displayText()).toStdString())){
              nuovoArticolo.setConferenzaRiferimento(Conferenze->conferenzaRiferimento((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString(),(ui->conferenzaRiferimentoLuogo->displayText()).toStdString()));
              nuovoArticolo.aggiungiAnno(anno(Conferenze->conferenzaRiferimento((ui->conferenzaRiferimentoAcronimo->displayText()).toStdString(),(ui->conferenzaRiferimentoLuogo->displayText()).toStdString()).getData()));
              acronimoConferenza=ui->conferenzaRiferimentoAcronimo->displayText();
              luogoConferenza=ui->conferenzaRiferimentoLuogo->displayText();
              acronimoRivista="";
              volumeRivista="";
        }
        if (!Riviste->rivistaValida((ui->rivistaRiferimentoAcronimo->displayText()).toStdString(),(ui->rivistaRiferimentoVolume->displayText()).toStdString())){
              nuovoArticolo.setRivistaRiferimento(Riviste->rivistaRiferimento((ui->rivistaRiferimentoAcronimo->displayText()).toStdString(),(ui->rivistaRiferimentoVolume->displayText()).toStdString()));
              nuovoArticolo.aggiungiAnno(anno(Riviste->rivistaRiferimento((ui->rivistaRiferimentoAcronimo->displayText()).toStdString(),(ui->rivistaRiferimentoVolume->displayText()).toStdString()).getData()));
              acronimoRivista=ui->rivistaRiferimentoAcronimo->displayText();
              volumeRivista=ui->rivistaRiferimentoVolume->displayText();
              acronimoConferenza="";
              luogoConferenza="";
        }
        nuovoArticolo.setNumeroPagine(ui->numeroPagineArticolo->value());
        nuovoArticolo.setPrezzo(ui->prezzoArticolo->value());
        Articoli->aggiungiArticolo(nuovoArticolo);
        ui->listaArticoli->addItem(ui->identificativoArticolo->displayText());
        ui->listaRapidaArticoli->addItem(QString::number (Articoli->sizeArticoli()) + ") ["  + QString::fromStdString(nuovoArticolo.getTitolo()) + "] ID: " + QString::fromStdString(nuovoArticolo.getID()) );
        ui->titoloArticolo->clear();
        ui->identificativoArticolo->clear();
        ui->conferenzaRiferimentoAcronimo->clear();
        ui->rivistaRiferimentoAcronimo->clear();
        ui->conferenzaRiferimentoLuogo->clear();
        ui->rivistaRiferimentoVolume->clear();
        ui->numeroPagineArticolo->setValue(0);
        ui->prezzoArticolo->setValue(0.0);
    }
  else
    {
       QMessageBox messaggio (QMessageBox::Critical, "Errore", "L'articolo non può avere un ID uguale ad un'altro!", QMessageBox::Ok, this);
       messaggio.exec();
    }


}


void MainWindow::on_bottoneOkAutori_clicked()  //aggiunge un autore a un articolo
{
    if (Articoli->sizeArticoli()==0){
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un articolo!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else if (!Autori->idValido((ui->aggiuntaAutoreArticolo->displayText()).toStdString())){
        Articoli->aggiungiAutoreArticolo(Autori->ricercaID((ui->aggiuntaAutoreArticolo->displayText()).toStdString()));
        ui->aggiuntaAutoreArticolo->clear();
    }
    else{
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "L'autore non esiste!", QMessageBox::Ok, this);
        messaggio.exec();
     }

}

bool listaValida (vector<string> v, string key)     // metodo per non aggiungere keyword doppione
{
    for (unsigned i=0; i<v.size(); i++){
        if (v[i]==key)
            return false;
    }
    return true;
}

void MainWindow::on_bottoneOkKeyword_clicked()
{
    if (Articoli->sizeArticoli()==0){
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un articolo!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else
    {
        Articoli->aggiungiKeywordArticolo((ui->aggiuntaKeyword->displayText()).toStdString());
        Riviste->aggiungiKeyRivista(acronimoRivista.toStdString(), volumeRivista.toStdString(), (ui->aggiuntaKeyword->displayText()).toStdString());
        Conferenze->aggiungiKeyConferenza(acronimoConferenza.toStdString(), luogoConferenza.toStdString(), (ui->aggiuntaKeyword->displayText()).toStdString());
        if (listaValida(listaRapidaKey, (ui->aggiuntaKeyword->displayText()).toStdString())){
        ui->listaRapidaKeyword->addItem(ui->aggiuntaKeyword->displayText());
        ui->listaRapidaKeyword_2->addItem(ui->aggiuntaKeyword->displayText());
        listaRapidaKey.push_back((ui->aggiuntaKeyword->displayText()).toStdString());
        }

    }

    ui->aggiuntaKeyword->clear();
}


void MainWindow::on_bottoneArticoloCorrelato_clicked()
{
    if (Articoli->sizeArticoli()==0){
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "Inserisci un articolo!", QMessageBox::Ok, this);
        messaggio.exec();
     }
    else if (!Articoli->idValido((ui->aggiuntaArticoloCorrelato->displayText()).toStdString())){
        Articoli->aggiungiArticoloCorrelato(Articoli->ricercaID((ui->aggiuntaArticoloCorrelato->displayText()).toStdString()));
        ui->aggiuntaArticoloCorrelato->clear();
    }
    else{
        QMessageBox messaggio (QMessageBox::Critical, "Errore", "L'articolo non esiste!", QMessageBox::Ok, this);
        messaggio.exec();
     }
}

void MainWindow::on_aggiornaArticoli_clicked()
{
    ui->listaAggiornamentoArticoli->clear();
    int index = 1;
    for (auto c : Articoli->listaArticoli())
    {
        stringstream stream;
        stream << c;
        string str = stream.str();
        ui->listaAggiornamentoArticoli->addItem(QString::number(index) + ") " + QString::fromStdString(str));
        index++;
    }
}

void MainWindow::on_bottoneConferenza_clicked()
{
        ui->listaArticoliConferenze->clear();
        int index = 1;
        for (auto c : Articoli->listaArticoliConferenza((ui->ricercaConferenzaAcronimo->displayText()).toStdString(),(ui->ricercaConferenzaLuogo->displayText()).toStdString()))
        {

            ui->ricercaConferenzaAcronimo->clear();
            ui->ricercaConferenzaLuogo->clear();
                stringstream stream;
                stream << c;
                string str = stream.str();
                ui->listaArticoliConferenze->addItem(QString::number(index) + ") " + QString::fromStdString(str));
                index++;
        }

}


void MainWindow::on_homeGestore_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->sezioneGestione);
}

void MainWindow::on_bottoneRivista_Ricerca_clicked()
{
    ui->listaArticoliRiviste->clear();
    int index = 1;
    for (auto c : Articoli->listaArticoliRivista((ui->ricercaRivistaAcronimo->displayText()).toStdString(),(ui->ricercaRivistaVolume->displayText()).toStdString()))
    {

        ui->ricercaRivistaAcronimo->clear();
        ui->ricercaRivistaVolume->clear();
            stringstream stream;
            stream << c;
            string str = stream.str();
            ui->listaArticoliRiviste->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }
}

void MainWindow::on_bottoneKeyword_Ricerca_clicked()
{
    ui->listaArticoliKeyword->clear();
    int index = 1;
    for (auto c : Articoli->listaArticoliKeyword((ui->ricercaKeyword->displayText()).toStdString()))
    {

            ui->ricercaKeyword->clear();
            stringstream stream;
            stream << c;
            string str = stream.str();
            ui->listaArticoliKeyword->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }
}



void MainWindow::on_annullaAutore_clicked()
{
    Autori->annullaInserimento();
    ui->listaAut->clear();
}

void MainWindow::on_annullaConferenza_clicked()
{
    Conferenze->annullaInserimento();
    ui->listaOrg->clear();
}

void MainWindow::on_annullaRivista_clicked()
{
    Riviste->annullaInserimento();
    ui->listaRivista->clear();
}



void MainWindow::on_annullaArticolo_clicked()
{
    Articoli->annullaInserimento();
    ui->listaArticoli->clear();
}

void MainWindow::on_bottone_mediaAutori_clicked()
{
    ui->listaMediaAutori->clear();
    double media=0;
    media=Articoli->mediaPrezzi((ui->mediaAutore->displayText()).toStdString());
    ui->listaMediaAutori->addItem(QString::number(media));
}

void MainWindow::on_bottoneGestione_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneGestione);
}
void MainWindow::on_bottoneInserimento_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneInserimento);
}



void MainWindow::on_backToPag1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_1);
}

void MainWindow::on_goToPage2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_2);

}


void MainWindow::on_bottone_keywordRedditizie_clicked()
{
    ui->listakeywordRedditizie->clear();
    for (auto k : Articoli->listaKeywordRedditizie())
    {
        ui->listakeywordRedditizie->addItem(QString::fromStdString(k));
    }
}

void MainWindow::on_bottone_ArticoliAutorePrezzo_clicked()
{
    ui->listaArticoliAutorePrezzo->clear();
    int index = 1;
    for (auto c : Articoli->listaArticoliAutorePrezzo((ui->articoliAutorePrezzo->displayText()).toStdString()))
    {

            ui->articoliAutorePrezzo->clear();
            stringstream stream;
            stream << c;
            string str = stream.str();
            ui->listaArticoliAutorePrezzo->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }


}

void MainWindow::on_bottone_ArticoliAutorePrezzoAlto_clicked()
{
    ui->listaArticoliAutorePrezzoAlto->clear();
    int index = 1;
    for (auto c : Articoli->prezzoAltoAutore((ui->articoliAutorePrezzoAlto->displayText()).toStdString()))
    {

            ui->articoliAutorePrezzoAlto->clear();
            stringstream stream;
            stream << c;
            string str = stream.str();
            ui->listaArticoliAutorePrezzoAlto->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }
}

void MainWindow::on_backToPag2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_2);
}

void MainWindow::on_goToPage3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_3);

}

void MainWindow::on_bottone_ArticoliKeywordAnnoDecrescente_clicked()
{
    ui->listaArticoliKeywordAnnoDecrescente->clear();
    int index = 1;
    for (auto c : Articoli->articoliKeywordAnnoDecrescentePrezzoCrescente((ui->articoliKeywordAnnoDecrescente->displayText()).toStdString()))
    {

            ui->articoliKeywordAnnoDecrescente->clear();
            stringstream stream;
            stream << c;
            string str = stream.str();
            ui->listaArticoliKeywordAnnoDecrescente->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }

}

// METODI PER IMPORTARE I DATI DA FILE .txt

void MainWindow::on_importa_autori_clicked()
{
    QFile file (QFileDialog::getOpenFileName(this, tr("Open File"), ""));
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"Info", file.errorString());

        QTextStream in (&file);
        while (!in.atEnd())
        {
            Autore nuovo;
            QString str = in.readLine();
            nuovo.setNome(str.toStdString());
            str = in.readLine();
            nuovo.setCognome(str.toStdString());
            str = in.readLine();
            nuovo.setID(str.toStdString());
            str = in.readLine();
              while (str!="")
                {
                    nuovo.aggiungiAfferenza(str.toStdString());
                    str = in.readLine();
                }
         if (Autori->idValido(nuovo.getID())){
              Autori->aggiungiAutore(nuovo);
              ui->listaAutori_2->addItem(QString::number (Autori->sizeAutori()) + ") "  + QString::fromStdString(nuovo.getCognome()) + " [ID: " + QString::fromStdString(nuovo.getID()) + "]");
         }
         else {
                 QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile inserire " + QString::fromStdString(nuovo.getNome()) + " " + QString::fromStdString(nuovo.getCognome()) + " perché l'id esiste già.", QMessageBox::Ok, this);
                 messaggio.exec();
                  }
        }
}

void MainWindow::on_importa_conferenze_clicked()
{
    QFile file (QFileDialog::getOpenFileName(this, tr("Open File"), ""));
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"Info", file.errorString());

        QTextStream in (&file);
        while (!in.atEnd())
        {
            Conferenza nuovo;
            QString str = in.readLine();
            nuovo.setNome(str.toStdString());
            str = in.readLine();
            nuovo.setAcronimo(str.toStdString());
            str = in.readLine();
            nuovo.setLuogo(str.toStdString());
            str = in.readLine();
            nuovo.setData(str.toStdString());
            str = in.readLine();
            nuovo.setPartecipanti(stoi(str.toStdString()));
            str = in.readLine();
              while (str!="")
                {
                    nuovo.aggiungiOrganizzatore(str.toStdString());
                    str = in.readLine();
                }
              if (Conferenze->conferenzaValida(nuovo.getAcronimo(), nuovo.getLuogo())){
             Conferenze->aggiungiConferenza(nuovo);
             ui->listaRapidaConferenze->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + QString::fromStdString(nuovo.getNome()) + " [" + QString::fromStdString(nuovo.getAcronimo()) + "] presso " + QString::fromStdString(nuovo.getLuogo()));
             ui->listaRapidaConferenze_2->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + QString::fromStdString(nuovo.getNome()) + " [" + QString::fromStdString(nuovo.getAcronimo()) + "] presso " + QString::fromStdString(nuovo.getLuogo()));
             ui->listaRapidaConferenze_3->addItem(QString::number(Conferenze->sizeConferenze()) + ") " + QString::fromStdString(nuovo.getNome()) + " [" + QString::fromStdString(nuovo.getAcronimo()) + "] presso " + QString::fromStdString(nuovo.getLuogo()));
              }
              else {
                      QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile inserire " + QString::fromStdString(nuovo.getNome()) + " perché la conferenza esiste già.", QMessageBox::Ok, this);
                      messaggio.exec();
                       }
        }
}

void MainWindow::on_importa_riviste_clicked()
{
    QFile file (QFileDialog::getOpenFileName(this, tr("Open File"), ""));
       if (!file.open(QIODevice::ReadOnly))
           QMessageBox::information(0,"Info", file.errorString());

       QTextStream in (&file);
       while (!in.atEnd())
       {
           Rivista nuovo;
           QString str = in.readLine();
           nuovo.setNome(str.toStdString());
           str = in.readLine();
           nuovo.setAcronimo(str.toStdString());
           str = in.readLine();
           nuovo.setEditore(str.toStdString());
           str = in.readLine();
           nuovo.setData(str.toStdString());
           str = in.readLine();
           nuovo.setVolume(str.toStdString());
           str = in.readLine();
           if (Riviste->rivistaValida(nuovo.getVolume(), nuovo.getAcronimo())){
            Riviste->aggiungiRivista(nuovo);
            ui->listaRapidaRiviste->addItem(QString::number (Riviste->sizeRiviste()) + ") " + QString::fromStdString(nuovo.getNome()) + " " + QString::fromStdString(nuovo.getAcronimo()) + " vol.[" + QString::fromStdString(nuovo.getVolume()) + "] ");
            ui->listaRapidaRiviste_2->addItem(QString::number (Riviste->sizeRiviste()) + ") " + QString::fromStdString(nuovo.getNome()) + " " + QString::fromStdString(nuovo.getAcronimo()) + " vol.[" + QString::fromStdString(nuovo.getVolume()) + "] ");
           }
           else {
                   QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile inserire " + QString::fromStdString(nuovo.getNome()) + " perché la rivista esiste già!", QMessageBox::Ok, this);
                   messaggio.exec();
                    }

       }
}




void MainWindow::on_importa_articoli_clicked()
{
    QFile file (QFileDialog::getOpenFileName(this, tr("Open File"), ""));
       if (!file.open(QIODevice::ReadOnly))
           QMessageBox::information(0,"Info", file.errorString());

       QTextStream in (&file);
       while (!in.atEnd())
       {
           Articolo nuovo;
           QString acronimoRiv;
           QString volumeRiv;
           QString acronimoConf;
           QString luogoConf;
           bool valido=true;
           QString str = in.readLine();
           nuovo.setTitolo(str.toStdString());
           str = in.readLine();
           nuovo.setID(str.toStdString());
           str = in.readLine();

           if (str=="RIVISTA")
           {
                acronimoRiv = in.readLine();
                volumeRiv = in.readLine();
               if (Riviste->rivistaValida(acronimoRiv.toStdString(),volumeRiv.toStdString()))
                    valido=false;
               else
               {
                        nuovo.setRivistaRiferimento(Riviste->rivistaRiferimento(acronimoRiv.toStdString(),volumeRiv.toStdString()));
                        nuovo.aggiungiAnno(anno(Riviste->rivistaRiferimento(acronimoRiv.toStdString(),volumeRiv.toStdString()).getData()));

               }
           }

           if (str=="CONFERENZA")
           {
                acronimoConf = in.readLine();
                luogoConf = in.readLine();
               if (Conferenze->conferenzaValida(acronimoConf.toStdString(),luogoConf.toStdString()))
                       valido=false;
               else
                 {
                   nuovo.setConferenzaRiferimento(Conferenze->conferenzaRiferimento(acronimoConf.toStdString(),luogoConf.toStdString()));
                   nuovo.aggiungiAnno(anno(Conferenze->conferenzaRiferimento(acronimoConf.toStdString(),luogoConf.toStdString()).getData()));

                 }
           }

           str = in.readLine();
           nuovo.setPrezzo(stod(str.toStdString()));
           str= in.readLine();
           nuovo.setNumeroPagine(stoi(str.toStdString()));
           str = in.readLine();
           if (str=="AUTORI")
           {
              str = in.readLine();
               while (str!="KEYWORD" && str!="CORRELATI" && str!=""){
                   nuovo.aggiungiAutore(Autori->ricercaID(str.toStdString()));
                   str = in.readLine();
               }
           }
           if (str=="KEYWORD")
           {
              str = in.readLine();
               while (str!="CORRELATI" && str!=""){
                   nuovo.aggiungiKeyword(str.toStdString());
                   Riviste->aggiungiKeyRivista(acronimoRiv.toStdString(), volumeRiv.toStdString(), str.toStdString());
                   Conferenze->aggiungiKeyConferenza(acronimoConf.toStdString(), luogoConf.toStdString(), str.toStdString());
                   if (listaValida(listaRapidaKey, str.toStdString())){
                   listaRapidaKey.push_back(str.toStdString());
                   ui->listaRapidaKeyword->addItem(str);
                   ui->listaRapidaKeyword_2->addItem(str);}
                   str = in.readLine();
               }
           }
           if (str=="CORRELATI")
           {
              str = in.readLine();
               while (str!=""){
                   nuovo.aggiungiArticolo(Articoli->ricercaID(str.toStdString()));
                   str = in.readLine();
               }
           }

           if (Articoli->idValido(nuovo.getID()) && valido){
               Articoli->aggiungiArticolo(nuovo);
               ui->listaRapidaArticoli->addItem(QString::number (Articoli->sizeArticoli()) + ") ["  + QString::fromStdString(nuovo.getTitolo()) + "] ID: " + QString::fromStdString(nuovo.getID()) );
            }
           else if (!valido)
           {
               QMessageBox messaggio (QMessageBox::Critical, "Errore", "Non è stato possibile aggiungere ''" + QString::fromStdString(nuovo.getTitolo()) + "'' in quanto la rivista o la conferenza non esiste." , QMessageBox::Ok, this);
               messaggio.exec();
           }
           else
           {
              QMessageBox messaggio (QMessageBox::Critical, "Errore", "L'articolo non può avere un ID uguale ad un'altro!", QMessageBox::Ok, this);
              messaggio.exec();
           }


       }
}



void MainWindow::on_istruzioni_importa_clicked()
{
    QFile file (":/Istruzioni/Istruzioni/Istruzioni.txt");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"Info", file.errorString());

        QTextStream in (&file);
        ui->istruzioni->setText(in.readAll());
}


// FINE METODI PER IMPORTARE I DATI



void MainWindow::on_goToPage4_clicked()
{
        ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_4);
}

void MainWindow::on_backToPag3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_3);

}

void MainWindow::on_rivisteSpecialistiche_clicked()
{
    ui->listaSpecialistiche->clear();
    int n=1;
    for (auto r: Riviste->rivisteSpecialistiche())
    {
        stringstream stream;
        stream << r;
        string str = stream.str();
        ui->listaSpecialistiche->addItem(QString::number(n) + ") " + QString::fromStdString(str));
        n++;
    }
}


void MainWindow::on_goToPage5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_5);
}

void MainWindow::on_backToPag4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_4);

}

void MainWindow::on_backToPag5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_5);

}

void MainWindow::on_goToPage6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_6);

}

void MainWindow::on_bottone_articoliInfluenzati_clicked()
{
    ui->listaArticoliInfluenzati->clear();
    int index = 1;
    for (auto r: Articoli->articoliInfluenzati(Articoli->ricercaID((ui->idArticolo_influenzato->displayText()).toStdString())))
    {

            stringstream stream;
            stream << r;
            string str = stream.str();
            ui->listaArticoliInfluenzati->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }
}


void MainWindow::on_goToPage7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_7);
}

void MainWindow::on_backToPag6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_6);

}

void MainWindow::on_bottoneConferenza_2_clicked()
{
    ui->listaConferenzeSimili->clear();
    int index = 1;
    for (auto r: Conferenze->conferenzeSimili(Conferenze->conferenzaRiferimento((ui->ricercaConferenzaAcronimo_2->displayText()).toStdString(),(ui->ricercaConferenzaLuogo_2->displayText()).toStdString())))
    {

            stringstream stream;
            stream << r;
            string str = stream.str();
            ui->listaConferenzeSimili->addItem(QString::number(index) + ") " + QString::fromStdString(str));
            index++;
    }
}

void MainWindow::on_home_inserimento_clicked()
{

}

void MainWindow::on_pagina_successiva1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_1);

}


void MainWindow::on_backToPagRapida_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneRapida);
}

void MainWindow::on_cercaArticoli_RivConf_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_1);
}

void MainWindow::on_cerca_autore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_2);
}

void MainWindow::on_visualizza_redditizie_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_5);
}

void MainWindow::on_cerca_influenzati_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_6);
}

void MainWindow::on_cerca_confSimili_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_7);
}

void MainWindow::on_cerca_artKey_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_5);
}

void MainWindow::on_cerca_prezzoAlto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_2);
}

void MainWindow::on_cerca_mediaAutore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_2);
}

void MainWindow::on_visualizza_specialistiche_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_4);
}

void MainWindow::on_visualizza_annoDecrPrezzoCrescAlf_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneArticoli_3);
}
