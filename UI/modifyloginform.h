#ifndef MODIFYLOGINFORM_H
#define MODIFYLOGINFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRelationalTableModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QSqlRelationalDelegate>

#include "databaseoperations.h"

namespace Ui {
class ModifyLoginForm;
}

class ModifyLoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyLoginForm(QWidget *parent = nullptr);
    ~ModifyLoginForm();

    void openTableLogin();
private slots:
    void tableChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnDelete_clicked();

    void on_btnSubmit_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ModifyLoginForm *ui;
    QSqlDatabase DB;
    QSqlRelationalTableModel *loginTableModel;
    QItemSelectionModel *selection;

    void initBackground();
};
#endif // MODIFYLOGINFORM_H
