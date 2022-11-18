#include "optionform.h"
#include "ui_optionform.h"

OptionForm::OptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionForm)
{
    ui->setupUi(this);
    initBackground();
}

OptionForm::~OptionForm()
{
    delete ui;
}

void OptionForm::initBackground(){
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
}

void OptionForm::on_btnGameSetting_clicked()
{
    GameSettingForm *gamesetting = new GameSettingForm();
    connect(gamesetting, SIGNAL(sendSettingData(QVector<int>)), this, SLOT(setPlayerSetting(QVector<int>)));
    gamesetting->setAttribute(Qt::WA_DeleteOnClose);
    gamesetting->setWindowTitle("Game Setting");
    gamesetting->setWindowModality(Qt::NonModal);
    gamesetting->initSkinLists();
    gamesetting->show();
}

void OptionForm::on_btnMusicSetting_clicked()
{
    SoundSettingForm *soundsetting = new SoundSettingForm();
    soundsetting->setAttribute(Qt::WA_DeleteOnClose);
    soundsetting->setWindowTitle("Sound Setting");
    soundsetting->setWindowModality(Qt::NonModal);
    QObject::connect(soundsetting, SIGNAL(sendMusicSettings(int, QString)),
                     this, SLOT(setMusicSetting(int, QString)));
    soundsetting->show();
}

void OptionForm::setPlayerSetting(QVector<int> datas){
    playerSettingDatas = datas;
}

void OptionForm::setMusicSetting(int volumn, QString BGMabsPath){
    this->volumn = volumn;
    this->BGMPath = BGMabsPath;
}

void OptionForm::on_btnExit_clicked()
{
    //send setting messages
    emit sendSettings(playerSettingDatas, volumn, BGMPath);

    //may redundant
    this->close();
}
