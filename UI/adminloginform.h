#ifndef ADMINLOGINFORM_H
#define ADMINLOGINFORM_H

#include <QWidget>
#include <QMessageBox>

#include "gameform.h"
#include "databaseoperations.h"
#include "adminoperationform.h"

namespace Ui {
class AdminLoginForm;
}

class AdminLoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginForm(QWidget *parent = nullptr);
    ~AdminLoginForm();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::AdminLoginForm *ui;
    void initBackground();
    void jump_to_manage();
};

#endif // ADMINLOGINFORM_H
