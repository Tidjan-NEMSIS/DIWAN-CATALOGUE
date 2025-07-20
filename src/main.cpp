#include <QApplication>
#include <QFile>
#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon(":/icons/logo.png"));

    // Charger et appliquer la feuille de style
    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        app.setStyleSheet(styleSheet);
        styleFile.close();
    }

    MainWindow w;
    w.show();
    return app.exec();
}