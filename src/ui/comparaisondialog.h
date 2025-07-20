#ifndef COMPARAISONDIALOG_H
#define COMPARAISONDIALOG_H

#include <QDialog>
#include <QMap>
#include <QList>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QValueAxis>

#include "../models/table_hachage.h"

namespace Ui {
class ComparaisonDialog;
}

class ComparaisonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComparaisonDialog(const QVector<Maison*>& maisons, QWidget *parent = nullptr);
    ~ComparaisonDialog();

private:
    // Structures pour stocker les résultats
    struct ResultatsHachage {
        int collisions;
        double tauxOccupation;
        double tempsInsertion; // en millisecondes
        double tempsRecherche; // en millisecondes
    };

    // Méthodes pour les graphiques de comparaison statique
    void initialiserGraphiques();
    void initialiserGraphiqueVitesse(const QColor& c1, const QColor& c2, const QColor& c3, const QColor& c4);
    void initialiserGraphiquesCollisions(const QColor& c1, const QColor& c2, const QColor& c3, const QColor& c4);

    // Méthodes pour la simulation et les graphiques d'évolution
    void lancerSimulationEvolution();
    void initialiserGraphiquesEvolution();

    // Logique de comparaison
    void lancerToutesLesComparaisons();
    ResultatsHachage lancerComparaison(TableHachage::FonctionHachageType type, const QVector<Maison*>& maisonsCibles);

    Ui::ComparaisonDialog *ui;
    const QVector<Maison*>& m_maisons;

    // Données pour la comparaison statique
    ResultatsHachage m_resultatsF1;
    ResultatsHachage m_resultatsF2;
    ResultatsHachage m_resultatsF3;
    ResultatsHachage m_resultatsSansHachage;

    // Données pour la simulation d'évolution
    QMap<int, QList<ResultatsHachage>> m_resultatsEvolution;
};

#endif // COMPARAISONDIALOG_H
