#include "gamesettingform.h"
#include "ui_gamesettingform.h"

GameSettingForm::GameSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettingForm)
{
    ui->setupUi(this);
    initBackground();
}

GameSettingForm::~GameSettingForm()
{
    delete ui;
}

void GameSettingForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/background.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
     this->setPalette(palette);
    initSkinLists();
}

void GameSettingForm::initSkinLists(){
    DatabaseOperations& db = DatabaseOperations::getDBInstance();
    onlinePlayers = db.getOnlinePlayers();

    //manage infos with vector
    QVector<QString> currentSkinNames = skinList;
    QVector<QLabel*> playerNameLabels;
    playerNameLabels.push_back(ui->lbPlayer1Name);
    playerNameLabels.push_back(ui->lbPlayer2Name);
    playerNameLabels.push_back(ui->lbPlayer3Name);

    playerSkinLists.push_back(ui->cbPlayer1);
    playerSkinLists.push_back(ui->cbPlayer2);
    playerSkinLists.push_back(ui->cbPlayer3);


    for(int i=0; i < onlinePlayers.size(); ++i){
        playerNameLabels[i]->setText(onlinePlayers[i]);
        for(int j=0; j<currentSkinNames.size(); ++j){
            if(currentSkinNames[j] != NULL){
                playerSkinLists[i]->addItem(currentSkinNames[j]);
            }
        }


        //remove the selected item
        currentSkinNames.erase(currentSkinNames.begin());
    }

    //remove duplicated skins
    if(onlinePlayers.size() == 1){
        playerSkinLists[1]->setDisabled(true);
        playerSkinLists[2]->setDisabled(true);

        ui->cbPlayer2Skill->setDisabled(true);
        ui->cbPlayer3Skill->setDisabled(true);
    }else if(onlinePlayers.size() == 2){
        //remove duplicated items
        playerSkinLists[0]->removeItem(playerSkinLists[0]->findText(playerSkinLists[1]->currentText()));

        playerSkinLists[2]->setDisabled(true);
        ui->cbPlayer3Skill->setDisabled(true);
    }else if(onlinePlayers.size() == 3){
        //remove duplicated items
        playerSkinLists[0]->removeItem(playerSkinLists[0]->findText(playerSkinLists[1]->currentText()));

        playerSkinLists[0]->removeItem(playerSkinLists[0]->findText(playerSkinLists[2]->currentText()));

        playerSkinLists[1]->removeItem(playerSkinLists[1]->findText(playerSkinLists[2]->currentText()));
    }

    for(int i=0; i < onlinePlayers.size(); ++i){
        connect(playerSkinLists[i], SIGNAL(currentIndexChanged(const QString&)),
                this, SLOT(selectedSkinChanged(const QString&)));
    }

    switch(onlinePlayers.size()){
        case 1: comboBoxState[0] = 1;
                break;
        case 2: comboBoxState[0] = 1;
                comboBoxState[1] = 1;
                break;
        case 3: comboBoxState[0] = 1;
                comboBoxState[1] = 1;
                comboBoxState[2] = 1;
                break;
        default:break;
    }

    for(int i=0; i < onlinePlayers.size(); ++i){
        playerSkinLists[i]->setEnabled(comboBoxState[i]);
    }
    if(ui->cbPlayer1Skill->isEnabled())
        for(int i=0; i < skillList.size(); ++i){
            ui->cbPlayer1Skill->addItem(skillList[i]);
        }
    if(ui->cbPlayer2Skill->isEnabled())
        for(int i=0; i < skillList.size(); ++i){
            ui->cbPlayer2Skill->addItem(skillList[i]);
        }
    if(ui->cbPlayer3Skill->isEnabled())
        for(int i=0; i < skillList.size(); ++i){
            ui->cbPlayer3Skill->addItem(skillList[i]);
        }
}

void GameSettingForm::selectedSkinChanged(const QString& currentSkin){
    //get sender and corrosponding skin index
    QComboBox* changedBox = qobject_cast<QComboBox*>(sender());
    QString currentBoxName = changedBox->objectName();
    QString prevSkinName;

    if(currentBoxName == "cbPlayer1"){
        prevSkinName = prevSkin1;
    }else if(currentBoxName == "cbPlayer2"){
        prevSkinName = prevSkin2;
    }else if(currentBoxName == "cbPlayer3"){
        prevSkinName = prevSkin3;
    }

    //set the changed index
    for(QComboBox* comboBox:playerSkinLists){
        if(comboBox->objectName() != currentBoxName){
            if((currentBoxName == "cbPlayer1")&&(onlinePlayers.size() > 0)){
                //remove seleted item
                comboBox->removeItem(comboBox->findText(currentSkin));

                //add removed item
                comboBox->addItem(prevSkinName);
            }else if((currentBoxName == "cbPlayer2") && (onlinePlayers.size() > 1)){
                //remove seleted item
                comboBox->removeItem(comboBox->findText(currentSkin));

                //add removed item
                comboBox->addItem(prevSkinName);
            }else if((currentBoxName == "cbPlayer3") && (onlinePlayers.size() > 2)){
                //remove seleted item
                comboBox->removeItem(comboBox->findText(currentSkin));

                //add removed item
                comboBox->addItem(prevSkinName);
            }
        }
    }

    if(currentBoxName == "cbPlayer1"){
        prevSkin1 = currentSkin;
    }else if(currentBoxName == "cbPlayer2"){
        prevSkin2 = currentSkin;
    }else if(currentBoxName == "cbPlayer3"){
        prevSkin3 = currentSkin;
    }
}

void GameSettingForm::on_btnSaveandQuit_clicked()
{
    //[0] is difficulty, [1]-[size-1] is skins
    QVector<int> gameSettings;

    if(ui->rbtnEasy->isChecked()){
        gameSettings.push_back(0);
    }else if(ui->rbtnNormal->isChecked()){
        gameSettings.push_back(1);
    }else{
        gameSettings.push_back(2);
    }

    for(int i=0; i<onlinePlayers.size(); ++i){
        if(playerSkinLists[i]->currentText() == "Red"){
            gameSettings.push_back(0);
            continue;
        }else if(playerSkinLists[i]->currentText() == "Green"){
            gameSettings.push_back(1);
            continue;
        }else if(playerSkinLists[i]->currentText() == "Blue"){
            gameSettings.push_back(2);
            continue;
        }else if(playerSkinLists[i]->currentText() == "Cyan"){
            gameSettings.push_back(3);
            continue;
        }else if(playerSkinLists[i]->currentText() == "Yellow"){
            gameSettings.push_back(4);
            continue;
        }else{
            gameSettings.push_back(5);
        }
    }
    if(ui->cbPlayer1Skill->isEnabled())
        gameSettings.push_back(ui->cbPlayer1Skill->currentIndex());
    if(ui->cbPlayer2Skill->isEnabled())
        gameSettings.push_back(ui->cbPlayer2Skill->currentIndex());
    if(ui->cbPlayer3Skill->isEnabled())
        gameSettings.push_back(ui->cbPlayer3Skill->currentIndex());

    emit sendSettingData(gameSettings);
    this->close();
}
