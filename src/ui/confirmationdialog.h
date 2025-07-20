#ifndef CONFIRMATIONDIALOG_H
#define CONFIRMATIONDIALOG_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class ConfirmationDialog;
}

class ConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmationDialog(const QString &title, const QString &message, const QString &details, const QPixmap &image, QWidget *parent = nullptr);
    ~ConfirmationDialog();

private:
    Ui::ConfirmationDialog *ui;
};

#endif // CONFIRMATIONDIALOG_H
