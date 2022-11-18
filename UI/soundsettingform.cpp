#include "soundsettingform.h"
#include "ui_soundsettingform.h"

SoundSettingForm::SoundSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SoundSettingForm)
{
    ui->setupUi(this);
    initBackground();
}

SoundSettingForm::~SoundSettingForm()
{
    delete ui;
}

void SoundSettingForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);
    ui->horizontalSlider->setValue(75);
}

void SoundSettingForm::on_btnSaveandQuit_clicked()
{
    int volumn = ui->horizontalSlider->value();
    emit sendMusicSettings(volumn, BGMPath);
    this->close();
}

void SoundSettingForm::on_horizontalSlider_valueChanged(int value)
{
    if(value == 0){
        ui->rbtnMute->setChecked(true);
        ui->rbtnFullVolumn->setChecked(false);
    }else if(value == 100){
        ui->rbtnMute->setChecked(false);
        ui->rbtnFullVolumn->setChecked(true);
    }else{
        //cancle pressed in both button
        if(ui->rbtnMute->isChecked()){
            ui->rbtnMute->setAutoExclusive(false);
            ui->rbtnMute->setChecked(false);
            ui->rbtnMute->setAutoExclusive(true);
        }

        if(ui->rbtnFullVolumn->isChecked()){
            ui->rbtnFullVolumn->setAutoExclusive(false);
            ui->rbtnFullVolumn->setChecked(false);
            ui->rbtnFullVolumn->setAutoExclusive(true);
        }

    }
}
void SoundSettingForm::on_pushButton_clicked()
{
    QString currentpath = QDir::currentPath();
    QString title = "Open an Sound File";
    QString filter = "tr(*.MP3, *.AAC, *.FLAC, *.MIDI, *.WAV)";
    QFileDialog* selectDialog = new QFileDialog(this, title, currentpath, filter);
    if(selectDialog->exec() == QDialog::Accepted){
        BGMPath = selectDialog->selectedFiles()[0];
        BGMName = selectDialog->getOpenFileName();
    }

    //if select an exist file, remind user and set it to current
    ui->textBrowser->setText(BGMName);
}

void SoundSettingForm::on_rbtnFullVolumn_pressed()
{
    ui->horizontalSlider->setValue(100);
    ui->rbtnMute->setChecked(false);
}

void SoundSettingForm::on_rbtnMute_pressed()
{
    ui->horizontalSlider->setValue(0);
    ui->rbtnFullVolumn->setChecked(false);
}
