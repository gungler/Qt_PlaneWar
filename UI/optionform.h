#ifndef OPTIONFORM_H
#define OPTIONFORM_H

#include <QWidget>
#include "gamesettingform.h"
#include "soundsettingform.h"

namespace Ui {
class OptionForm;
}

class OptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit OptionForm(QWidget *parent = nullptr);
    ~OptionForm();

signals:
    void sendSettings(QVector<int>, int, QString);

private slots:
    void on_btnGameSetting_clicked();

    void on_btnMusicSetting_clicked();

    void setPlayerSetting(QVector<int>);

    void setMusicSetting(int volumn, QString BGMabsPath);

    void on_btnExit_clicked();

private:
    Ui::OptionForm *ui;
    void initBackground();
    QVector<int> playerSettingDatas;
    int volumn;
    QString BGMPath;
};


#endif // OPTIONFORM_H
