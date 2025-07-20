/********************************************************************************
** Form generated from reading UI file 'videoplayerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYERDIALOG_H
#define UI_VIDEOPLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVideoWidget *videoWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VideoPlayerDialog)
    {
        if (VideoPlayerDialog->objectName().isEmpty())
            VideoPlayerDialog->setObjectName("VideoPlayerDialog");
        VideoPlayerDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(VideoPlayerDialog);
        verticalLayout->setObjectName("verticalLayout");
        videoWidget = new QVideoWidget(VideoPlayerDialog);
        videoWidget->setObjectName("videoWidget");

        verticalLayout->addWidget(videoWidget);

        buttonBox = new QDialogButtonBox(VideoPlayerDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(VideoPlayerDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, VideoPlayerDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, VideoPlayerDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(VideoPlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoPlayerDialog)
    {
        VideoPlayerDialog->setWindowTitle(QCoreApplication::translate("VideoPlayerDialog", "Pr\303\251sentation Vid\303\251o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayerDialog: public Ui_VideoPlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYERDIALOG_H
