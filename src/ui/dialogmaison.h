#ifndef DIALOGMAISON_H
#define DIALOGMAISON_H

#include <QDialog>
#include <QStringList>
#include "../models/maison.h"

// Forward declaration
namespace Ui {
class DialogMaison;
}
class QLabel;

class DialogMaison : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMaison(QWidget *parent = nullptr); // Pour l'insertion
    explicit DialogMaison(const Maison& maison, QWidget *parent = nullptr); // Pour la modification
    ~DialogMaison();

    Maison getMaison() const;
    void setMaison(const Maison& maison);

private slots:
    void on_btnPhoto1_clicked();
    void on_btnPhoto2_clicked();
    void on_btnPhoto3_clicked();
    void on_btnPhoto4_clicked();

private:
    void choisirPhoto(QLabel* label, QString& photoPath);

    Ui::DialogMaison *ui;
    QString m_photoPath1;
    QString m_photoPath2;
    QString m_photoPath3;
    QString m_photoPath4;
};

#endif // DIALOGMAISON_H
