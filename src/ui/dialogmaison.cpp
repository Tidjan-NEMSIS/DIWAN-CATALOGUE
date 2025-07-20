#include "dialogmaison.h"
#include "ui_dialogmaison.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>

DialogMaison::DialogMaison(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMaison)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

DialogMaison::~DialogMaison()
{
    delete ui;
}

void DialogMaison::choisirPhoto(QLabel* label, QString& photoPath)
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choisir une image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp)"));

    if (!fileName.isEmpty()) {
        photoPath = fileName;
        QPixmap pixmap(fileName);
        label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void DialogMaison::on_btnPhoto1_clicked()
{
    choisirPhoto(ui->labelPhoto1, m_photoPath1);
}

void DialogMaison::on_btnPhoto2_clicked()
{
    choisirPhoto(ui->labelPhoto2, m_photoPath2);
}

void DialogMaison::on_btnPhoto3_clicked()
{
    choisirPhoto(ui->labelPhoto3, m_photoPath3);
}

void DialogMaison::on_btnPhoto4_clicked()
{
    choisirPhoto(ui->labelPhoto4, m_photoPath4);
}

DialogMaison::DialogMaison(const Maison& maison, QWidget *parent) :
    DialogMaison(parent) // Réutiliser le constructeur par défaut
{
    setMaison(maison);
}

void DialogMaison::setMaison(const Maison& maison)
{
    ui->lineEditId->setText(maison.getId());
    ui->lineEditType->setText(maison.getType());
    ui->lineEditStanding->setText(maison.getStanding());
    ui->spinBoxChambres->setValue(maison.getChambres());
    ui->spinBoxToilettes->setValue(maison.getToilettes());
    ui->textEditDescription->setPlainText(maison.getDescription());

    // Empêcher la modification de l'ID
    ui->lineEditId->setEnabled(false);

    // Conserver les chemins des photos et les afficher
    m_photoPath1 = maison.getPhoto1();
    if (!m_photoPath1.isEmpty()) ui->labelPhoto1->setPixmap(QPixmap(m_photoPath1).scaled(ui->labelPhoto1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    m_photoPath2 = maison.getPhoto2();
    if (!m_photoPath2.isEmpty()) ui->labelPhoto2->setPixmap(QPixmap(m_photoPath2).scaled(ui->labelPhoto2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    m_photoPath3 = maison.getPhoto3();
    if (!m_photoPath3.isEmpty()) ui->labelPhoto3->setPixmap(QPixmap(m_photoPath3).scaled(ui->labelPhoto3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    m_photoPath4 = maison.getPhoto4();
    if (!m_photoPath4.isEmpty()) ui->labelPhoto4->setPixmap(QPixmap(m_photoPath4).scaled(ui->labelPhoto4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Maison DialogMaison::getMaison() const
{
    QString id = ui->lineEditId->text();
    QString type = ui->lineEditType->text();
    QString standing = ui->lineEditStanding->text();
    int chambres = ui->spinBoxChambres->value();
    int toilettes = ui->spinBoxToilettes->value();
    QString description = ui->textEditDescription->toPlainText();

    return Maison(id, type, standing, chambres, toilettes, description, m_photoPath1, m_photoPath2, m_photoPath3, m_photoPath4);
}
