#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QWidget>
#include <QProcess>
#include <QBuffer>
#include <QSharedMemory>
#include "optionform.h"
#include "instructionform.h"
#include "joingameform.h"
#include "playersettingform.h"
#include "gamesettingform.h"
#include "databaseoperations.h"


namespace Ui {
class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT
public:
    explicit GameForm(QWidget *parent = nullptr);
    ~GameForm();

signals:
    void getLogoutInfo(QVector<QString>);

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private slots:
    void on_btnOption_clicked();

    void on_btnJoinGame_clicked();

    void on_btnGameStart_clicked();

    void on_btnPlayInstruction_clicked();

    void on_btnPlayerSet_clicked();

    void setSettings(QVector<int>, int, QString);

    void on_btnExitGame_clicked();

private:
    void initBackground();

    Ui::GameForm *ui;
    QVector<int> skinList;
    int volumn = 75;
    QString BGMabsPath = "default";

    QSharedMemory memory;
};

#endif // GAMEFORM_H
