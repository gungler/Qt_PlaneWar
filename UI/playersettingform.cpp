#include "playersettingform.h"
#include "ui_playersettingform.h"

PlayerSettingForm::PlayerSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerSettingForm)
{
    ui->setupUi(this);
    initBackground();
}

void PlayerSettingForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

PlayerSettingForm::~PlayerSettingForm()
{
    delete ui;
}

void PlayerSettingForm::on_btnDelete_clicked()
{
    LogoutForm *form1 = new LogoutForm();
    form1->setAttribute(Qt::WA_DeleteOnClose);
    form1->setWindowTitle("Logout");
    form1->setWindowModality(Qt::NonModal);
    form1->show();
}

void PlayerSettingForm::on_btnModifyPass_clicked()
{
    ModifyPasswordForm *form2 = new ModifyPasswordForm();
    form2->setAttribute(Qt::WA_DeleteOnClose);
    form2->setWindowTitle("Modify Password");
    form2->setWindowModality(Qt::NonModal);
    form2->show();
}

void PlayerSettingForm::on_btnPlayerExit_clicked()
{
    ExitForm *form3 = new ExitForm();
    connect(form3, SIGNAL(gameEnd()), this, SLOT(gameShouldClose()));
    form3->setAttribute(Qt::WA_DeleteOnClose);
    form3->setWindowTitle("Player Exit");
    form3->setWindowModality(Qt::NonModal);
    form3->show();
}

void PlayerSettingForm::gameShouldClose(){
    this->close();
    emit closeGameForm();
}
