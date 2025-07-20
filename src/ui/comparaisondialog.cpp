#include "comparaisondialog.h"
#include "ui_comparaisondialog.h"
#include <QElapsedTimer>
#include <QDebug>
#include <QMessageBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarCategoryAxis>

// Fonction utilitaire pour obtenir le nom d'une fonction de hachage
QString getNomFonctionHachage(TableHachage::FonctionHachageType type) {
    switch (type) {
    case TableHachage::F1: return "F1 - Somme des codes ASCII";
    case TableHachage::F2: return "F2 - Polynôme de Horner";
    case TableHachage::F3: return "F3 - Multiplication par un nombre premier";
    case TableHachage::SANS_HACHAGE: return "Sans Hachage (Linéaire)";
    default: return "Inconnue";
    }
}

ComparaisonDialog::ComparaisonDialog(const QVector<Maison*>& maisons, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComparaisonDialog),
    m_maisons(maisons)
{
    ui->setupUi(this);
    setWindowTitle("Comparaison des Fonctions de Hachage");

    // Amélioration du style pour la lisibilité des onglets sur thème sombre
    setStyleSheet("QTabBar::tab { color: white; } "
                  "QTabWidget::pane { border: none; } "
                  "QTabBar::tab:selected { background: #555; border-radius: 4px; }" );

    // Lancer les comparaisons et initialiser tous les graphiques
    lancerToutesLesComparaisons();
    initialiserGraphiques(); // Gère les graphiques statiques

    lancerSimulationEvolution();
    initialiserGraphiquesEvolution(); // Gère les nouveaux graphiques d'évolution
}

ComparaisonDialog::~ComparaisonDialog()
{
    delete ui;
}

void ComparaisonDialog::lancerToutesLesComparaisons()
{
    m_resultatsF1 = lancerComparaison(TableHachage::F1, m_maisons);
    m_resultatsF2 = lancerComparaison(TableHachage::F2, m_maisons);
    m_resultatsF3 = lancerComparaison(TableHachage::F3, m_maisons);
    m_resultatsSansHachage = lancerComparaison(TableHachage::SANS_HACHAGE, m_maisons);
}

ComparaisonDialog::ResultatsHachage ComparaisonDialog::lancerComparaison(TableHachage::FonctionHachageType type, const QVector<Maison*>& maisonsCibles)
{
    if (maisonsCibles.isEmpty()) {
        return {0, 0.0, 0.0, 0.0};
    }

    TableHachage table(maisonsCibles.size());
    table.setFonctionHachage(type);
    ResultatsHachage res;

    // Temps d'insertion
    QElapsedTimer timerInsertion;
    timerInsertion.start();
    for (const Maison* maisonOriginal : maisonsCibles) {
        Maison* maisonCopie = new Maison(*maisonOriginal);
        table.inserer(maisonCopie->getId(), maisonCopie);
    }
    res.tempsInsertion = timerInsertion.nsecsElapsed() / 1000000.0; // en millisecondes

    // Temps de recherche
    QElapsedTimer timerRecherche;
    timerRecherche.start();
    for (Maison* maison : maisonsCibles) {
        table.get(maison->getId());
    }
    res.tempsRecherche = timerRecherche.nsecsElapsed() / 1000000.0; // en millisecondes

    res.collisions = table.getNombreCollisions();
    res.tauxOccupation = table.getTauxOccupation();
    return res;
}

void ComparaisonDialog::initialiserGraphiques()
{
    // Couleurs cohérentes pour chaque fonction
    QColor colorF1 = QColor("#3498db");        // Bleu
    QColor colorF2 = QColor("#2ecc71");        // Vert
    QColor colorF3 = QColor("#e74c3c");        // Rouge
    QColor colorSansHachage = QColor("#f1c40f"); // Jaune

    // Appliquer un style aux onglets pour une meilleure lisibilité
    QString tabStyle = R"(
        QTabBar::tab {
            color: black; 
            padding: 8px;
        }
        QTabBar::tab:selected {
            background: lightgray;
        }
    )";
    ui->tabWidget->setStyleSheet(tabStyle);
    ui->tabWidgetCollisions->setStyleSheet(tabStyle);

    // === ONGLET VITESSE ===
    initialiserGraphiqueVitesse(colorF1, colorF2, colorF3, colorSansHachage);

    // === ONGLET COLLISIONS ===
    initialiserGraphiquesCollisions(colorF1, colorF2, colorF3, colorSansHachage);

    // --- Remplissage et style du tableau ---
    ui->tableWidgetResultats->setRowCount(4);
    ui->tableWidgetResultats->setColumnCount(4);
    ui->tableWidgetResultats->setVerticalHeaderLabels({"F1", "F2", "F3", "Sans Hachage"});
    ui->tableWidgetResultats->setHorizontalHeaderLabels({"Collisions", "Taux d'Occupation", "Temps Insertion", "Temps Recherche"});

    // Style du tableau
    ui->tableWidgetResultats->setStyleSheet(R"(
        QTableWidget {
            gridline-color: #d0d0d0;
            font-size: 14px;
        }
        QHeaderView::section {
            background-color: #34495e;
            color: white;
            padding: 6px;
            border: 1px solid #2c3e50;
            font-weight: bold;
        }
        QTableWidget::item {
            padding: 6px;
        }
    )");
    ui->tableWidgetResultats->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetResultats->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    auto setTableItem = [&](int row, int col, const QVariant& value, const QString& suffix = "") {
        QString text = value.toString();
        if (value.typeId() == QMetaType::fromType<double>().id()) {
            text = QString::number(value.toDouble(), 'f', 4);
        }
        ui->tableWidgetResultats->setItem(row, col, new QTableWidgetItem(text + suffix));
    };

    // F1
    setTableItem(0, 0, m_resultatsF1.collisions);
    setTableItem(0, 1, m_resultatsF1.tauxOccupation, " %");
    setTableItem(0, 2, m_resultatsF1.tempsInsertion, " ms");
    setTableItem(0, 3, m_resultatsF1.tempsRecherche, " ms");

    // F2
    setTableItem(1, 0, m_resultatsF2.collisions);
    setTableItem(1, 1, m_resultatsF2.tauxOccupation, " %");
    setTableItem(1, 2, m_resultatsF2.tempsInsertion, " ms");
    setTableItem(1, 3, m_resultatsF2.tempsRecherche, " ms");

    // F3
    setTableItem(2, 0, m_resultatsF3.collisions);
    setTableItem(2, 1, m_resultatsF3.tauxOccupation, " %");
    setTableItem(2, 2, m_resultatsF3.tempsInsertion, " ms");
    setTableItem(2, 3, m_resultatsF3.tempsRecherche, " ms");

    // Sans Hachage
    setTableItem(3, 0, m_resultatsSansHachage.collisions);
    setTableItem(3, 1, m_resultatsSansHachage.tauxOccupation, " %");
    setTableItem(3, 2, m_resultatsSansHachage.tempsInsertion, " ms");
    setTableItem(3, 3, m_resultatsSansHachage.tempsRecherche, " ms");
}

void ComparaisonDialog::initialiserGraphiqueVitesse(const QColor& c1, const QColor& c2, const QColor& c3, const QColor& c4)
{
    QList<ResultatsHachage> resultats = {m_resultatsF1, m_resultatsF2, m_resultatsF3, m_resultatsSansHachage};
    QList<QColor> colors = {c1, c2, c3, c4};
    QStringList functionNames = {"F1", "F2", "F3", "Sans Hachage"};

    // === 1. Graphique en Courbes ===
    {
        QChart *chart = new QChart();
        chart->setTitle("Comparaison des Temps d'Exécution (Courbe)");
        
        for (int i = 0; i < resultats.size(); ++i) {
            QLineSeries *series = new QLineSeries();
            series->setName(functionNames[i]);
            *series << QPointF(resultats[i].tempsInsertion, 0) << QPointF(resultats[i].tempsRecherche, 1);
            QPen pen(colors[i]);
            pen.setWidth(2);
            series->setPen(pen);
            chart->addSeries(series);
        }

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Temps (ms)");
        chart->addAxis(axisX, Qt::AlignBottom);

        QCategoryAxis *axisY = new QCategoryAxis();
        axisY->append("Insertion", 0);
        axisY->append("Recherche", 1);
        axisY->setTitleText("Opération");
        chart->addAxis(axisY, Qt::AlignLeft);

        for (QAbstractSeries *s : chart->series()) { 
            s->attachAxis(axisX);
            s->attachAxis(axisY);
        }
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        ui->chartViewVitesseCourbe->setChart(chart);
    }

    // === 2. Graphique en Barres ===
    {
        QChart *chart = new QChart();
        chart->setTitle("Comparaison des Temps d'Exécution (Barres)");
        QBarSeries *series = new QBarSeries();
        QBarSet *setInsertion = new QBarSet("Insertion");
        QBarSet *setRecherche = new QBarSet("Recherche");
        for(const auto& res : resultats) {
            *setInsertion << res.tempsInsertion;
            *setRecherche << res.tempsRecherche;
        }
        series->append(setInsertion);
        series->append(setRecherche);
        chart->addSeries(series);
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(functionNames);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Temps (ms)");
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        ui->chartViewVitesseBarres->setChart(chart);
    }

    // === 3. Graphique Circulaire ===
    {
        QChart *chart = new QChart();
        chart->setTitle("Répartition du Temps Total");
        QPieSeries *series = new QPieSeries();
        qreal totalTime = 0;
        for(const auto& res : resultats) totalTime += res.tempsInsertion + res.tempsRecherche;
        for (int i = 0; i < resultats.size(); ++i) {
            qreal time = resultats[i].tempsInsertion + resultats[i].tempsRecherche;
            if (time > 0) {
                QPieSlice *slice = series->append(functionNames[i], time);
                slice->setColor(colors[i]);
                slice->setLabel(QString("%1\n%2%").arg(functionNames[i]).arg(100 * time / totalTime, 0, 'f', 1));
                slice->setLabelVisible();
            }
        }
        chart->addSeries(series);
        ui->chartViewVitesseCirculaire->setChart(chart);
    }
}

void ComparaisonDialog::initialiserGraphiquesCollisions(const QColor& c1, const QColor& c2, const QColor& c3, const QColor& c4)
{
    // --- Données et couleurs communes ---
    QStringList categories = {"F1", "F2", "F3", "Sans Hachage"};
    QList<qreal> collisions = {
        (qreal)m_resultatsF1.collisions,
        (qreal)m_resultatsF2.collisions,
        (qreal)m_resultatsF3.collisions,
        (qreal)m_resultatsSansHachage.collisions
    };
    QList<QColor> colors = {c1, c2, c3, c4};

    // --- 1. Graphique en Courbe ---
    {
        QChart *chart = new QChart();
        chart->setTitle("Comparaison des Collisions");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        for (int i = 0; i < categories.size(); ++i) {
            QLineSeries *series = new QLineSeries();
            series->setName(categories[i]);
            *series << QPointF(0, i) << QPointF(collisions[i], i);
            QPen pen(colors[i]);
            pen.setWidth(2);
            series->setPen(pen);
            chart->addSeries(series);
        }

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Nombre de Collisions");
        chart->addAxis(axisX, Qt::AlignBottom);

        QCategoryAxis *axisY = new QCategoryAxis();
        for(int i = 0; i < categories.size(); ++i) {
            axisY->append(categories[i], i);
        }
        axisY->setTitleText("Fonctions");
        chart->addAxis(axisY, Qt::AlignLeft);

        for(auto* series : chart->series()) {
            series->attachAxis(axisX);
            series->attachAxis(axisY);
        }

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        ui->chartViewCollisionsCourbe->setChart(chart);
        ui->chartViewCollisionsCourbe->setRenderHint(QPainter::Antialiasing);
    }

    // --- 2. Graphique en Barres ---
    QChart *chartBarres = new QChart();
    chartBarres->setTitle("Comparaison des Collisions");
    chartBarres->setAnimationOptions(QChart::SeriesAnimations);

    QBarSeries *seriesBarres = new QBarSeries();
    for (int i = 0; i < categories.size(); ++i) {
        QBarSet *set = new QBarSet(categories[i]);
        *set << collisions[i];
        set->setColor(colors[i]);
        seriesBarres->append(set);
    }
    chartBarres->addSeries(seriesBarres);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(""); // Une seule catégorie pour grouper les barres
    chartBarres->addAxis(axisX, Qt::AlignBottom);
    seriesBarres->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chartBarres->addAxis(axisY, Qt::AlignLeft);
    seriesBarres->attachAxis(axisY);

    chartBarres->legend()->setVisible(true);
    chartBarres->legend()->setAlignment(Qt::AlignBottom);
    ui->chartViewCollisionsBarres->setChart(chartBarres);
    ui->chartViewCollisionsBarres->setRenderHint(QPainter::Antialiasing);

    // --- 3. Graphique Circulaire ---
    QChart *chartCirculaire = new QChart();
    chartCirculaire->setTitle("Répartition des Collisions");
    chartCirculaire->setAnimationOptions(QChart::SeriesAnimations);

    QPieSeries *seriesCirculaire = new QPieSeries();
    seriesCirculaire->setHoleSize(0.35);

    qreal totalCollisions = 0;
    for(qreal val : collisions) totalCollisions += val;

    for (int i = 0; i < categories.size(); ++i) {
        if (collisions[i] > 0) {
            QPieSlice *slice = seriesCirculaire->append(categories[i], collisions[i]);
            slice->setColor(colors[i]);
            slice->setLabelVisible();
            if (totalCollisions > 0) {
                slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(100 * slice->value() / totalCollisions, 0, 'f', 1));
            }
        }
    }

    chartCirculaire->addSeries(seriesCirculaire);
    chartCirculaire->legend()->setVisible(true);
    chartCirculaire->legend()->setAlignment(Qt::AlignRight);
    ui->chartViewCollisionsCirculaire->setChart(chartCirculaire);
    ui->chartViewCollisionsCirculaire->setRenderHint(QPainter::Antialiasing);
}

void ComparaisonDialog::lancerSimulationEvolution()
{
    m_resultatsEvolution.clear();
    QVector<double> checkpoints = {0.10, 0.25, 0.50, 0.75, 1.00};

    for (double checkpoint : checkpoints) {
        int subsetSize = static_cast<int>(m_maisons.size() * checkpoint);
        if (subsetSize == 0) continue;

        QVector<Maison*> maisonsSubset;
        maisonsSubset.reserve(subsetSize);
        for(int i = 0; i < subsetSize; ++i) {
            maisonsSubset.append(m_maisons[i]);
        }

        QList<ResultatsHachage> resultatsCheckpoint;
        resultatsCheckpoint.append(lancerComparaison(TableHachage::F1, maisonsSubset));
        resultatsCheckpoint.append(lancerComparaison(TableHachage::F2, maisonsSubset));
        resultatsCheckpoint.append(lancerComparaison(TableHachage::F3, maisonsSubset));
        resultatsCheckpoint.append(lancerComparaison(TableHachage::SANS_HACHAGE, maisonsSubset));

        m_resultatsEvolution[subsetSize] = resultatsCheckpoint;

        qDebug() << "--- Checkpoint: " << subsetSize << " maisons ---";
        qDebug() << "F1: Collisions=" << resultatsCheckpoint[0].collisions << ", InsTime=" << resultatsCheckpoint[0].tempsInsertion << ", SearchTime=" << resultatsCheckpoint[0].tempsRecherche;
        qDebug() << "F2: Collisions=" << resultatsCheckpoint[1].collisions << ", InsTime=" << resultatsCheckpoint[1].tempsInsertion << ", SearchTime=" << resultatsCheckpoint[1].tempsRecherche;
        qDebug() << "F3: Collisions=" << resultatsCheckpoint[2].collisions << ", InsTime=" << resultatsCheckpoint[2].tempsInsertion << ", SearchTime=" << resultatsCheckpoint[2].tempsRecherche;
        qDebug() << "Sans Hachage: Collisions=" << resultatsCheckpoint[3].collisions << ", InsTime=" << resultatsCheckpoint[3].tempsInsertion << ", SearchTime=" << resultatsCheckpoint[3].tempsRecherche;
    }
}

void ComparaisonDialog::initialiserGraphiquesEvolution()
{
    // Couleurs et noms pour la cohérence
    QList<QColor> colors = {QColor("#3498db"), QColor("#2ecc71"), QColor("#e74c3c"), QColor("#f1c40f")};
    QStringList functionNames = {"F1", "F2", "F3", "Sans Hachage"};

    // --- 1. Évolution des Collisions ---
    QChart *chartCollisions = new QChart();
    chartCollisions->setTitle("Évolution du nombre de collisions");
    chartCollisions->setAnimationOptions(QChart::SeriesAnimations);

    for (int i = 0; i < functionNames.size(); ++i) {
        QLineSeries *series = new QLineSeries();
        series->setName(functionNames[i]);
        series->setPen(QPen(colors[i], 2));
        for (auto it = m_resultatsEvolution.constBegin(); it != m_resultatsEvolution.constEnd(); ++it) {
            series->append(it.key(), it.value()[i].collisions);
        }
        chartCollisions->addSeries(series);
    }

    QValueAxis *axisXCollisions = new QValueAxis;
    axisXCollisions->setTitleText("Nombre d'éléments");
    chartCollisions->addAxis(axisXCollisions, Qt::AlignBottom);

    QValueAxis *axisYCollisions = new QValueAxis;
    axisYCollisions->setTitleText("Nombre de collisions");
    axisYCollisions->setRange(0, 10); // Plage minimale pour la visibilité
    chartCollisions->addAxis(axisYCollisions, Qt::AlignLeft);

    for(auto* s : chartCollisions->series()) {
        s->attachAxis(axisXCollisions);
        s->attachAxis(axisYCollisions);
    }
    chartCollisions->legend()->setVisible(true);
    ui->chartViewEvolutionCollisions->setChart(chartCollisions);
    ui->chartViewEvolutionCollisions->setRenderHint(QPainter::Antialiasing);

    // --- 2. Évolution de la Vitesse ---
    QChart *chartVitesseInsertion = new QChart();
    chartVitesseInsertion->setTitle("Temps d'insertion");
    QChart *chartVitesseRecherche = new QChart();
    chartVitesseRecherche->setTitle("Temps de recherche");

    for (int i = 0; i < functionNames.size(); ++i) {
        QLineSeries *seriesInsertion = new QLineSeries();
        QLineSeries *seriesRecherche = new QLineSeries();
        seriesInsertion->setName(functionNames[i]);
        seriesRecherche->setName(functionNames[i]);
        seriesInsertion->setPen(QPen(colors[i], 2));
        seriesRecherche->setPen(QPen(colors[i], 2));

        for (auto it = m_resultatsEvolution.constBegin(); it != m_resultatsEvolution.constEnd(); ++it) {
            seriesInsertion->append(it.key(), it.value()[i].tempsInsertion);
            seriesRecherche->append(it.key(), it.value()[i].tempsRecherche);
        }
        chartVitesseInsertion->addSeries(seriesInsertion);
        chartVitesseRecherche->addSeries(seriesRecherche);
    }

    QValueAxis *axisXVitesse = new QValueAxis;
    axisXVitesse->setTitleText("Nombre d'éléments");
    chartVitesseInsertion->addAxis(axisXVitesse, Qt::AlignBottom);

    QValueAxis *axisXVitesseRecherche = new QValueAxis;
    axisXVitesseRecherche->setTitleText("Nombre d'éléments");
    chartVitesseRecherche->addAxis(axisXVitesseRecherche, Qt::AlignBottom);

    QValueAxis *axisYVitesse = new QValueAxis;
    axisYVitesse->setTitleText("Temps (ms)");
    axisYVitesse->setRange(0, 1); // Plage minimale pour la visibilité
    chartVitesseInsertion->addAxis(axisYVitesse, Qt::AlignLeft);

    QValueAxis *axisYVitesseRecherche = new QValueAxis;
    axisYVitesseRecherche->setTitleText("Temps (ms)");
    axisYVitesseRecherche->setRange(0, 1); // Plage minimale pour la visibilité
    chartVitesseRecherche->addAxis(axisYVitesseRecherche, Qt::AlignLeft);

    for(auto* s : chartVitesseInsertion->series()) {
        s->attachAxis(axisXVitesse);
        s->attachAxis(axisYVitesse);
    }
    for(auto* s : chartVitesseRecherche->series()) {
        s->attachAxis(axisXVitesseRecherche);
        s->attachAxis(axisYVitesseRecherche);
    }

    chartVitesseInsertion->legend()->setVisible(false);
    chartVitesseRecherche->legend()->setVisible(true);
    ui->chartViewEvolutionVitesseInsertion->setChart(chartVitesseInsertion);
    ui->chartViewEvolutionVitesseRecherche->setChart(chartVitesseRecherche);
    ui->chartViewEvolutionVitesseInsertion->setRenderHint(QPainter::Antialiasing);
    ui->chartViewEvolutionVitesseRecherche->setRenderHint(QPainter::Antialiasing);
}
