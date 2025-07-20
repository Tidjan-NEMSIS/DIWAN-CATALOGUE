/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/clickablelabel.h"
#include "ui/marqueelabel.h"
#include "ui/rotatablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCharger;
    QAction *actionSauvegarder;
    QAction *actionInserer;
    QAction *actionSupprimer;
    QAction *actionModifier;
    QAction *actionQuitter;
    QAction *actionRechercher;
    QAction *action_video_presentation;
    QAction *actionA_propos;
    QAction *actionComparaison_Graphique;
    QAction *actionF1;
    QAction *actionF2;
    QAction *actionF3;
    QAction *actionSans_Hashage;
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QWidget *bannerWidget;
    QHBoxLayout *horizontalLayout_banner;
    RotatableLabel *labelLogo;
    MarqueeLabel *labelAppName;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_maison_precedente;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_maison_suivante;
    QHBoxLayout *content_layout;
    QVBoxLayout *thumbnail_layout;
    ClickableLabel *thumbnail_1;
    ClickableLabel *thumbnail_2;
    ClickableLabel *thumbnail_3;
    QVBoxLayout *photo_section_layout;
    QLabel *photo_display_label;
    QHBoxLayout *photo_nav_layout;
    QPushButton *pushButton_photo_precedente;
    QLabel *label_photo_compteur;
    QPushButton *pushButton_photo_suivante;
    QVBoxLayout *details_and_description_layout;
    QGroupBox *detailsGroup;
    QFormLayout *formLayout;
    QLabel *label_id_key;
    QLabel *label_id_val;
    QLabel *label_type_key;
    QLabel *label_type_val;
    QLabel *label_standing_key;
    QLabel *label_standing_val;
    QLabel *label_chambres_key;
    QLabel *label_chambres_val;
    QLabel *label_toilettes_key;
    QLabel *label_toilettes_val;
    QGroupBox *descriptionGroupBox;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *text_description;
    QMenuBar *menubar;
    QMenu *menuBase;
    QMenu *menuMaison;
    QMenu *menuOutils;
    QMenu *menuFonction_de_Hachage;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionCharger = new QAction(MainWindow);
        actionCharger->setObjectName("actionCharger");
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName("actionSauvegarder");
        actionInserer = new QAction(MainWindow);
        actionInserer->setObjectName("actionInserer");
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName("actionSupprimer");
        actionModifier = new QAction(MainWindow);
        actionModifier->setObjectName("actionModifier");
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        actionRechercher = new QAction(MainWindow);
        actionRechercher->setObjectName("actionRechercher");
        action_video_presentation = new QAction(MainWindow);
        action_video_presentation->setObjectName("action_video_presentation");
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName("actionA_propos");
        actionComparaison_Graphique = new QAction(MainWindow);
        actionComparaison_Graphique->setObjectName("actionComparaison_Graphique");
        actionF1 = new QAction(MainWindow);
        actionF1->setObjectName("actionF1");
        actionF2 = new QAction(MainWindow);
        actionF2->setObjectName("actionF2");
        actionF3 = new QAction(MainWindow);
        actionF3->setObjectName("actionF3");
        actionSans_Hashage = new QAction(MainWindow);
        actionSans_Hashage->setObjectName("actionSans_Hashage");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        bannerWidget = new QWidget(centralwidget);
        bannerWidget->setObjectName("bannerWidget");
        bannerWidget->setMinimumSize(QSize(0, 50));
        horizontalLayout_banner = new QHBoxLayout(bannerWidget);
        horizontalLayout_banner->setObjectName("horizontalLayout_banner");
        labelLogo = new RotatableLabel(bannerWidget);
        labelLogo->setObjectName("labelLogo");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelLogo->sizePolicy().hasHeightForWidth());
        labelLogo->setSizePolicy(sizePolicy);
        labelLogo->setMinimumSize(QSize(80, 80));
        labelLogo->setMaximumSize(QSize(80, 80));
        labelLogo->setScaledContents(false);
        labelLogo->setAlignment(Qt::AlignCenter);

        horizontalLayout_banner->addWidget(labelLogo);

        labelAppName = new MarqueeLabel(bannerWidget);
        labelAppName->setObjectName("labelAppName");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAppName->sizePolicy().hasHeightForWidth());
        labelAppName->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(24);
        labelAppName->setFont(font);

        horizontalLayout_banner->addWidget(labelAppName);


        mainLayout->addWidget(bannerWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_maison_precedente = new QPushButton(centralwidget);
        pushButton_maison_precedente->setObjectName("pushButton_maison_precedente");

        horizontalLayout->addWidget(pushButton_maison_precedente);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_maison_suivante = new QPushButton(centralwidget);
        pushButton_maison_suivante->setObjectName("pushButton_maison_suivante");

        horizontalLayout->addWidget(pushButton_maison_suivante);


        mainLayout->addLayout(horizontalLayout);

        content_layout = new QHBoxLayout();
        content_layout->setObjectName("content_layout");
        thumbnail_layout = new QVBoxLayout();
        thumbnail_layout->setObjectName("thumbnail_layout");
        thumbnail_1 = new ClickableLabel(centralwidget);
        thumbnail_1->setObjectName("thumbnail_1");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(thumbnail_1->sizePolicy().hasHeightForWidth());
        thumbnail_1->setSizePolicy(sizePolicy2);
        thumbnail_1->setMinimumSize(QSize(100, 100));
        thumbnail_1->setAlignment(Qt::AlignCenter);
        thumbnail_1->setScaledContents(true);

        thumbnail_layout->addWidget(thumbnail_1);

        thumbnail_2 = new ClickableLabel(centralwidget);
        thumbnail_2->setObjectName("thumbnail_2");
        sizePolicy2.setHeightForWidth(thumbnail_2->sizePolicy().hasHeightForWidth());
        thumbnail_2->setSizePolicy(sizePolicy2);
        thumbnail_2->setMinimumSize(QSize(100, 100));
        thumbnail_2->setAlignment(Qt::AlignCenter);
        thumbnail_2->setScaledContents(true);

        thumbnail_layout->addWidget(thumbnail_2);

        thumbnail_3 = new ClickableLabel(centralwidget);
        thumbnail_3->setObjectName("thumbnail_3");
        sizePolicy2.setHeightForWidth(thumbnail_3->sizePolicy().hasHeightForWidth());
        thumbnail_3->setSizePolicy(sizePolicy2);
        thumbnail_3->setMinimumSize(QSize(100, 100));
        thumbnail_3->setAlignment(Qt::AlignCenter);
        thumbnail_3->setScaledContents(true);

        thumbnail_layout->addWidget(thumbnail_3);


        content_layout->addLayout(thumbnail_layout);

        photo_section_layout = new QVBoxLayout();
        photo_section_layout->setObjectName("photo_section_layout");
        photo_display_label = new QLabel(centralwidget);
        photo_display_label->setObjectName("photo_display_label");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(photo_display_label->sizePolicy().hasHeightForWidth());
        photo_display_label->setSizePolicy(sizePolicy3);
        photo_display_label->setMinimumSize(QSize(400, 400));
        photo_display_label->setScaledContents(false);
        photo_display_label->setAlignment(Qt::AlignCenter);

        photo_section_layout->addWidget(photo_display_label);

        photo_nav_layout = new QHBoxLayout();
        photo_nav_layout->setObjectName("photo_nav_layout");
        pushButton_photo_precedente = new QPushButton(centralwidget);
        pushButton_photo_precedente->setObjectName("pushButton_photo_precedente");

        photo_nav_layout->addWidget(pushButton_photo_precedente);

        label_photo_compteur = new QLabel(centralwidget);
        label_photo_compteur->setObjectName("label_photo_compteur");
        label_photo_compteur->setAlignment(Qt::AlignCenter);

        photo_nav_layout->addWidget(label_photo_compteur);

        pushButton_photo_suivante = new QPushButton(centralwidget);
        pushButton_photo_suivante->setObjectName("pushButton_photo_suivante");

        photo_nav_layout->addWidget(pushButton_photo_suivante);


        photo_section_layout->addLayout(photo_nav_layout);


        content_layout->addLayout(photo_section_layout);

        details_and_description_layout = new QVBoxLayout();
        details_and_description_layout->setObjectName("details_and_description_layout");
        detailsGroup = new QGroupBox(centralwidget);
        detailsGroup->setObjectName("detailsGroup");
        formLayout = new QFormLayout(detailsGroup);
        formLayout->setObjectName("formLayout");
        label_id_key = new QLabel(detailsGroup);
        label_id_key->setObjectName("label_id_key");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_id_key);

        label_id_val = new QLabel(detailsGroup);
        label_id_val->setObjectName("label_id_val");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, label_id_val);

        label_type_key = new QLabel(detailsGroup);
        label_type_key->setObjectName("label_type_key");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_type_key);

        label_type_val = new QLabel(detailsGroup);
        label_type_val->setObjectName("label_type_val");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, label_type_val);

        label_standing_key = new QLabel(detailsGroup);
        label_standing_key->setObjectName("label_standing_key");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_standing_key);

        label_standing_val = new QLabel(detailsGroup);
        label_standing_val->setObjectName("label_standing_val");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, label_standing_val);

        label_chambres_key = new QLabel(detailsGroup);
        label_chambres_key->setObjectName("label_chambres_key");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_chambres_key);

        label_chambres_val = new QLabel(detailsGroup);
        label_chambres_val->setObjectName("label_chambres_val");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, label_chambres_val);

        label_toilettes_key = new QLabel(detailsGroup);
        label_toilettes_key->setObjectName("label_toilettes_key");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_toilettes_key);

        label_toilettes_val = new QLabel(detailsGroup);
        label_toilettes_val->setObjectName("label_toilettes_val");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, label_toilettes_val);


        details_and_description_layout->addWidget(detailsGroup);

        descriptionGroupBox = new QGroupBox(centralwidget);
        descriptionGroupBox->setObjectName("descriptionGroupBox");
        verticalLayout_4 = new QVBoxLayout(descriptionGroupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        text_description = new QTextBrowser(descriptionGroupBox);
        text_description->setObjectName("text_description");

        verticalLayout_4->addWidget(text_description);


        details_and_description_layout->addWidget(descriptionGroupBox);


        content_layout->addLayout(details_and_description_layout);

        content_layout->setStretch(0, 1);
        content_layout->setStretch(1, 4);
        content_layout->setStretch(2, 2);

        mainLayout->addLayout(content_layout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuBase = new QMenu(menubar);
        menuBase->setObjectName("menuBase");
        menuMaison = new QMenu(menubar);
        menuMaison->setObjectName("menuMaison");
        menuOutils = new QMenu(menubar);
        menuOutils->setObjectName("menuOutils");
        menuFonction_de_Hachage = new QMenu(menuOutils);
        menuFonction_de_Hachage->setObjectName("menuFonction_de_Hachage");
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBase->menuAction());
        menubar->addAction(menuMaison->menuAction());
        menubar->addAction(menuOutils->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuBase->addAction(actionCharger);
        menuBase->addAction(actionSauvegarder);
        menuBase->addSeparator();
        menuBase->addAction(actionQuitter);
        menuMaison->addAction(actionRechercher);
        menuMaison->addAction(actionInserer);
        menuMaison->addAction(actionSupprimer);
        menuMaison->addAction(actionModifier);
        menuOutils->addAction(menuFonction_de_Hachage->menuAction());
        menuOutils->addSeparator();
        menuOutils->addAction(actionComparaison_Graphique);
        menuFonction_de_Hachage->addAction(actionF1);
        menuFonction_de_Hachage->addAction(actionF2);
        menuFonction_de_Hachage->addAction(actionF3);
        menuFonction_de_Hachage->addSeparator();
        menuFonction_de_Hachage->addAction(actionSans_Hashage);
        menuAide->addAction(action_video_presentation);
        menuAide->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Diwan-catalogue", nullptr));
        actionCharger->setText(QCoreApplication::translate("MainWindow", "Charger Donn\303\251es", nullptr));
        actionSauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegarder Modifs", nullptr));
        actionInserer->setText(QCoreApplication::translate("MainWindow", "Ins\303\251rer...", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        actionModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher...", nullptr));
        action_video_presentation->setText(QCoreApplication::translate("MainWindow", "Pr\303\251sentation Vid\303\251o", nullptr));
        actionA_propos->setText(QCoreApplication::translate("MainWindow", "A propos", nullptr));
        actionComparaison_Graphique->setText(QCoreApplication::translate("MainWindow", "Comparaison Graphique", nullptr));
        actionF1->setText(QCoreApplication::translate("MainWindow", "F1 - Somme Caract\303\250res", nullptr));
        actionF2->setText(QCoreApplication::translate("MainWindow", "F2 - Hachage Polynomial", nullptr));
        actionF3->setText(QCoreApplication::translate("MainWindow", "F3 - DJB2", nullptr));
        actionSans_Hashage->setText(QCoreApplication::translate("MainWindow", "Sans Hashage", nullptr));
        labelLogo->setText(QString());
        labelAppName->setText(QCoreApplication::translate("MainWindow", "Diwan-catalogue", nullptr));
        pushButton_maison_precedente->setText(QCoreApplication::translate("MainWindow", "<< Maison Pr\303\251c\303\251dente", nullptr));
        pushButton_maison_suivante->setText(QCoreApplication::translate("MainWindow", "Maison Suivante >>", nullptr));
        thumbnail_1->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid transparent; border-radius: 5px;", nullptr));
        thumbnail_1->setText(QString());
        thumbnail_2->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid transparent; border-radius: 5px;", nullptr));
        thumbnail_2->setText(QString());
        thumbnail_3->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid transparent; border-radius: 5px;", nullptr));
        thumbnail_3->setText(QString());
        photo_display_label->setText(QCoreApplication::translate("MainWindow", "Photo", nullptr));
        pushButton_photo_precedente->setText(QCoreApplication::translate("MainWindow", "< Photo", nullptr));
        label_photo_compteur->setText(QCoreApplication::translate("MainWindow", "Photo 0/0", nullptr));
        pushButton_photo_suivante->setText(QCoreApplication::translate("MainWindow", "Photo >", nullptr));
        detailsGroup->setTitle(QCoreApplication::translate("MainWindow", "D\303\251tails de la Maison", nullptr));
        label_id_key->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_id_val->setText(QString());
        label_type_key->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_type_val->setText(QString());
        label_standing_key->setText(QCoreApplication::translate("MainWindow", "Standing", nullptr));
        label_standing_val->setText(QString());
        label_chambres_key->setText(QCoreApplication::translate("MainWindow", "Chambres", nullptr));
        label_chambres_val->setText(QString());
        label_toilettes_key->setText(QCoreApplication::translate("MainWindow", "Toilettes", nullptr));
        label_toilettes_val->setText(QString());
        descriptionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Description", nullptr));
        menuBase->setTitle(QCoreApplication::translate("MainWindow", "Base", nullptr));
        menuMaison->setTitle(QCoreApplication::translate("MainWindow", "Maison", nullptr));
        menuOutils->setTitle(QCoreApplication::translate("MainWindow", "Outils", nullptr));
        menuFonction_de_Hachage->setTitle(QCoreApplication::translate("MainWindow", "Fonction de Hachage", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
