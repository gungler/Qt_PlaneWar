#include "exitform.h"
#include "ui_exitform.h"

ExitForm::ExitForm(QWidget *parent):
    QWidget(parent),
    ui(new Ui::ExitForm)
{
    ui->setupUi(this);
    initBackground();
}

ExitForm::~ExitForm()
{
    delete ui;
}

void ExitForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void ExitForm::on_btnSubmit_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    //format check
    if(username.size() >10){
        QMessageBox::information(this, "alert", "username is no longer than 10 chars.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else if(password.size()>20){
        QMessageBox::information(this, "alert", "password is no longer than 20 chars.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else{
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        dbv2.userLogout(username);
        QMessageBox::information(this, "information", "Logout Success!",
                                 QMessageBox::Ok);

        if(!dbv2.getOnlinePlayers().size()) emit gameEnd();
        this->close();
    }
}
