#include "modifyloginform.h"
#include "ui_modifyloginform.h"
#include <QMessageBox>

ModifyLoginForm::ModifyLoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyLoginForm)
{
    ui->setupUi(this);
    initBackground();
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("E:\\qtProjects\\PlaneWar_MultiPlayer_v4\\PlaneWar_MultiPlayer_v4\\UI\\db\\planewar.db3");
    if (!DB.open())   //打开数据库
    {
        QMessageBox::warning(this, "error", "failed to connect Database", QMessageBox::Ok,QMessageBox::NoButton);
        return;
    }
    openTableLogin();
}

ModifyLoginForm::~ModifyLoginForm()
{
    delete ui;
}

void ModifyLoginForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background_admin.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void ModifyLoginForm::openTableLogin(){
    QSqlQuery sql_query;
    sql_query.exec("PRAGMA foreign_keys = ON;");

    loginTableModel = new QSqlRelationalTableModel(this, DB);
    loginTableModel->setTable("logInfo");
    loginTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    loginTableModel->setSort(0, Qt::AscendingOrder);

    loginTableModel->setHeaderData(0, Qt::Horizontal, "logId");
    loginTableModel->setHeaderData(1, Qt::Horizontal, "playerName");
    loginTableModel->setHeaderData(2, Qt::Horizontal, "online");
    loginTableModel->setHeaderData(3, Qt::Horizontal, "lastExitTime");

    loginTableModel->setRelation(1,QSqlRelation("user", "id", "name"));

    selection = new QItemSelectionModel(loginTableModel);
    connect(selection, SIGNAL(currentChanged(QModelIndex, QModelIndex)),
            this, SLOT(tableChanged(QModelIndex, QModelIndex)));

    ui->tableView->setModel(loginTableModel);
    ui->tableView->setSelectionModel(selection);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    loginTableModel->select();
}

//change infos when it is reall changed
void ModifyLoginForm::tableChanged(const QModelIndex &current, const QModelIndex &previous){
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->btnSubmit->setEnabled(loginTableModel->isDirty());
    ui->btnCancel->setEnabled(loginTableModel->isDirty());
}

void ModifyLoginForm::on_btnAdd_clicked()
{
    loginTableModel->insertRow(loginTableModel->rowCount(),QModelIndex());
    QModelIndex curIndex = loginTableModel->index(loginTableModel->rowCount()-1,1);
    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}

void ModifyLoginForm::on_btnInsert_clicked()
{
    QModelIndex curIndex = ui->tableView->currentIndex();
    loginTableModel->insertRow(curIndex.row(),QModelIndex());

    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}


void ModifyLoginForm::on_btnDelete_clicked()
{
    loginTableModel->removeRow(selection->currentIndex().row());
}

void ModifyLoginForm::on_btnSubmit_clicked()
{
    bool result = loginTableModel->submitAll();
    if(!result)
        QMessageBox::information(this, "消息", "数据保存错误,错误信息" + loginTableModel->lastError().text(),
                                 QMessageBox::Ok,QMessageBox::NoButton);
    else{
        ui->btnSubmit->setEnabled(false);
        ui->btnCancel->setEnabled(false);
    }
}

void ModifyLoginForm::on_btnCancel_clicked()
{
    loginTableModel->revertAll();
    ui->btnSubmit->setEnabled(false);
    ui->btnCancel->setEnabled(false);
}

