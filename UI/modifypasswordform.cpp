#include "modifypasswordform.h"
#include "ui_modifypasswordform.h"

ModifyPasswordForm::ModifyPasswordForm(QWidget *parent):
    QWidget(parent),
    ui(new Ui::ModifyPasswordForm)
{
    ui->setupUi(this);
    initBackground();
}

ModifyPasswordForm::~ModifyPasswordForm()
{
    delete ui;
}

void ModifyPasswordForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}


void ModifyPasswordForm::on_btnSubmit_clicked()
{
    QString username = ui->leUsername->text();
    QString opassword = ui->lePassword->text();
    QString npassword = ui->leNewPassword->text();
    QString confirm = ui->leConfirm->text();

    //format check
    if(username.size() >10){
        QMessageBox::information(this, "alert", "username is no longer than 10 chars.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else if(opassword.size()>20){
        QMessageBox::information(this, "alert", "password is no longer than 20 chars.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else if(npassword.size() > 20){
        QMessageBox::information(this, "alert", "new password is no loger than 11 numbers.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else if(confirm != npassword){
        QMessageBox::information(this, "alert", "cpnfirm password is not right.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else{
//        DB::modifyPassword(username, opassword, npassword);
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        dbv2.modifyPassword(username, opassword, npassword);
        this->close();
    }
}

