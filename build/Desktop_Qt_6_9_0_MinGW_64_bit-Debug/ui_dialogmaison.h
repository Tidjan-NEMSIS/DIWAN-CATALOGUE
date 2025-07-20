/********************************************************************************
** Form generated from reading UI file 'dialogmaison.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMAISON_H
#define UI_DIALOGMAISON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMaison
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditId;
    QLabel *label_2;
    QLineEdit *lineEditType;
    QLabel *label_3;
    QLineEdit *lineEditStanding;
    QLabel *label_4;
    QSpinBox *spinBoxChambres;
    QLabel *label_5;
    QSpinBox *spinBoxToilettes;
    QLabel *label_6;
    QTextEdit *textEditDescription;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelPhoto1;
    QLabel *labelPhoto2;
    QLabel *labelPhoto3;
    QLabel *labelPhoto4;
    QPushButton *btnPhoto1;
    QPushButton *btnPhoto2;
    QPushButton *btnPhoto3;
    QPushButton *btnPhoto4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogMaison)
    {
        if (DialogMaison->objectName().isEmpty())
            DialogMaison->setObjectName("DialogMaison");
        DialogMaison->resize(600, 700);
        DialogMaison->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"      background-color: rgba(30, 30, 30, 0.95);\n"
"      color: #f0f0f0;\n"
"      border-radius: 20px;\n"
"      font-family: 'Segoe UI', 'Arial', sans-serif;\n"
"      font-size: 14px;\n"
"    }\n"
"    QLabel, QGroupBox {\n"
"      color: #f0f0f0;\n"
"    }\n"
"    QLineEdit, QSpinBox, QTextEdit {\n"
"      background-color: rgba(255,255,255,0.08);\n"
"      border-radius: 8px;\n"
"      color: #f0f0f0;\n"
"      border: 1px solid rgba(255,255,255,0.15);\n"
"    }\n"
"    QPushButton {\n"
"      background-color: rgba(255,255,255,0.12);\n"
"      border-radius: 10px;\n"
"      color: #f0f0f0;\n"
"      border: 1px solid rgba(255,255,255,0.18);\n"
"      padding: 6px 18px;\n"
"    }\n"
"    QPushButton:hover {\n"
"      background-color: rgba(255,255,255,0.22);\n"
"    }\n"
"    QGroupBox {\n"
"      background-color: rgba(255,255,255,0.10);\n"
"      border-radius: 15px;\n"
"      border: 1px solid rgba(255,255,255,0.18);\n"
"      margin-top: 10px;\n"
"      font-weight: bold;\n"
" "
                        "   }\n"
"   "));
        verticalLayout = new QVBoxLayout(DialogMaison);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DialogMaison);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEditId = new QLineEdit(DialogMaison);
        lineEditId->setObjectName("lineEditId");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditId);

        label_2 = new QLabel(DialogMaison);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        lineEditType = new QLineEdit(DialogMaison);
        lineEditType->setObjectName("lineEditType");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditType);

        label_3 = new QLabel(DialogMaison);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        lineEditStanding = new QLineEdit(DialogMaison);
        lineEditStanding->setObjectName("lineEditStanding");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEditStanding);

        label_4 = new QLabel(DialogMaison);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        spinBoxChambres = new QSpinBox(DialogMaison);
        spinBoxChambres->setObjectName("spinBoxChambres");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, spinBoxChambres);

        label_5 = new QLabel(DialogMaison);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        spinBoxToilettes = new QSpinBox(DialogMaison);
        spinBoxToilettes->setObjectName("spinBoxToilettes");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, spinBoxToilettes);

        label_6 = new QLabel(DialogMaison);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        textEditDescription = new QTextEdit(DialogMaison);
        textEditDescription->setObjectName("textEditDescription");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, textEditDescription);


        verticalLayout->addLayout(formLayout);

        groupBox = new QGroupBox(DialogMaison);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"        QGroupBox {\n"
"          background-color: rgba(255,255,255,0.18);\n"
"          border-radius: 18px;\n"
"          border: 1px solid rgba(255,255,255,0.22);\n"
"        }\n"
"      "));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        labelPhoto1 = new QLabel(groupBox);
        labelPhoto1->setObjectName("labelPhoto1");
        labelPhoto1->setMinimumSize(QSize(180, 180));
        labelPhoto1->setAlignment(Qt::AlignCenter);
        labelPhoto1->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelPhoto1, 0, 0, 1, 1);

        labelPhoto2 = new QLabel(groupBox);
        labelPhoto2->setObjectName("labelPhoto2");
        labelPhoto2->setMinimumSize(QSize(180, 180));
        labelPhoto2->setAlignment(Qt::AlignCenter);
        labelPhoto2->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelPhoto2, 0, 1, 1, 1);

        labelPhoto3 = new QLabel(groupBox);
        labelPhoto3->setObjectName("labelPhoto3");
        labelPhoto3->setMinimumSize(QSize(180, 180));
        labelPhoto3->setAlignment(Qt::AlignCenter);
        labelPhoto3->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelPhoto3, 1, 0, 1, 1);

        labelPhoto4 = new QLabel(groupBox);
        labelPhoto4->setObjectName("labelPhoto4");
        labelPhoto4->setMinimumSize(QSize(180, 180));
        labelPhoto4->setAlignment(Qt::AlignCenter);
        labelPhoto4->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelPhoto4, 1, 1, 1, 1);

        btnPhoto1 = new QPushButton(groupBox);
        btnPhoto1->setObjectName("btnPhoto1");

        gridLayout->addWidget(btnPhoto1, 2, 0, 1, 1);

        btnPhoto2 = new QPushButton(groupBox);
        btnPhoto2->setObjectName("btnPhoto2");

        gridLayout->addWidget(btnPhoto2, 2, 1, 1, 1);

        btnPhoto3 = new QPushButton(groupBox);
        btnPhoto3->setObjectName("btnPhoto3");

        gridLayout->addWidget(btnPhoto3, 3, 0, 1, 1);

        btnPhoto4 = new QPushButton(groupBox);
        btnPhoto4->setObjectName("btnPhoto4");

        gridLayout->addWidget(btnPhoto4, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(DialogMaison);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogMaison);

        QMetaObject::connectSlotsByName(DialogMaison);
    } // setupUi

    void retranslateUi(QDialog *DialogMaison)
    {
        DialogMaison->setWindowTitle(QCoreApplication::translate("DialogMaison", "Maison", nullptr));
        label->setText(QCoreApplication::translate("DialogMaison", "ID :", nullptr));
        label_2->setText(QCoreApplication::translate("DialogMaison", "Type :", nullptr));
        label_3->setText(QCoreApplication::translate("DialogMaison", "Standing :", nullptr));
        label_4->setText(QCoreApplication::translate("DialogMaison", "Chambres :", nullptr));
        label_5->setText(QCoreApplication::translate("DialogMaison", "Toilettes :", nullptr));
        label_6->setText(QCoreApplication::translate("DialogMaison", "Description :", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogMaison", "Photos", nullptr));
        labelPhoto1->setText(QCoreApplication::translate("DialogMaison", "Photo 1", nullptr));
        labelPhoto2->setText(QCoreApplication::translate("DialogMaison", "Photo 2", nullptr));
        labelPhoto3->setText(QCoreApplication::translate("DialogMaison", "Photo 3", nullptr));
        labelPhoto4->setText(QCoreApplication::translate("DialogMaison", "Photo 4", nullptr));
        btnPhoto1->setText(QCoreApplication::translate("DialogMaison", "Choisir Photo 1", nullptr));
        btnPhoto2->setText(QCoreApplication::translate("DialogMaison", "Choisir Photo 2", nullptr));
        btnPhoto3->setText(QCoreApplication::translate("DialogMaison", "Choisir Photo 3", nullptr));
        btnPhoto4->setText(QCoreApplication::translate("DialogMaison", "Choisir Photo 4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMaison: public Ui_DialogMaison {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMAISON_H
