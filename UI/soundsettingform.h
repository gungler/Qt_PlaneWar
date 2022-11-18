#ifndef SOUNDSETTINGFORM_H
#define SOUNDSETTINGFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class SoundSettingForm;
}

class SoundSettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SoundSettingForm(QWidget *parent = nullptr);
    ~SoundSettingForm();

signals:
    void sendMusicSettings(int volumn, QString BGMPath);

private slots:
    void on_btnSaveandQuit_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_rbtnFullVolumn_pressed();

    void on_rbtnMute_pressed();

private:
    Ui::SoundSettingForm *ui;
    void initBackground();
    int volumn = 50;

    QString BGMName;
    QString BGMPath;
};

#endif // SOUNDSETTINGFORM_H
