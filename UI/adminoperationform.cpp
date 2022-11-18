#include "adminoperationform.h"
#include "ui_adminoperationform.h"

AdminOperationForm::AdminOperationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminOperationForm)
{
    ui->setupUi(this);
    initBackground();
}

AdminOperationForm::~AdminOperationForm()
{
    delete ui;
}

void AdminOperationForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background_admin.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void AdminOperationForm::on_btnModifyUser_clicked()
{
    ModifyUserForm* modifyuser = new ModifyUserForm();
    modifyuser->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    modifyuser->setWindowTitle("User Infos");
    modifyuser->setWindowModality(Qt::NonModal);
    modifyuser->show();

}

void AdminOperationForm::on_btnModifyLogin_clicked()
{
    ModifyLoginForm* modifylogin = new ModifyLoginForm();
    modifylogin->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    modifylogin->setWindowTitle("User Infos");
    modifylogin->setWindowModality(Qt::NonModal);
    modifylogin->show();
}

void AdminOperationForm::on_btnModifyTotalRec_clicked()
{
    ModifyTotalRecForm* modifyTRec = new ModifyTotalRecForm();
    modifyTRec->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    modifyTRec->setWindowTitle("User Infos");
    modifyTRec->setWindowModality(Qt::NonModal);
    modifyTRec->show();

}



void AdminOperationForm::on_btnExit_clicked()
{
    DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
    dbv2.adminLogout();
}
