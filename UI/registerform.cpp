#include "registerform.h"
#include "ui_registerform.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    initBackground();
    this->setAutoFillBackground(true);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::initBackground(){

    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/backgroundReg.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void RegisterForm::on_btnSubmit_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    QString email = ui->leEmail->text();
    QString phone = ui->lePhone->text();

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
    }else if(phone.size() != 11){
        QMessageBox::information(this, "alert", "phone number is no loger than 11 numbers.",
                                 QMessageBox::Ok);
        return;
        this->close();
    }else{
        QString id;
        id = createUserId();
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        dbv2.createPlayer(id, username, password, email, phone);
        this->close();
    }
}

QString RegisterForm::createUserId(){
    //rng initialization
    long long idNum = RNG::genUserId();

    //type convertion: long long to QString
    std::string idStr;
    std::ostringstream os;
    os << idNum;
    std::istringstream is(os.str());
    is >> idStr;
    QString id = QString::fromStdString(idStr);

    return id;
}
