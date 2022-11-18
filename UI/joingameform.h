#ifndef JOINGAMEFORM_H
#define JOINGAMEFORM_H

#include <QWidget>
#include <QMessageBox>

#include "databaseoperations.h"

namespace Ui {
class JoinGameForm;
}

class JoinGameForm : public QWidget
{
    Q_OBJECT

public:
    explicit JoinGameForm(QWidget *parent = nullptr);
    ~JoinGameForm();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::JoinGameForm *ui;
    void initBackground();
    void upd_userState_login(QString id);
};

#endif // JOINGAMEFORM_H
