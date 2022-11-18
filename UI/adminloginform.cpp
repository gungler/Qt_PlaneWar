#include "adminloginform.h"
#include "ui_adminloginform.h"

AdminLoginForm::AdminLoginForm(QWidget *parent):
              QWidget(parent),
              ui(new Ui::AdminLoginForm)
{

    ui->setupUi(this);
    initBackground();
    this->setAutoFillBackground(true);
}

AdminLoginForm::~AdminLoginForm()
{
    delete ui;
}

void AdminLoginForm::on_btnLogin_clicked()
{

    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if(username == "" || password == ""){
        QMessageBox::information(this, "alert", "username or password shouldn't be null", QMessageBox::Ok);
        return;
    }else{
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        bool result = dbv2.adminLogin(username, password);
        if(result){
            QMessageBox::information(this, "Reminder", "Login Success", QMessageBox::Ok);
            jump_to_manage();
        }
        else{
            QMessageBox::information(this, "Reminder", "username or password is wrong, please"
                                                       " try again", QMessageBox::Ok);
        }
        this->close();
    }
}

void AdminLoginForm::jump_to_manage(){
    AdminOperationForm *operationform = new AdminOperationForm();
    operationform->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    operationform->setWindowTitle("Administrator");
    operationform->setWindowModality(Qt::NonModal);
    operationform->show();
}

void AdminLoginForm::initBackground(){

    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}
