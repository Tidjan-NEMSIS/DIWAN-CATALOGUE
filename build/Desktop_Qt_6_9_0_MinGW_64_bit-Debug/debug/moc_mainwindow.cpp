/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "on_actionCharger_triggered",
        "",
        "on_actionSauvegarder_triggered",
        "on_actionQuitter_triggered",
        "on_actionRechercher_triggered",
        "on_actionInserer_triggered",
        "on_actionSupprimer_triggered",
        "on_actionModifier_triggered",
        "on_actionA_propos_triggered",
        "on_action_video_presentation_triggered",
        "on_actionF1_triggered",
        "on_actionF2_triggered",
        "on_actionF3_triggered",
        "on_actionSans_Hashage_triggered",
        "on_actionComparaison_Graphique_triggered",
        "on_pushButton_maison_suivante_clicked",
        "on_pushButton_maison_precedente_clicked",
        "on_pushButton_photo_suivante_clicked",
        "on_pushButton_photo_precedente_clicked",
        "onThumbnailClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_actionCharger_triggered'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSauvegarder_triggered'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionQuitter_triggered'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionRechercher_triggered'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionInserer_triggered'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSupprimer_triggered'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionModifier_triggered'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionA_propos_triggered'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action_video_presentation_triggered'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionF1_triggered'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionF2_triggered'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionF3_triggered'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSans_Hashage_triggered'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionComparaison_Graphique_triggered'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_maison_suivante_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_maison_precedente_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_photo_suivante_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_photo_precedente_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onThumbnailClicked'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_actionCharger_triggered(); break;
        case 1: _t->on_actionSauvegarder_triggered(); break;
        case 2: _t->on_actionQuitter_triggered(); break;
        case 3: _t->on_actionRechercher_triggered(); break;
        case 4: _t->on_actionInserer_triggered(); break;
        case 5: _t->on_actionSupprimer_triggered(); break;
        case 6: _t->on_actionModifier_triggered(); break;
        case 7: _t->on_actionA_propos_triggered(); break;
        case 8: _t->on_action_video_presentation_triggered(); break;
        case 9: _t->on_actionF1_triggered(); break;
        case 10: _t->on_actionF2_triggered(); break;
        case 11: _t->on_actionF3_triggered(); break;
        case 12: _t->on_actionSans_Hashage_triggered(); break;
        case 13: _t->on_actionComparaison_Graphique_triggered(); break;
        case 14: _t->on_pushButton_maison_suivante_clicked(); break;
        case 15: _t->on_pushButton_maison_precedente_clicked(); break;
        case 16: _t->on_pushButton_photo_suivante_clicked(); break;
        case 17: _t->on_pushButton_photo_precedente_clicked(); break;
        case 18: _t->onThumbnailClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
