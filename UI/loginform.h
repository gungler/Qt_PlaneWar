#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "gameform.h"
#include "databaseoperations.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginForm *ui;
    void initBackground();
    void jump_to_game();
};

#endif // LOGINFORM_H
