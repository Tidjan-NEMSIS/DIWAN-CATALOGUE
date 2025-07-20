#ifndef VIDEOPLAYERDIALOG_H
#define VIDEOPLAYERDIALOG_H

#include <QDialog>

// Forward declarations
namespace Ui {
class VideoPlayerDialog;
}
class QMediaPlayer;

class VideoPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoPlayerDialog(const QString &videoPath, QWidget *parent = nullptr);
    ~VideoPlayerDialog();

private:
    Ui::VideoPlayerDialog *ui;
    QMediaPlayer *m_mediaPlayer;
};

#endif // VIDEOPLAYERDIALOG_H
