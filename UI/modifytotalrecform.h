#ifndef MODIFYTOTALRECFORM_H
#define MODIFYTOTALRECFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRelationalTableModel>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRelationalDelegate>

namespace Ui {
class ModifyTotalRecForm;
}

class ModifyTotalRecForm : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyTotalRecForm(QWidget *parent = nullptr);
    ~ModifyTotalRecForm();

    void openTableTotal();
private slots:
    void tableChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnDelete_clicked();

    void on_btnSubmit_clicked();

    void on_btnCancel_clicked();

    void on_btnExit_clicked();

private:
    Ui::ModifyTotalRecForm *ui;

    void initBackground();
    QSqlDatabase DB;
    QSqlRelationalTableModel *TotalTableModel;
    QItemSelectionModel *selection;
};

#endif // MODIFYTOTALRECFORM_H
