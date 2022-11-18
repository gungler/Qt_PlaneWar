#include "modifytotalrecform.h"
#include "ui_modifytotalrecform.h"

ModifyTotalRecForm::ModifyTotalRecForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyTotalRecForm)
{
    ui->setupUi(this);
    initBackground();
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("E:\\qtProjects\\PlaneWar_MultiPlayer_v4\\PlaneWar_MultiPlayer_v4\\UI\\db\\planewar.db3");
    if (!DB.open())   //打开数据库
    {
        QMessageBox::warning(this, "Error", "failed to connect database", QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }
    openTableTotal();
}

ModifyTotalRecForm::~ModifyTotalRecForm()
{
    delete ui;
}

void ModifyTotalRecForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background_admin.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void ModifyTotalRecForm::openTableTotal(){
    QSqlQuery sql_query;
    sql_query.exec("PRAGMA foreign_keys = ON;");

    TotalTableModel = new QSqlRelationalTableModel(this, DB);
    TotalTableModel->setTable("totalRecord");
    TotalTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    TotalTableModel->setSort(0, Qt::AscendingOrder);

    TotalTableModel->setHeaderData(0, Qt::Horizontal, "tRecordId");
    TotalTableModel->setHeaderData(1, Qt::Horizontal, "playerName");
    TotalTableModel->setHeaderData(2, Qt::Horizontal, "bestScore");
    TotalTableModel->setHeaderData(3, Qt::Horizontal, "tScore");
    TotalTableModel->setHeaderData(4, Qt::Horizontal, "tTime");
    TotalTableModel->setHeaderData(5, Qt::Horizontal, "logTimes");

    TotalTableModel->setRelation(1,QSqlRelation("user", "id", "name"));

    selection = new QItemSelectionModel(TotalTableModel);
    connect(selection, SIGNAL(currentChanged(QModelIndex, QModelIndex)),
            this, SLOT(tableChanged(QModelIndex, QModelIndex)));

    ui->tableView->setModel(TotalTableModel);
    ui->tableView->setSelectionModel(selection);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    TotalTableModel->select();
}

//change infos when it is reall changed
void ModifyTotalRecForm::tableChanged(const QModelIndex &current, const QModelIndex &previous){
    Q_UNUSED(current);
    Q_UNUSED(previous);
    ui->btnSubmit->setEnabled(TotalTableModel->isDirty());
    ui->btnCancel->setEnabled(TotalTableModel->isDirty());
}

void ModifyTotalRecForm::on_btnAdd_clicked()
{
    TotalTableModel->insertRow(TotalTableModel->rowCount(),QModelIndex());
    QModelIndex curIndex = TotalTableModel->index(TotalTableModel->rowCount()-1,1);
    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}

void ModifyTotalRecForm::on_btnInsert_clicked()
{
    QModelIndex curIndex = ui->tableView->currentIndex();
    TotalTableModel->insertRow(curIndex.row(),QModelIndex());

    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}


void ModifyTotalRecForm::on_btnDelete_clicked()
{
    TotalTableModel->removeRow(selection->currentIndex().row());
}

void ModifyTotalRecForm::on_btnSubmit_clicked()
{
    bool result = TotalTableModel->submitAll();
    if(!result)
        QMessageBox::information(this, "error", "failed to open databse:" + TotalTableModel->lastError().text(),
                                 QMessageBox::Ok,QMessageBox::NoButton);
    else{
        ui->btnSubmit->setEnabled(false);
        ui->btnCancel->setEnabled(false);
    }

}

void ModifyTotalRecForm::on_btnCancel_clicked()
{
    TotalTableModel->revertAll();
    ui->btnSubmit->setEnabled(false);
    ui->btnCancel->setEnabled(false);
}


void ModifyTotalRecForm::on_btnExit_clicked()
{
    this->close();
}
