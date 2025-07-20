/********************************************************************************
** Form generated from reading UI file 'comparaisondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARAISONDIALOG_H
#define UI_COMPARAISONDIALOG_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComparaisonDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabVitesse;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidgetVitesse;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QChartView *chartViewVitesseCourbe;
    QWidget *tab_vitesse_barres;
    QVBoxLayout *verticalLayout_vitesse_barres;
    QChartView *chartViewVitesseBarres;
    QWidget *tab_vitesse_circulaire;
    QVBoxLayout *verticalLayout_vitesse_circulaire;
    QChartView *chartViewVitesseCirculaire;
    QWidget *tabCollisions;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidgetCollisions;
    QWidget *tabCollisionsCourbe;
    QGridLayout *gridLayout_6;
    QChartView *chartViewCollisionsCourbe;
    QWidget *tabCollisionsBarres;
    QGridLayout *gridLayout_7;
    QChartView *chartViewCollisionsBarres;
    QWidget *tabCollisionsCirculaire;
    QGridLayout *gridLayout_8;
    QChartView *chartViewCollisionsCirculaire;
    QWidget *tabTableau;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetResultats;
    QWidget *tabEvolution;
    QGridLayout *gridLayout_evolution;
    QTabWidget *tabWidgetEvolution;
    QWidget *tabEvolutionCollisions;
    QVBoxLayout *verticalLayout_evo_coll;
    QChartView *chartViewEvolutionCollisions;
    QWidget *tabEvolutionVitesse;
    QVBoxLayout *verticalLayout_evo_vit;
    QLabel *label_evo_ins;
    QChartView *chartViewEvolutionVitesseInsertion;
    QLabel *label_evo_rech;
    QChartView *chartViewEvolutionVitesseRecherche;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ComparaisonDialog)
    {
        if (ComparaisonDialog->objectName().isEmpty())
            ComparaisonDialog->setObjectName("ComparaisonDialog");
        ComparaisonDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(ComparaisonDialog);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ComparaisonDialog);
        tabWidget->setObjectName("tabWidget");
        tabVitesse = new QWidget();
        tabVitesse->setObjectName("tabVitesse");
        gridLayout_2 = new QGridLayout(tabVitesse);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidgetVitesse = new QTabWidget(tabVitesse);
        tabWidgetVitesse->setObjectName("tabWidgetVitesse");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        chartViewVitesseCourbe = new QChartView(tab_3);
        chartViewVitesseCourbe->setObjectName("chartViewVitesseCourbe");

        verticalLayout_4->addWidget(chartViewVitesseCourbe);

        tabWidgetVitesse->addTab(tab_3, QString());
        tab_vitesse_barres = new QWidget();
        tab_vitesse_barres->setObjectName("tab_vitesse_barres");
        verticalLayout_vitesse_barres = new QVBoxLayout(tab_vitesse_barres);
        verticalLayout_vitesse_barres->setObjectName("verticalLayout_vitesse_barres");
        chartViewVitesseBarres = new QChartView(tab_vitesse_barres);
        chartViewVitesseBarres->setObjectName("chartViewVitesseBarres");

        verticalLayout_vitesse_barres->addWidget(chartViewVitesseBarres);

        tabWidgetVitesse->addTab(tab_vitesse_barres, QString());
        tab_vitesse_circulaire = new QWidget();
        tab_vitesse_circulaire->setObjectName("tab_vitesse_circulaire");
        verticalLayout_vitesse_circulaire = new QVBoxLayout(tab_vitesse_circulaire);
        verticalLayout_vitesse_circulaire->setObjectName("verticalLayout_vitesse_circulaire");
        chartViewVitesseCirculaire = new QChartView(tab_vitesse_circulaire);
        chartViewVitesseCirculaire->setObjectName("chartViewVitesseCirculaire");

        verticalLayout_vitesse_circulaire->addWidget(chartViewVitesseCirculaire);

        tabWidgetVitesse->addTab(tab_vitesse_circulaire, QString());

        gridLayout_2->addWidget(tabWidgetVitesse, 0, 0, 1, 1);

        tabWidget->addTab(tabVitesse, QString());
        tabCollisions = new QWidget();
        tabCollisions->setObjectName("tabCollisions");
        gridLayout_3 = new QGridLayout(tabCollisions);
        gridLayout_3->setObjectName("gridLayout_3");
        tabWidgetCollisions = new QTabWidget(tabCollisions);
        tabWidgetCollisions->setObjectName("tabWidgetCollisions");
        tabCollisionsCourbe = new QWidget();
        tabCollisionsCourbe->setObjectName("tabCollisionsCourbe");
        gridLayout_6 = new QGridLayout(tabCollisionsCourbe);
        gridLayout_6->setObjectName("gridLayout_6");
        chartViewCollisionsCourbe = new QChartView(tabCollisionsCourbe);
        chartViewCollisionsCourbe->setObjectName("chartViewCollisionsCourbe");

        gridLayout_6->addWidget(chartViewCollisionsCourbe, 0, 0, 1, 1);

        tabWidgetCollisions->addTab(tabCollisionsCourbe, QString());
        tabCollisionsBarres = new QWidget();
        tabCollisionsBarres->setObjectName("tabCollisionsBarres");
        gridLayout_7 = new QGridLayout(tabCollisionsBarres);
        gridLayout_7->setObjectName("gridLayout_7");
        chartViewCollisionsBarres = new QChartView(tabCollisionsBarres);
        chartViewCollisionsBarres->setObjectName("chartViewCollisionsBarres");

        gridLayout_7->addWidget(chartViewCollisionsBarres, 0, 0, 1, 1);

        tabWidgetCollisions->addTab(tabCollisionsBarres, QString());
        tabCollisionsCirculaire = new QWidget();
        tabCollisionsCirculaire->setObjectName("tabCollisionsCirculaire");
        gridLayout_8 = new QGridLayout(tabCollisionsCirculaire);
        gridLayout_8->setObjectName("gridLayout_8");
        chartViewCollisionsCirculaire = new QChartView(tabCollisionsCirculaire);
        chartViewCollisionsCirculaire->setObjectName("chartViewCollisionsCirculaire");

        gridLayout_8->addWidget(chartViewCollisionsCirculaire, 0, 0, 1, 1);

        tabWidgetCollisions->addTab(tabCollisionsCirculaire, QString());

        gridLayout_3->addWidget(tabWidgetCollisions, 0, 0, 1, 1);

        tabWidget->addTab(tabCollisions, QString());
        tabTableau = new QWidget();
        tabTableau->setObjectName("tabTableau");
        verticalLayout_3 = new QVBoxLayout(tabTableau);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableWidgetResultats = new QTableWidget(tabTableau);
        if (tableWidgetResultats->columnCount() < 4)
            tableWidgetResultats->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetResultats->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetResultats->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetResultats->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetResultats->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetResultats->setObjectName("tableWidgetResultats");

        verticalLayout_3->addWidget(tableWidgetResultats);

        tabWidget->addTab(tabTableau, QString());
        tabEvolution = new QWidget();
        tabEvolution->setObjectName("tabEvolution");
        gridLayout_evolution = new QGridLayout(tabEvolution);
        gridLayout_evolution->setObjectName("gridLayout_evolution");
        tabWidgetEvolution = new QTabWidget(tabEvolution);
        tabWidgetEvolution->setObjectName("tabWidgetEvolution");
        tabEvolutionCollisions = new QWidget();
        tabEvolutionCollisions->setObjectName("tabEvolutionCollisions");
        verticalLayout_evo_coll = new QVBoxLayout(tabEvolutionCollisions);
        verticalLayout_evo_coll->setObjectName("verticalLayout_evo_coll");
        chartViewEvolutionCollisions = new QChartView(tabEvolutionCollisions);
        chartViewEvolutionCollisions->setObjectName("chartViewEvolutionCollisions");

        verticalLayout_evo_coll->addWidget(chartViewEvolutionCollisions);

        tabWidgetEvolution->addTab(tabEvolutionCollisions, QString());
        tabEvolutionVitesse = new QWidget();
        tabEvolutionVitesse->setObjectName("tabEvolutionVitesse");
        verticalLayout_evo_vit = new QVBoxLayout(tabEvolutionVitesse);
        verticalLayout_evo_vit->setObjectName("verticalLayout_evo_vit");
        label_evo_ins = new QLabel(tabEvolutionVitesse);
        label_evo_ins->setObjectName("label_evo_ins");
        label_evo_ins->setAlignment(Qt::AlignCenter);

        verticalLayout_evo_vit->addWidget(label_evo_ins);

        chartViewEvolutionVitesseInsertion = new QChartView(tabEvolutionVitesse);
        chartViewEvolutionVitesseInsertion->setObjectName("chartViewEvolutionVitesseInsertion");

        verticalLayout_evo_vit->addWidget(chartViewEvolutionVitesseInsertion);

        label_evo_rech = new QLabel(tabEvolutionVitesse);
        label_evo_rech->setObjectName("label_evo_rech");
        label_evo_rech->setAlignment(Qt::AlignCenter);

        verticalLayout_evo_vit->addWidget(label_evo_rech);

        chartViewEvolutionVitesseRecherche = new QChartView(tabEvolutionVitesse);
        chartViewEvolutionVitesseRecherche->setObjectName("chartViewEvolutionVitesseRecherche");

        verticalLayout_evo_vit->addWidget(chartViewEvolutionVitesseRecherche);

        tabWidgetEvolution->addTab(tabEvolutionVitesse, QString());

        gridLayout_evolution->addWidget(tabWidgetEvolution, 0, 0, 1, 1);

        tabWidget->addTab(tabEvolution, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(ComparaisonDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ComparaisonDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ComparaisonDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ComparaisonDialog, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(0);
        tabWidgetEvolution->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ComparaisonDialog);
    } // setupUi

    void retranslateUi(QDialog *ComparaisonDialog)
    {
        ComparaisonDialog->setWindowTitle(QCoreApplication::translate("ComparaisonDialog", "Dialog", nullptr));
        tabWidgetVitesse->setTabText(tabWidgetVitesse->indexOf(tab_3), QCoreApplication::translate("ComparaisonDialog", "Courbe", nullptr));
        tabWidgetVitesse->setTabText(tabWidgetVitesse->indexOf(tab_vitesse_barres), QCoreApplication::translate("ComparaisonDialog", "Barres", nullptr));
        tabWidgetVitesse->setTabText(tabWidgetVitesse->indexOf(tab_vitesse_circulaire), QCoreApplication::translate("ComparaisonDialog", "Circulaire", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabVitesse), QCoreApplication::translate("ComparaisonDialog", "Vitesse", nullptr));
        tabWidgetCollisions->setTabText(tabWidgetCollisions->indexOf(tabCollisionsCourbe), QCoreApplication::translate("ComparaisonDialog", "Courbe", nullptr));
        tabWidgetCollisions->setTabText(tabWidgetCollisions->indexOf(tabCollisionsBarres), QCoreApplication::translate("ComparaisonDialog", "Barres", nullptr));
        tabWidgetCollisions->setTabText(tabWidgetCollisions->indexOf(tabCollisionsCirculaire), QCoreApplication::translate("ComparaisonDialog", "Circulaire", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCollisions), QCoreApplication::translate("ComparaisonDialog", "Collisions", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetResultats->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ComparaisonDialog", "Collisions", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetResultats->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ComparaisonDialog", "Taux d'Occupation", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetResultats->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ComparaisonDialog", "Temps d'Insertion", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetResultats->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ComparaisonDialog", "Temps de Recherche", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTableau), QCoreApplication::translate("ComparaisonDialog", "Tableau D\303\251taill\303\251", nullptr));
        tabWidgetEvolution->setTabText(tabWidgetEvolution->indexOf(tabEvolutionCollisions), QCoreApplication::translate("ComparaisonDialog", "\303\211volution des Collisions", nullptr));
        label_evo_ins->setText(QCoreApplication::translate("ComparaisonDialog", "\303\211volution du Temps d'Insertion", nullptr));
        label_evo_rech->setText(QCoreApplication::translate("ComparaisonDialog", "\303\211volution du Temps de Recherche", nullptr));
        tabWidgetEvolution->setTabText(tabWidgetEvolution->indexOf(tabEvolutionVitesse), QCoreApplication::translate("ComparaisonDialog", "\303\211volution de la Vitesse", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEvolution), QCoreApplication::translate("ComparaisonDialog", "\303\211volution", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComparaisonDialog: public Ui_ComparaisonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARAISONDIALOG_H
