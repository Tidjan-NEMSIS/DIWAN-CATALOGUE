#include "dialog_maison.h"
#include "ui_dialog_maison.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QLabel>
#include <QRegularExpressionValidator>

DialogMaison::DialogMaison(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogMaison)
    , m_maison(new Maison())
    , m_estModification(false)
{
    ui->setupUi(this);
    initialiserUI();
    setWindowTitle("Ajouter une maison");
}

DialogMaison::DialogMaison(Maison* maison, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogMaison)
    , m_maison(maison)
    , m_estModification(true)
{
    ui->setupUi(this);
    initialiserUI();
    setWindowTitle("Modifier une maison");
    
    // Remplir les champs avec les données existantes
    ui->lineEditId->setText(m_maison->getId());
    ui->lineEditId->setReadOnly(true); // L'ID ne peut pas être modifié
    ui->lineEditType->setText(m_maison->getType());
    ui->lineEditStanding->setText(m_maison->getStanding());
    ui->spinBoxChambres->setValue(m_maison->getChambres());
    ui->spinBoxToilettes->setValue(m_maison->getToilettes());
    ui->textEditDescription->setText(m_maison->getDescription());
    
    // Charger les photos existantes
    if (!m_maison->getPhoto1().isEmpty()) {
        ui->labelPhoto1->setPixmap(QPixmap(m_maison->getPhoto1()).scaled(150, 150, Qt::KeepAspectRatio));
    }
    if (!m_maison->getPhoto2().isEmpty()) {
        ui->labelPhoto2->setPixmap(QPixmap(m_maison->getPhoto2()).scaled(150, 150, Qt::KeepAspectRatio));
    }
    if (!m_maison->getPhoto3().isEmpty()) {
        ui->labelPhoto3->setPixmap(QPixmap(m_maison->getPhoto3()).scaled(150, 150, Qt::KeepAspectRatio));
    }
    if (!m_maison->getPhoto4().isEmpty()) {
        ui->labelPhoto4->setPixmap(QPixmap(m_maison->getPhoto4()).scaled(150, 150, Qt::KeepAspectRatio));
    }
}

DialogMaison::~DialogMaison()
{
    delete ui;
    if (!m_estModification) {
        delete m_maison;
    }
}

void DialogMaison::initialiserUI()
{
    // Configurer les validations
    ui->lineEditId->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z0-9]+"), this));
    ui->lineEditType->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-z ]+"), this));
    ui->lineEditStanding->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Za-z ]+"), this));
    
    // Configurer les limites des spinboxes
    ui->spinBoxChambres->setRange(1, 20);
    ui->spinBoxToilettes->setRange(1, 10);
    
    // Configurer les labels de photos
    ui->labelPhoto1->setMinimumSize(150, 150);
    ui->labelPhoto2->setMinimumSize(150, 150);
    ui->labelPhoto3->setMinimumSize(150, 150);
    ui->labelPhoto4->setMinimumSize(150, 150);
    
    // Connecter les signaux
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogMaison::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DialogMaison::on_buttonBox_rejected);
}

void DialogMaison::chargerPhoto(int index)
{
    QString chemin = QFileDialog::getOpenFileName(this,
        "Choisir une photo", "",
        "Images (*.png *.jpg *.jpeg *.bmp)");
    if (chemin.isEmpty()) return;
    QLabel* label = nullptr;
    switch (index) {
        case 0:
            label = ui->labelPhoto1;
            m_maison->setPhoto1(chemin);
            break;
        case 1:
            label = ui->labelPhoto2;
            m_maison->setPhoto2(chemin);
            break;
        case 2:
            label = ui->labelPhoto3;
            m_maison->setPhoto3(chemin);
            break;
        case 3:
            label = ui->labelPhoto4;
            m_maison->setPhoto4(chemin);
            break;
    }
    if (label) {
        QPixmap pixmap(chemin);
        if (!pixmap.isNull()) {
            label->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio));
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de charger l'image");
        }
    }
}

void DialogMaison::on_btnPhoto1_clicked() { chargerPhoto(0); }
void DialogMaison::on_btnPhoto2_clicked() { chargerPhoto(1); }
void DialogMaison::on_btnPhoto3_clicked() { chargerPhoto(2); }
void DialogMaison::on_btnPhoto4_clicked() { chargerPhoto(3); }

bool DialogMaison::validerFormulaire()
{
    if (ui->lineEditId->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID est obligatoire");
        return false;
    }
    if (ui->lineEditType->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le type est obligatoire");
        return false;
    }
    if (ui->lineEditStanding->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le standing est obligatoire");
        return false;
    }
    return true;
}

void DialogMaison::sauvegarderDonnees()
{
    m_maison->setId(ui->lineEditId->text());
    m_maison->setType(ui->lineEditType->text());
    m_maison->setStanding(ui->lineEditStanding->text());
    m_maison->setChambres(ui->spinBoxChambres->value());
    m_maison->setToilettes(ui->spinBoxToilettes->value());
    m_maison->setDescription(ui->textEditDescription->toPlainText());
}

void DialogMaison::on_buttonBox_accepted()
{
    if (!validerFormulaire()) {
        return;
    }
    
    sauvegarderDonnees();
    accept();
}

void DialogMaison::on_buttonBox_rejected()
{
    reject();
} 