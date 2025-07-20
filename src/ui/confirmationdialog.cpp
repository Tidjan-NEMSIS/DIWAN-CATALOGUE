#include "confirmationdialog.h"
#include "ui_confirmationdialog.h"
#include <QPushButton>

ConfirmationDialog::ConfirmationDialog(const QString &title, const QString &message, const QString &details, const QPixmap &image, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);
    setWindowIcon(QIcon(":/icons/logo.png"));

    ui->messageLabel->setText(message);
    ui->detailsLabel->setText(details);

    if (!image.isNull()) {
        ui->imageLabel->setPixmap(image.scaled(ui->imageLabel->width(), 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->imageLabel->setText("Image non disponible");
        ui->imageLabel->setMinimumHeight(50); // Réduire la hauteur si pas d'image
    }

    // Assurez-vous que buttonBox est bien dans votre .ui
    // Si vous utilisez les boutons standard Ok/Cancel, ils sont déjà connectés.
    // Sinon, il faudra les connecter manuellement.
    // Par exemple, si vous avez un QDialogButtonBox nommé 'buttonBox':
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Confirmer");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Annuler");
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete ui;
}
