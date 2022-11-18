#ifndef EXITFORM_H
#define EXITFORM_H

#include <QWidget>
#include <QMessageBox>
#include "databaseoperations.h"

namespace Ui {
class ExitForm;
}

class ExitForm : public QWidget
{
    Q_OBJECT

public:
    explicit ExitForm(QWidget *parent = nullptr);
    ~ExitForm();

signals:
    //used to trigger information sending
    void gameEnd();

private slots:
    void on_btnSubmit_clicked();

private:
    Ui::ExitForm *ui;
    void initBackground();

    //logout infos for current player
    int currentScore = 0;
    QString currentSkill = "";
    QString loginTime = "";
    QString logoutTime = "";

};
#endif // EXITFORM_H
