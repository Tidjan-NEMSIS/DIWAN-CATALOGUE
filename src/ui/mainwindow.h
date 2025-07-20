#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent> // Nécessaire pour la gestion de la fermeture
#include "ui/clickablelabel.h"


#include "../models/table_hachage.h"
#include "../database/db.h"

// Forward declaration pour éviter les inclusions croisées
namespace Ui { class MainWindow; }
class Maison;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // Redéfinition de l'événement de fermeture pour demander la sauvegarde
    void closeEvent(QCloseEvent *event) override;

private slots:
    // --- Actions du Menu ---
    void on_actionCharger_triggered();
    void on_actionSauvegarder_triggered();
    void on_actionQuitter_triggered();
    void on_actionRechercher_triggered();
    void on_actionInserer_triggered();
    void on_actionSupprimer_triggered();
    void on_actionModifier_triggered();
    void on_actionA_propos_triggered();
    void on_action_video_presentation_triggered();

    // --- Actions du Menu (Fonction de Hachage) ---
    void on_actionF1_triggered();
    void on_actionF2_triggered();
    void on_actionF3_triggered();
    void on_actionSans_Hashage_triggered();

    // --- Actions du Menu (Comparaison) ---
    void on_actionComparaison_Graphique_triggered();



    // --- Boutons de Navigation (Maisons) ---
    void on_pushButton_maison_suivante_clicked();
    void on_pushButton_maison_precedente_clicked();

    // --- Boutons de Navigation (Photos) ---
    void on_pushButton_photo_suivante_clicked();
    void on_pushButton_photo_precedente_clicked();

    // --- Galerie Photos ---
    void onThumbnailClicked();

private:
    Ui::MainWindow *ui;
    TableHachage m_table;
    Database& m_db;
    bool m_donneesModifiees; // Pour savoir si on doit proposer de sauvegarder

    // --- Gestion de l'état de l'affichage ---
    QList<QString> m_clesMaisons;       // Liste ordonnée des clés des maisons chargées
    int m_indexMaisonCourante;          // Index dans m_clesMaisons de la maison affichée
    int m_indexPhotoCourante;           // Index de la photo affichée (0-3)

    // --- Gestion de la galerie de photos ---
    QList<ClickableLabel*> m_thumbnails; // Liste des labels des vignettes



    // --- Méthodes d'initialisation ---
    void initialiserApplication();
    void appliquerStyle();
    void connecterSignaux();

    // --- Méthodes de logique principale ---
    void chargerDonnees();
    void afficherMaisonParIndex(int index);
    void afficherDetailsMaison(const Maison* maison);
    void afficherPhotoActuelle();
    void miseAJourAffichagePhotos();
    void mettreAJourControlesNavigation();
    void afficherMessage(const QString& titre, const QString& message, bool isError = false);
};

#endif // MAINWINDOW_H