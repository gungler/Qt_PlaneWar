#include "logoutform.h"
#include "ui_logoutform.h"

LogoutForm::LogoutForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoutForm)
{
    ui->setupUi(this);
    initBackground();
}

LogoutForm::~LogoutForm()
{
    delete ui;
}

void LogoutForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}


void LogoutForm::on_btnSubmit_clicked()
{
    QString username = ui->leUsername->text();

    //format check
    if(username.size() > 10){
        QMessageBox::information(this, "alert", "username is no longer than 10 chars.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else{
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        bool result = dbv2.deleteUser(username);
        if(!result) QMessageBox::information(this, "message", "delete failed. no palyer named " + username,
                                             QMessageBox::Ok);
        else QMessageBox::information(this, "message", username + " has been cleared for system.",
                                      QMessageBox::Ok);
        this->close();
    }
}
