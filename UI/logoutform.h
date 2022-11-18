#ifndef LOGOUTFORM_H
#define LOGOUTFORM_H

#include <QWidget>
#include <QMessageBox>
#include "databaseoperations.h"

namespace Ui {
class LogoutForm;
}

class LogoutForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogoutForm(QWidget *parent = nullptr);
    ~LogoutForm();

private slots:
    void on_btnSubmit_clicked();

private:
    Ui::LogoutForm *ui;
    void initBackground();
};

#endif // LOGOUTFORM_H
