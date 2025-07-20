#include "documentationdialog.h"
#include "ui_documentationdialog.h"
#include <QFile>
#include <QTextStream>
#include <QScrollBar>

DocumentationDialog::DocumentationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DocumentationDialog)
{
    ui->setupUi(this);

    // Charger le texte de la documentation
    QFile file(":/doc/documentation.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        ui->labelDocumentation->setText(in.readAll());
        file.close();
    }

    // Configurer le timer pour l'animation
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &DocumentationDialog::scrollText);
    m_timer->start(50); // Vitesse de défilement
}

DocumentationDialog::~DocumentationDialog()
{
    delete ui;
}

void DocumentationDialog::scrollText()
{
    QScrollBar *scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setValue(scrollBar->value() + 1);
    if (scrollBar->value() >= scrollBar->maximum())
    {
        scrollBar->setValue(0); // Revenir au début
    }
}
