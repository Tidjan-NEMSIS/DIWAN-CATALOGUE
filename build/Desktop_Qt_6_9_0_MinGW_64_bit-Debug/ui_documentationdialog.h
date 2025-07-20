/********************************************************************************
** Form generated from reading UI file 'documentationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTATIONDIALOG_H
#define UI_DOCUMENTATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelDocumentation;

    void setupUi(QDialog *DocumentationDialog)
    {
        if (DocumentationDialog->objectName().isEmpty())
            DocumentationDialog->setObjectName("DocumentationDialog");
        DocumentationDialog->resize(600, 400);
        verticalLayout = new QVBoxLayout(DocumentationDialog);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(DocumentationDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 576, 376));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelDocumentation = new QLabel(scrollAreaWidgetContents);
        labelDocumentation->setObjectName("labelDocumentation");
        labelDocumentation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelDocumentation->setWordWrap(true);

        verticalLayout_2->addWidget(labelDocumentation);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(DocumentationDialog);

        QMetaObject::connectSlotsByName(DocumentationDialog);
    } // setupUi

    void retranslateUi(QDialog *DocumentationDialog)
    {
        DocumentationDialog->setWindowTitle(QCoreApplication::translate("DocumentationDialog", "Documentation", nullptr));
        labelDocumentation->setText(QCoreApplication::translate("DocumentationDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentationDialog: public Ui_DocumentationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTATIONDIALOG_H
