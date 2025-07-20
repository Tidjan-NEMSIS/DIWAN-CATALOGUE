QT += core gui widgets sql charts multimedia multimediawidgets

CONFIG += c++17
TEMPLATE = app
TARGET = Diwan-catalogue

# Spécifier l'icône de l'application pour Windows
RC_ICON = resources/logo.ico

SOURCES += \
    src/main.cpp \
    src/models/maison.cpp \
    src/models/table_hachage.cpp \
    src/models/fonction_hachage.cpp \
    src/database/db.cpp \
    src/ui/mainwindow.cpp \
    src/ui/comparaisondialog.cpp \
    src/ui/dialogmaison.cpp \
    src/ui/documentationdialog.cpp \
    src/ui/confirmationdialog.cpp \
    src/ui/rotatablelabel.cpp \
    src/ui/marqueelabel.cpp \
        src/ui/clickablelabel.cpp \
    src/ui/videoplayerdialog.cpp

HEADERS += \
    src/models/maison.h \
    src/models/table_hachage.h \
    src/models/fonction_hachage.h \
    src/database/db.h \
    src/ui/mainwindow.h \
    src/ui/comparaisondialog.h \
    src/ui/dialogmaison.h \
    src/ui/documentationdialog.h \
    src/ui/confirmationdialog.h \
    src/ui/rotatablelabel.h \
    src/ui/marqueelabel.h \
        src/ui/clickablelabel.h \
    src/ui/videoplayerdialog.h

FORMS += \
    src/ui/mainwindow.ui \
    src/ui/comparaisondialog.ui \
    src/ui/dialogmaison.ui \
    src/ui/documentationdialog.ui \
        src/ui/confirmationdialog.ui \
    src/ui/videoplayerdialog.ui

RESOURCES += resources.qrc

INCLUDEPATH += src
