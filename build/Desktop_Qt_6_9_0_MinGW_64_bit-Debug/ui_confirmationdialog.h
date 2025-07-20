/********************************************************************************
** Form generated from reading UI file 'confirmationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATIONDIALOG_H
#define UI_CONFIRMATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfirmationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QLabel *detailsLabel;
    QLabel *imageLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfirmationDialog)
    {
        if (ConfirmationDialog->objectName().isEmpty())
            ConfirmationDialog->setObjectName("ConfirmationDialog");
        ConfirmationDialog->resize(400, 380);
        verticalLayout = new QVBoxLayout(ConfirmationDialog);
        verticalLayout->setObjectName("verticalLayout");
        messageLabel = new QLabel(ConfirmationDialog);
        messageLabel->setObjectName("messageLabel");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        messageLabel->setFont(font);
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setWordWrap(true);

        verticalLayout->addWidget(messageLabel);

        detailsLabel = new QLabel(ConfirmationDialog);
        detailsLabel->setObjectName("detailsLabel");
        detailsLabel->setAlignment(Qt::AlignCenter);
        detailsLabel->setWordWrap(true);

        verticalLayout->addWidget(detailsLabel);

        imageLabel = new QLabel(ConfirmationDialog);
        imageLabel->setObjectName("imageLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setMinimumSize(QSize(0, 200));
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(imageLabel);

        buttonBox = new QDialogButtonBox(ConfirmationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ConfirmationDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ConfirmationDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ConfirmationDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ConfirmationDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmationDialog)
    {
        ConfirmationDialog->setWindowTitle(QCoreApplication::translate("ConfirmationDialog", "Confirmation", nullptr));
        messageLabel->setText(QCoreApplication::translate("ConfirmationDialog", "Voulez-vous vraiment effectuer cette action ?", nullptr));
        detailsLabel->setText(QCoreApplication::translate("ConfirmationDialog", "D\303\251tails...", nullptr));
        imageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfirmationDialog: public Ui_ConfirmationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATIONDIALOG_H
