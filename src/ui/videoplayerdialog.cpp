#include "videoplayerdialog.h"
#include "ui_videoplayerdialog.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>

VideoPlayerDialog::VideoPlayerDialog(const QString &videoPath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPlayerDialog),
    m_mediaPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);

    // Set up the media player
    m_mediaPlayer->setVideoOutput(ui->videoWidget);
    m_mediaPlayer->setSource(QUrl::fromLocalFile(videoPath));

    // Connect the button box
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &VideoPlayerDialog::reject);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &VideoPlayerDialog::accept);

    // Start playing the video
    m_mediaPlayer->play();
}

VideoPlayerDialog::~VideoPlayerDialog()
{
    delete ui;
}
