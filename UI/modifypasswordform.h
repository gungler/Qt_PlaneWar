#ifndef MODIFYPASSWORDFORM_H
#define MODIFYPASSWORDFORM_H

#include <QWidget>
#include "databaseoperations.h"
#include <QMessageBox>

namespace Ui {
class ModifyPasswordForm;
}

class ModifyPasswordForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyPasswordForm(QWidget *parent = nullptr);
    ~ModifyPasswordForm();

private slots:
    void on_btnSubmit_clicked();

private:
    Ui::ModifyPasswordForm *ui;
    void initBackground();
};

#endif // MODIFYPASSWORDFORM_H
