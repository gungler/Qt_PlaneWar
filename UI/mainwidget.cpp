#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    initBackground();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initBackground(){

    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void MainWidget::on_btnLogin_clicked()
{
    LoginForm *loginform = new LoginForm();
    loginform->setAttribute(Qt::WA_DeleteOnClose);
    loginform->setWindowTitle("Login");
    loginform->setWindowModality(Qt::NonModal);
    loginform->show();
}

void MainWidget::on_btnRegister_clicked()
{
    RegisterForm *registerform = new RegisterForm();
    registerform->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    registerform->setWindowTitle("Register");
    registerform->setWindowModality(Qt::NonModal);
    registerform->show();
}


void MainWidget::on_btnAdminLogin_clicked()
{
    AdminLoginForm *adminForm = new AdminLoginForm();
    adminForm->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    adminForm->setWindowTitle("Register");
    adminForm->setWindowModality(Qt::NonModal);
    adminForm->show();
}

