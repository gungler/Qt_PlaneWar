#include "modifyuserform.h"
#include "ui_modifyuserform.h"

ModifyUserForm::ModifyUserForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyUserForm)
{
    ui->setupUi(this);
    initBackground();
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("E:\\qtProjects\\PlaneWar_MultiPlayer_v4\\PlaneWar_MultiPlayer_v4\\UI\\db\\planewar.db3");
    if (!DB.open())   //打开数据库
    {
        QMessageBox::warning(this, "error", "failed open database",
                                 QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
    openTableUser();
}

void ModifyUserForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background_admin.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}


void ModifyUserForm::openTableUser(){
    userTableModel = new QSqlRelationalTableModel(this, DB);
    userTableModel->setTable("user");
    userTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    userTableModel->setSort(0, Qt::AscendingOrder);

    userTableModel->setHeaderData(0, Qt::Horizontal, "id");
    userTableModel->setHeaderData(1, Qt::Horizontal, "name");
    userTableModel->setHeaderData(2, Qt::Horizontal, "password");
    userTableModel->setHeaderData(3, Qt::Horizontal, "mailAdd");
    userTableModel->setHeaderData(4, Qt::Horizontal, "phoneNum");
    userTableModel->setHeaderData(5, Qt::Horizontal, "isAdmin");

    selection = new QItemSelectionModel(userTableModel);
    connect(selection, SIGNAL(currentChanged(QModelIndex, QModelIndex)),
            this, SLOT(tableChanged(QModelIndex, QModelIndex)));

    ui->tableView->setModel(userTableModel);
    ui->tableView->setSelectionModel(selection);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    userTableModel->select();
}

//change infos when it is really changed
void ModifyUserForm::tableChanged(const QModelIndex &current, const QModelIndex &previous){
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->btnSubmit->setEnabled(userTableModel->isDirty());
    ui->btnCancel->setEnabled(userTableModel->isDirty());
}


ModifyUserForm::~ModifyUserForm()
{
    delete ui;
}

void ModifyUserForm::on_btnAdd_clicked()
{
    userTableModel->insertRow(userTableModel->rowCount(),QModelIndex());
    QModelIndex curIndex = userTableModel->index(userTableModel->rowCount()-1,1);
    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}

void ModifyUserForm::on_btnInsert_clicked()
{
    QModelIndex curIndex = ui->tableView->currentIndex();
    userTableModel->insertRow(curIndex.row(),QModelIndex());

    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}


void ModifyUserForm::on_btnDelete_clicked()
{
    userTableModel->removeRow(selection->currentIndex().row());
    userTableModel->submitAll();
}

void ModifyUserForm::on_btnSubmit_clicked()
{
    bool result = userTableModel->submitAll();
    if(!result)
        QMessageBox::information(this, "message", "failed to save datas,error message\n"+userTableModel->lastError().text(),
                                 QMessageBox::Ok,QMessageBox::NoButton);
    else{
        ui->btnSubmit->setEnabled(false);
        ui->btnCancel->setEnabled(false);
    }

}

void ModifyUserForm::on_btnCancel_clicked()
{
    userTableModel->revertAll();
    ui->btnSubmit->setEnabled(false);
    ui->btnCancel->setEnabled(false);
}

void ModifyUserForm::on_btnExit_clicked()
{
    this->close();
}
