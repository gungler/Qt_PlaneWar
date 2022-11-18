#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "loginform.h"
#include "registerform.h"
#include "adminloginform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_btnLogin_clicked();

    void on_btnRegister_clicked();

    void on_btnAdminLogin_clicked();

private:
    Ui::MainWidget *ui;
    void initBackground();
};
#endif // MAINWIDGET_H
