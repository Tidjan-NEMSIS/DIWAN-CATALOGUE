#ifndef DOCUMENTATIONDIALOG_H
#define DOCUMENTATIONDIALOG_H

#include <QDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class DocumentationDialog;
}
QT_END_NAMESPACE

class DocumentationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DocumentationDialog(QWidget *parent = nullptr);
    ~DocumentationDialog();

private slots:
    void scrollText();

private:
    Ui::DocumentationDialog *ui;
    QTimer *m_timer;
    int m_scrollPos = 0;
};

#endif // DOCUMENTATIONDIALOG_H
