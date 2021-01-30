#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GestoreAutori.h"
#include "GestoreConferenze.h"
#include "GestoreRiviste.h"
#include "GestoreArticoli.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_backInserimento();

    void on_backGestore();

    void on_altreOperazioni();

    void on_bottoneAutore_clicked();

    void on_bottoneAfferenza_clicked();

    void on_bottoneGestione_clicked();

    void on_bottoneInserimento_clicked();

    void on_bottoneRivista_clicked();

    void on_aggiornaAutori_clicked();

    void on_aggiornaConferenze_clicked();

    void on_aggiornaRiviste_clicked();

    void on_bottoneArticolo_clicked();

    void on_bottoneOkAutori_clicked();

    void on_bottoneOkKeyword_clicked();

    void on_bottoneArticoloCorrelato_clicked();

    void on_aggiornaArticoli_clicked();

    void on_bottoneConferenza_clicked();

    void on_homeGestore_clicked();

    void on_bottoneRivista_Ricerca_clicked();

    void on_bottoneKeyword_Ricerca_clicked();

    void on_annullaAutore_clicked();

    void on_annullaConferenza_clicked();

    void on_annullaRivista_clicked();

    void on_annullaArticolo_clicked();

    void on_bottone_mediaAutori_clicked();

    void on_backToPag1_clicked();

    void on_goToPage2_clicked();

    void on_bottone_keywordRedditizie_clicked();

    void on_bottone_ArticoliAutorePrezzo_clicked();

    void on_bottone_ArticoliAutorePrezzoAlto_clicked();

    void on_backToPag2_clicked();

    void on_goToPage3_clicked();

    void on_bottone_ArticoliKeywordAnnoDecrescente_clicked();

    void on_importa_autori_clicked();

    void on_importa_conferenze_clicked();

    void on_importa_riviste_clicked();

    void on_bottoneConferenze_clicked();

    void on_bottoneOrganizzatori_clicked();

    void on_importa_articoli_clicked();

    void on_istruzioni_importa_clicked();

    void on_rivisteSpecialistiche_clicked();

    void on_goToPage4_clicked();

    void on_backToPag3_clicked();

    void on_goToPage5_clicked();

    void on_backToPag4_clicked();

    void on_backToPag5_clicked();

    void on_goToPage6_clicked();

    void on_bottone_articoliInfluenzati_clicked();

    void on_goToPage7_clicked();

    void on_backToPag6_clicked();

    void on_bottoneConferenza_2_clicked();

    void on_home_inserimento_clicked();

    void on_pagina_successiva1_clicked();

    void on_backToPagRapida_clicked();

    void on_cercaArticoli_RivConf_clicked();

    void on_cerca_autore_clicked();

    void on_visualizza_redditizie_clicked();

    void on_cerca_influenzati_clicked();

    void on_cerca_confSimili_clicked();

    void on_cerca_artKey_clicked();

    void on_cerca_prezzoAlto_clicked();

    void on_cerca_mediaAutore_clicked();

    void on_visualizza_specialistiche_clicked();

    void on_visualizza_annoDecrPrezzoCrescAlf_clicked();

private:
    Ui::MainWindow *ui;
    GestoreAutori* Autori;
    GestoreConferenze* Conferenze;
    GestoreRiviste* Riviste;
    GestoreArticoli* Articoli;

    vector<string> listaRapidaKey;
    QString acronimoRivista;
    QString volumeRivista;
    QString acronimoConferenza;
    QString luogoConferenza;

};
#endif // MAINWINDOW_H
