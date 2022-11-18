#ifndef GAMESETTINGFORM_H
#define GAMESETTINGFORM_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include "databaseoperations.h"

namespace Ui {
class GameSettingForm;
}

class GameSettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameSettingForm(QWidget *parent = nullptr);
    ~GameSettingForm();
    void initSkinLists();

signals:
    void sendSettingData(QVector<int> dataList);

private slots:

    void selectedSkinChanged(const QString&);

    void on_btnSaveandQuit_clicked();

private:
    Ui::GameSettingForm *ui;
    void initBackground();
    QVector<QString> onlinePlayers;
    QString prevSkin1 = "Red";
    QString prevSkin2 = "Green";
    QString prevSkin3 = "Blue";
    QVector<int> comboBoxState={ 1, 1, 1};

    QVector<QString> skinList={"Red","Green","Blue",
                              "Cyan","Yellow","Magenta"};

    QVector<QString> skillList={"Bomb", "RedBullet", "Heal", "Crush"};

    QVector<QComboBox*> playerSkinLists;
};


#endif // GAMESETTINGFORM_H
