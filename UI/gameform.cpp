#include "gameform.h"
#include "ui_gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameForm),
    memory("GameSettings")
{
    ui->setupUi(this);
    initBackground();
    ui->textBrowser->installEventFilter(this);
}

GameForm::~GameForm()
{
    delete ui;
}

void GameForm::initBackground(){
    //add background
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/images/backgroundReg.png").scaled(
                                            // scale background
                                            this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);
}

void GameForm::on_btnOption_clicked()
{
    OptionForm *form1 = new OptionForm();
    connect(form1, SIGNAL(sendSettings(QVector<int>, int, QString)), this, SLOT(setSettings(QVector<int>, int, QString)));
    form1->setAttribute(Qt::WA_DeleteOnClose);//delete when closed
    form1->setWindowTitle("Options");
    form1->setWindowModality(Qt::NonModal);
    form1->show();
}

void GameForm::on_btnJoinGame_clicked()
{
    JoinGameForm *form2 = new JoinGameForm();
    form2->setAttribute(Qt::WA_DeleteOnClose);
    form2->setWindowTitle("Join Game");
    form2->setWindowModality(Qt::NonModal);
    form2->show();
}

void GameForm::on_btnGameStart_clicked()
{

    DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
    QVector<QString> names = dbv2.getOnlinePlayers();

    QStringList settings;
    qDebug() << names.size();
    settings.push_back(QString::number(names.size() + '\n'));

    for(int i=0; i < names.size(); ++i){
        settings.push_back(names[i] + '\n');
    }

    //set skin
    if(skinList.size() != 0){
        for(int skinIndex:skinList){
            settings.push_back(QString::number(skinIndex) + '\n');
        }
    }else{
        //set difficulty to normal
        settings.push_back(QString::number(1) + '\n');
        //set default skinindex
        for(int i=0; i < names.size(); ++i){
            settings.push_back(QString::number(i) + '\n');
        }
    }

    settings.push_back(QString::number(this->volumn) + '\n');

    settings.push_back(this->BGMabsPath + '\n');

    //send gamesetting datas
    qDebug() << "sending:";
    for(int i=0; i< settings.size(); ++i){
        qDebug() << settings[i];
    }

    QProcess* game = new QProcess(this);
    QObject::connect(game, &QProcess::errorOccurred, [] (QProcess::ProcessError error) {
                                qDebug() << "Error: " << error;});
    QString exePath = "E:\\qtProjects\\PlaneWar_MultiPlayer_v4\\build-PlaneWar_MultiPlayer_v4-Desktop_Qt_5_14_2_MinGW_64_bit-Debug\\PlaneWar_Game\\debug\\PlaneWar_Game.exe";
    if(QFileInfo(exePath).exists()){
        game->start(exePath, settings);
    }else{
        qDebug() << "exe file can't open!";
    }

    qDebug() << game->environment() << game->state() << game->error() <<
                game->exitCode() << game->exitStatus();

    while(!game->waitForFinished(4800000));//wait until game stop
    QByteArray qByteRead = game->readAllStandardOutput();

    //read game result datas
    QList<QByteArray> datalist = qByteRead.split('\n');
    datalist.erase(datalist.end() - 1);
    for(int i=0; i < datalist.size(); ++i){
        datalist[i] = datalist[i].replace("\r", "");
    }

    if(datalist.size()){
        DatabaseOperations& db = DatabaseOperations::getDBInstance();
        for(int i=0; i < names.size(); ++i){
            //playername, skill, score, difficulty, totalTime
            db.insertPlayRecord(names[i],
                                QString::fromStdString(datalist[0 + 4 * i].toStdString()),
                                datalist[1 + 4 * i].toInt(),
                                QString::fromStdString(datalist[2 + 4 * i].toStdString()),
                                datalist[3 + 4 * i].toInt());

            qDebug() << names[i] << "\n" <<
            QString::fromStdString(datalist[0 + 4 * i].toStdString())<< "\n" <<
            QString::fromStdString(datalist[1 + 4 * i].toStdString())<< "\n" <<
            QString::fromStdString(datalist[2 + 4 * i].toStdString())<< "\n" <<
            datalist[3 + 4 * i].toInt();
        }
    }
}

void GameForm::setSettings(QVector<int> skins, int volumn, QString BGMPath)
{
    for(int i = 0; i < skins.size(); i++){
        skinList = skins;
    }

    if(volumn > 0 && volumn < 100)
        this->volumn = volumn;
    if(BGMPath  != NULL)
    this->BGMabsPath = BGMPath;
}

void GameForm::on_btnPlayInstruction_clicked()
{
    InstructionForm *form3 = new InstructionForm();
    form3->setAttribute(Qt::WA_DeleteOnClose);
    form3->setWindowTitle("Instruction");
    form3->setWindowModality(Qt::NonModal);
    form3->show();
}

void GameForm::on_btnPlayerSet_clicked()
{
    PlayerSettingForm *form4 = new PlayerSettingForm();

    form4->setAttribute(Qt::WA_DeleteOnClose);
    form4->setWindowTitle("Player Settings");
    form4->setWindowModality(Qt::NonModal);
    form4->show();
}

bool GameForm::eventFilter(QObject* obj, QEvent* event){
    if(obj == ui->textBrowser){
        if(event->type() == QEvent::FocusIn){
            DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
            QVector<QString> names = dbv2.getOnlinePlayers();
            for(QString name:names)
                ui->textBrowser->append(name);
        }
        if(event->type() == QEvent::FocusOut){
            ui->textBrowser->clear();
        }
    }
    return true;
}



void GameForm::on_btnExitGame_clicked()
{
    DatabaseOperations& dbv2 = DatabaseOperations::getDBInstance();
    dbv2.OfflineAllUser();
}
