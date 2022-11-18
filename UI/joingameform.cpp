#include "joingameform.h"
#include "ui_joingameform.h"

JoinGameForm::JoinGameForm(QWidget *parent):
          QWidget(parent),
    ui(new Ui::JoinGameForm)
{
    ui->setupUi(this);
    initBackground();
    this->setAutoFillBackground(true);
}

JoinGameForm::~JoinGameForm()
{
    delete ui;
}

void JoinGameForm::on_btnLogin_clicked(){
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if(username == "" || password == ""){
        QMessageBox::information(this, "alert", "username or password shouldn't be null", QMessageBox::Ok);
        this->close();
        return;
    }else{
        DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
        QVector<QString> onlinePlayers = dbv2.getOnlinePlayers();
        for(int i=0; i< onlinePlayers.size(); ++i){
            if(onlinePlayers[i] == username){
                QMessageBox::information(this, "Reminder", "Player has Login!", QMessageBox::Ok);
                return;
            }
        }
        bool result = dbv2.userLogin(username, password);
        if(result){
            QMessageBox::information(this, "Reminder", "Login Success", QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this, "Reminder", "username or password is wrong, or player is full."
                                                       "please try again", QMessageBox::Ok);
        }
        this->close();
    }
}

void JoinGameForm::initBackground(){

    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}
