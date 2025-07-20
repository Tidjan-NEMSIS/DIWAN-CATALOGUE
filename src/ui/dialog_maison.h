#ifndef DIALOG_MAISON_H
#define DIALOG_MAISON_H

#include <QDialog>
#include <QString>
#include "../models/maison.h"

namespace Ui {
class DialogMaison;
}

class DialogMaison : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMaison(QWidget *parent = nullptr);
    DialogMaison(Maison* maison, QWidget *parent = nullptr);
    ~DialogMaison();

    Maison* getMaison() const { return m_maison; }

private slots:
    void on_btnPhoto1_clicked();
    void on_btnPhoto2_clicked();
    void on_btnPhoto3_clicked();
    void on_btnPhoto4_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogMaison *ui;
    Maison* m_maison;
    bool m_estModification;

    void initialiserUI();
    void chargerPhoto(int index);
    bool validerFormulaire();
    void sauvegarderDonnees();
};

#endif // DIALOG_MAISON_H 