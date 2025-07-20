#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comparaisondialog.h" // Ajout de l'en-tête
#include "dialogmaison.h"
#include "documentationdialog.h"
#include "confirmationdialog.h" // Ajout de l'en-tête
#include "videoplayerdialog.h"
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <algorithm> // Pour std::sort
#include "../models/maison.h" // Inclusion nécessaire pour utiliser Maison

#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_db(Database::getInstance())
    , m_donneesModifiees(false)
    , m_indexMaisonCourante(-1)
    , m_indexPhotoCourante(0)
{
    ui->setupUi(this);

    // Définir les facteurs d'étirement pour la bannière (0=logo, 1=titre)
    ui->horizontalLayout_banner->setStretch(0, 0); // Le logo ne s'étire pas
    ui->horizontalLayout_banner->setStretch(1, 1); // Le titre prend tout l'espace restant

    // Charger et redimensionner le logo proprement
    QPixmap logoPixmap(":/icons/logo.png");
    ui->labelLogo->setPixmap(logoPixmap.scaled(ui->labelLogo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // --- Initialisation de la galerie de photos ---
    m_thumbnails.append(ui->thumbnail_1);
    m_thumbnails.append(ui->thumbnail_2);
    m_thumbnails.append(ui->thumbnail_3);

    initialiserApplication();

    // --- Animation du logo ---
    // 1. Créer l'animation de rotation
    auto* rotationAnimation = new QPropertyAnimation(ui->labelLogo, "rotation", this);
    rotationAnimation->setDuration(5000); // 5 secondes pour une rotation complète
    rotationAnimation->setStartValue(0);
    rotationAnimation->setEndValue(360);
    rotationAnimation->setLoopCount(-1); // Répétition infinie
    rotationAnimation->setEasingCurve(QEasingCurve::Linear); // Vitesse constante

    // 2. Créer l'effet de surbrillance (glow)
    auto* glowEffect = new QGraphicsDropShadowEffect(this);
    glowEffect->setOffset(0, 0);
    glowEffect->setColor(QColor("#FDB913")); // Couleur jaune de l'accent
    glowEffect->setBlurRadius(25); // Rayon du flou pour l'effet de lueur

    ui->labelLogo->setGraphicsEffect(glowEffect);

    // 3. Démarrer l'animation
    rotationAnimation->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialiserApplication()
{
    connecterSignaux();
    mettreAJourControlesNavigation(); // Désactiver les boutons au démarrage
    
    // Tentative de connexion à la base de données
    if (!m_db.initialiser()) {
        afficherMessage("Erreur Critique", "Impossible de se connecter à la base de données.\n" + m_db.getErreur(), true);
        ui->statusbar->showMessage("Erreur de connexion à la base de données.");
    } else {
        ui->statusbar->showMessage("Prêt. Chargez des données pour commencer.");
    }
}



void MainWindow::connecterSignaux()
{
    // Connexion manuelle pour les vignettes cliquables
    for (ClickableLabel* thumbnail : m_thumbnails) {
        connect(thumbnail, &ClickableLabel::clicked, this, &MainWindow::onThumbnailClicked);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (m_donneesModifiees) {
        QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Sauvegarder les modifications ?",
                                                                    "Vous avez des modifications non sauvegardées. Voulez-vous les sauvegarder avant de quitter ?",
                                                                    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                                                    QMessageBox::Cancel);

        if (resBtn == QMessageBox::Save) {
            on_actionSauvegarder_triggered();
            event->accept();
        } else if (resBtn == QMessageBox::Discard) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}

// --- SLOTS: Actions du Menu ---

void MainWindow::on_actionCharger_triggered()
{
    if (m_donneesModifiees) {
         QMessageBox::StandardButton res = QMessageBox::question(this, "Modifications non sauvegardées",
                                                                 "Voulez-vous sauvegarder les modifications actuelles avant de recharger la base ?",
                                                                 QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (res == QMessageBox::Save) on_actionSauvegarder_triggered();
        if (res == QMessageBox::Cancel) return;
    }
    chargerDonnees();
}

void MainWindow::on_actionSauvegarder_triggered()
{
    if (m_db.sauvegarderTable(m_table)) {
        m_donneesModifiees = false;
        afficherMessage("Succès", "Les modifications ont été sauvegardées dans la base de données.");
        ui->statusbar->showMessage("Données sauvegardées.", 5000);
    } else {
        afficherMessage("Erreur de Sauvegarde", "Impossible de sauvegarder les données.\n" + m_db.getErreur(), true);
    }
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close(); // Déclenche closeEvent
}

// --- SLOTS: Navigation Maisons ---

void MainWindow::on_pushButton_maison_suivante_clicked()
{
    if (m_indexMaisonCourante < m_clesMaisons.size() - 1) {
        m_indexMaisonCourante++;
        afficherMaisonParIndex(m_indexMaisonCourante);
    }
}

void MainWindow::on_pushButton_maison_precedente_clicked()
{
    if (m_indexMaisonCourante > 0) {
        m_indexMaisonCourante--;
        afficherMaisonParIndex(m_indexMaisonCourante);
    }
}

// --- SLOTS: Navigation Photos ---

void MainWindow::on_pushButton_photo_suivante_clicked()
{
    if (m_indexMaisonCourante != -1) {
        m_indexPhotoCourante = (m_indexPhotoCourante + 1) % 4; // 4 photos, boucle de 0 à 3
        miseAJourAffichagePhotos();
    }
}

void MainWindow::on_pushButton_photo_precedente_clicked()
{
    if (m_indexMaisonCourante != -1) {
        m_indexPhotoCourante = (m_indexPhotoCourante - 1 + 4) % 4; // Boucle inverse
        miseAJourAffichagePhotos();
    }
}

void MainWindow::onThumbnailClicked()
{
    auto* clickedLabel = qobject_cast<ClickableLabel*>(sender());
    if (!clickedLabel) return;

    bool ok;
    int photoIndex = clickedLabel->property("photo_index").toInt(&ok);

    if (ok) {
        m_indexPhotoCourante = photoIndex;
        miseAJourAffichagePhotos();
    }
}

// --- Méthodes de logique principale ---

void MainWindow::chargerDonnees()
{
    if (!m_db.chargerDansTable(m_table)) {
        afficherMessage("Erreur de Chargement", "Impossible de charger les données depuis la base.\n" + m_db.getErreur(), true);
        return;
    }

    m_clesMaisons = m_table.getCles();
    std::sort(m_clesMaisons.begin(), m_clesMaisons.end()); // Trier pour un ordre cohérent

    if (m_clesMaisons.isEmpty()) {
        m_indexMaisonCourante = -1;
        afficherMessage("Information", "La base de données est vide.");
        // Vider les champs
        afficherDetailsMaison(nullptr);
    } else {
        m_indexMaisonCourante = 0;
        afficherMaisonParIndex(m_indexMaisonCourante);
    }
    
    m_donneesModifiees = false;
    ui->statusbar->showMessage(QString("%1 maisons chargées.").arg(m_clesMaisons.size()), 5000);
}

void MainWindow::afficherMaisonParIndex(int index)
{
    if (index < 0 || index >= m_clesMaisons.size()) {
        afficherDetailsMaison(nullptr); // Vider l'affichage si l'index est invalide
        return;
    }

    QString id = m_clesMaisons.at(index);
    Maison* maison = m_table.get(id);
    afficherDetailsMaison(maison);
}

void MainWindow::afficherDetailsMaison(const Maison* maison)
{
    if (maison) {
        ui->label_id_val->setText(maison->getId());
        ui->label_type_val->setText(maison->getType());
        ui->label_standing_val->setText(maison->getStanding());
        ui->label_chambres_val->setText(QString::number(maison->getChambres()));
        ui->label_toilettes_val->setText(QString::number(maison->getToilettes()));
        ui->text_description->setText(maison->getDescription());
        
        m_indexPhotoCourante = 0;
        miseAJourAffichagePhotos();
    } else {
        // Vider tous les champs
        ui->label_id_val->clear();
        ui->label_type_val->clear();
        ui->label_standing_val->clear();
        ui->label_chambres_val->clear();
        ui->label_toilettes_val->clear();
        ui->text_description->clear();
        ui->photo_display_label->clear();
        ui->photo_display_label->setText("Aucune maison sélectionnée");
        // Vider aussi les vignettes
        for (auto* thumb : m_thumbnails) {
            thumb->clear();
        }
        ui->label_photo_compteur->setText("Photo 0/0");
    }
    mettreAJourControlesNavigation();
}

void MainWindow::miseAJourAffichagePhotos()
{
    if (m_indexMaisonCourante == -1) return;

    QString id = m_clesMaisons.at(m_indexMaisonCourante);
    Maison* maison = m_table.get(id);
    if (!maison) return;

    // 1. Rassembler toutes les photos dans une liste
    QList<QString> toutesLesPhotos;
    toutesLesPhotos << maison->getPhoto1() << maison->getPhoto2() << maison->getPhoto3() << maison->getPhoto4();

    // 2. Créer la file d'attente en commençant par la photo courante
    QList<QString> filePhotos;
    QList<int> fileIndex;
    for (int i = 0; i < toutesLesPhotos.size(); ++i) {
        int currentIndex = (m_indexPhotoCourante + i) % toutesLesPhotos.size();
        filePhotos.append(toutesLesPhotos.at(currentIndex));
        fileIndex.append(currentIndex);
    }

    // 3. Afficher l'image principale
    QPixmap pixmapPrincipal(filePhotos.at(0));
    if (pixmapPrincipal.isNull()) {
        ui->photo_display_label->setText("Photo principale non trouvée");
    } else {
        ui->photo_display_label->setPixmap(pixmapPrincipal.scaled(ui->photo_display_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // 4. Afficher les vignettes
    for (int i = 0; i < m_thumbnails.size(); ++i) {
        ClickableLabel* thumbnail = m_thumbnails.at(i);
        int photoIndexDansFile = i + 1;

        if (photoIndexDansFile < filePhotos.size()) {
            QString cheminVignette = filePhotos.at(photoIndexDansFile);
            QPixmap pixmapVignette(cheminVignette);

            if (pixmapVignette.isNull()) {
                thumbnail->setText("N/A");
                thumbnail->setProperty("photo_index", -1); // Index invalide
            } else {
                thumbnail->clear();
                thumbnail->setPixmap(pixmapVignette.scaled(thumbnail->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                thumbnail->setProperty("photo_index", fileIndex.at(photoIndexDansFile));
            }
        } else {
            thumbnail->clear();
            thumbnail->setProperty("photo_index", -1);
        }
    }

    // 5. Mettre à jour le compteur
    ui->label_photo_compteur->setText(QString("%1 / 4").arg(m_indexPhotoCourante + 1));
}

void MainWindow::mettreAJourControlesNavigation()
{
    bool maisonsChargees = !m_clesMaisons.isEmpty();
    ui->pushButton_maison_precedente->setEnabled(maisonsChargees && m_indexMaisonCourante > 0);
    ui->pushButton_maison_suivante->setEnabled(maisonsChargees && m_indexMaisonCourante < m_clesMaisons.size() - 1);
    
    ui->pushButton_photo_precedente->setEnabled(maisonsChargees);
    ui->pushButton_photo_suivante->setEnabled(maisonsChargees);
    
    // Activer/désactiver les actions qui dépendent des données
    ui->actionSauvegarder->setEnabled(m_donneesModifiees);
    ui->actionRechercher->setEnabled(maisonsChargees);
    ui->actionSupprimer->setEnabled(maisonsChargees && m_indexMaisonCourante != -1);
    ui->actionInserer->setEnabled(true);
}

void MainWindow::afficherMessage(const QString& titre, const QString& message, bool isError)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(titre);
    msgBox.setText(message);
    msgBox.setIcon(isError ? QMessageBox::Critical : QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

// --- Slots pour le menu de Hachage ---

void MainWindow::on_actionF1_triggered()
{
    m_table.setFonctionHachage(TableHachage::F1);
    ui->statusbar->showMessage("Fonction de hachage F1 sélectionnée.", 5000);
}

void MainWindow::on_actionF2_triggered()
{
    m_table.setFonctionHachage(TableHachage::F2);
    ui->statusbar->showMessage("Fonction de hachage F2 sélectionnée.", 5000);
}

void MainWindow::on_actionF3_triggered()
{
    m_table.setFonctionHachage(TableHachage::F3);
    ui->statusbar->showMessage("Fonction de hachage F3 sélectionnée.", 5000);
}

void MainWindow::on_actionSans_Hashage_triggered()
{
    m_table.setFonctionHachage(TableHachage::SANS_HACHAGE);
    ui->statusbar->showMessage("Aucune fonction de hachage sélectionnée (mode séquentiel).", 5000);
}

void MainWindow::on_actionComparaison_Graphique_triggered()
{
    // 1. Récupérer toutes les maisons de la table actuelle
    QVector<Maison*> toutesLesMaisons;
    for (const QString& cle : m_clesMaisons) {
        Maison* maison = m_table.get(cle);
        if (maison != nullptr) { // Vérification de sécurité
            toutesLesMaisons.append(maison);
        }
    }

    if (toutesLesMaisons.isEmpty()) {
        afficherMessage("Information", "Aucune donnée à comparer. Veuillez charger des maisons d'abord.");
        return;
    }

    // 2. Créer et afficher la boîte de dialogue
    ComparaisonDialog dialog(toutesLesMaisons, this);
    dialog.exec();
}



// --- Stubs pour les fonctionnalités futures ---

void MainWindow::on_actionRechercher_triggered()
{
    bool ok;
    QString id = QInputDialog::getText(this, "Rechercher une maison", "Entrez l'ID de la maison (ex: MAISON001):", QLineEdit::Normal, "", &ok);
    if (ok && !id.isEmpty()) {
        int index = m_clesMaisons.indexOf(id);
        if (index != -1) {
            m_indexMaisonCourante = index;
            afficherMaisonParIndex(index);
            ui->statusbar->showMessage("Maison " + id + " trouvée.", 5000);
        } else {
            afficherMessage("Recherche", "Aucune maison trouvée avec l'ID '" + id + "'.");
        }
    }
}

void MainWindow::on_actionInserer_triggered()
{
    DialogMaison dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Maison maison = dialog.getMaison();
        QString id = maison.getId();

        if (m_table.contient(id)) {
            afficherMessage("Erreur", "Une maison avec cet ID existe déjà.", true);
            return;
        }

        Maison* nouvelleMaison = new Maison(maison);
        m_table.inserer(id, nouvelleMaison);
        m_clesMaisons.append(id);
        m_donneesModifiees = true;

        // Afficher la nouvelle maison
        m_indexMaisonCourante = m_clesMaisons.size() - 1;
        afficherMaisonParIndex(m_indexMaisonCourante);

        afficherMessage("Succès", "La maison a été insérée avec succès.");
    }
}

void MainWindow::on_actionSupprimer_triggered()
{
    bool ok;
    QString id = QInputDialog::getText(this, "Supprimer une maison", "Entrez l'ID de la maison à supprimer (ex: MAISON001):", QLineEdit::Normal, "", &ok);

    if (!ok || id.isEmpty()) {
        return; // L'utilisateur a annulé ou n'a rien saisi
    }

    if (!m_table.contient(id)) {
        afficherMessage("Erreur", "Aucune maison trouvée avec l'ID '" + id + "'.", true);
        return;
    }

    Maison* maisonASupprimer = m_table.get(id);
    if (!maisonASupprimer) { // Sécurité supplémentaire
        afficherMessage("Erreur", "Erreur interne: Impossible de récupérer les détails de la maison '" + id + "'.", true);
        return;
    }

    // Utiliser la boîte de dialogue de confirmation existante
    QPixmap image(maisonASupprimer->getPhoto1());
    QString details = QString("ID: %1\nType: %2\nStanding: %3")
                        .arg(maisonASupprimer->getId())
                        .arg(maisonASupprimer->getType())
                        .arg(maisonASupprimer->getStanding());

    ConfirmationDialog dialog("Confirmer la suppression",
                              "Êtes-vous sûr de vouloir supprimer cette maison ?",
                              details,
                              image,
                              this);

    if (dialog.exec() == QDialog::Accepted) {
        int indexASupprimer = m_clesMaisons.indexOf(id);

        m_table.supprimer(id);
        if (indexASupprimer != -1) {
            m_clesMaisons.removeAt(indexASupprimer);
        }
        m_donneesModifiees = true;

        // Si la maison supprimée était celle affichée, mettre à jour l'affichage
        if (indexASupprimer == m_indexMaisonCourante) {
            if (m_clesMaisons.isEmpty()) {
                m_indexMaisonCourante = -1;
                afficherDetailsMaison(nullptr);
            } else {
                // Afficher l'élément précédent ou le premier si on était au début
                if (m_indexMaisonCourante >= m_clesMaisons.size()) {
                    m_indexMaisonCourante = m_clesMaisons.size() - 1;
                }
                afficherMaisonParIndex(m_indexMaisonCourante);
            }
        } else {
            // Mettre à jour l'index courant s'il est affecté par la suppression
            if (indexASupprimer < m_indexMaisonCourante) {
                m_indexMaisonCourante--;
            }
        }
        
        mettreAJourControlesNavigation();
        afficherMessage("Succès", "La maison '" + id + "' a été supprimée.");
    }
}

void MainWindow::on_actionModifier_triggered()
{
    bool ok;
    QString id = QInputDialog::getText(this, "Modifier une maison", "Entrez l'ID de la maison à modifier (ex: MAISON001):", QLineEdit::Normal, "", &ok);

    if (!ok || id.isEmpty()) {
        return; // L'utilisateur a annulé
    }

    if (!m_table.contient(id)) {
        afficherMessage("Erreur", "Aucune maison trouvée avec l'ID '" + id + "'.", true);
        return;
    }

    Maison* maisonAModifier = m_table.get(id);
    if (!maisonAModifier) {
        afficherMessage("Erreur", "Erreur interne: Impossible de récupérer les détails de la maison.", true);
        return;
    }

    // Ouvrir la boîte de dialogue avec les données de la maison
    DialogMaison dialog(*maisonAModifier, this);
    if (dialog.exec() == QDialog::Accepted) {
        // Récupérer les nouvelles données
        Maison maisonModifiee = dialog.getMaison();

        // Mettre à jour l'objet Maison existant dans la table de hachage
        *maisonAModifier = maisonModifiee;

        m_donneesModifiees = true;

        // Rafraîchir l'affichage si la maison modifiée est celle actuellement affichée
        if (m_indexMaisonCourante != -1 && m_clesMaisons[m_indexMaisonCourante] == id) {
            afficherDetailsMaison(maisonAModifier);
        }

        afficherMessage("Succès", "La maison '" + id + "' a été modifiée avec succès.");
    }
}

void MainWindow::on_action_video_presentation_triggered()
{
    QString videoPath = "C:/Users/ETUDE/OneDrive/Documents/PROJET_MAISON/catalogue/Diwan-catalogue/video/Presentation_video.mp4";
    VideoPlayerDialog player(videoPath, this);
    player.exec();
}

void MainWindow::on_actionA_propos_triggered()
{
    DocumentationDialog dialog(this);
    dialog.exec();
}