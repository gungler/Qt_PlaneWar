#ifndef ADMINOPERATIONFORM_H
#define ADMINOPERATIONFORM_H

#include <QWidget>
#include <QCloseEvent>
#include "databaseoperations.h"
#include "modifyloginform.h"
#include "modifytotalrecform.h"
#include "modifyuserform.h"

namespace Ui {
class AdminOperationForm;
}

class AdminOperationForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminOperationForm(QWidget *parent = nullptr);
    ~AdminOperationForm();

private slots:
    void on_btnModifyUser_clicked();

    void on_btnModifyLogin_clicked();

    void on_btnModifyTotalRec_clicked();

    void on_btnExit_clicked();

private:
    Ui::AdminOperationForm *ui;
    void initBackground();
};

#endif // ADMINOPERATIONFORM_H
