#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent):
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    initBackground();
    this->setAutoFillBackground(true);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_btnLogin_clicked(){
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
            jump_to_game();
            QMessageBox::information(this, "Reminder", "Login Success", QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this, "Reminder", "username or password is wrong, please"
                                                       " try again", QMessageBox::Ok);
        }
        this->close();
    }
}

void LoginForm::jump_to_game(){
    GameForm *gameform = new GameForm();
    gameform->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    gameform->setWindowTitle("GameMenu");
    gameform->setWindowModality(Qt::NonModal);
    gameform->show();
}

void LoginForm::initBackground(){

    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}
