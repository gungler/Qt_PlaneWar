#ifndef MODIFYUSERFORM_H
#define MODIFYUSERFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRelationalTableModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QSqlRelationalDelegate>

namespace Ui {
class ModifyUserForm;
}

class ModifyUserForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyUserForm(QWidget *parent = nullptr);
    ~ModifyUserForm();

    void openTableUser();
private slots:
    void tableChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnDelete_clicked();

    void on_btnSubmit_clicked();

    void on_btnCancel_clicked();

    void on_btnExit_clicked();

private:
    Ui::ModifyUserForm *ui;

    void initBackground();
    QSqlDatabase DB;
    QSqlRelationalTableModel *userTableModel;
    QItemSelectionModel *selection;
};


#endif // MODIFYUSERFORM_H
