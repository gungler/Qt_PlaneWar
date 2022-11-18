#include "databaseoperations.h"

QSqlDatabase DatabaseOperations::DataBase;
QString DatabaseOperations::dbType = "QSQLITE" ;
QString DatabaseOperations::dbName;
QString DatabaseOperations::dbPath = "E:\\qtProjects\\PlaneWar_MultiPlayer_v4\\PlaneWar_MultiPlayer_v4\\UI\\db\\planewar.db3";
QString DatabaseOperations::DBusername;
QString DatabaseOperations::DBpassword;
QString DatabaseOperations::currentAdminName;
QVector<QString> DatabaseOperations::onlinePlayers;

DatabaseOperations& DatabaseOperations::getDBInstance(){
    static DatabaseOperations db;
    if(!db.DataBase.isOpen()){
        db.DataBase = QSqlDatabase::addDatabase(dbType);
        db.DataBase.setDatabaseName(dbPath);
        if (!db.DataBase.open()) {
               qDebug() << "failed to open DB";
        }
    }

    return db;
}

bool DatabaseOperations::userLogin(QString name, QString password){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("SELECT * FROM user WHERE name = :name and password = :password");
    userQuery.bindValue(":name", name);
    userQuery.bindValue(":password", password);
    userQuery.exec();

    //if user exist
    if(userQuery.next()){
        QString id = userQuery.value(0).toString();
        bool isAdmin = userQuery.value(5).toBool();


        if(onlinePlayers.size() > 2 || isAdmin){
            return false;
        }else{
            QSqlQuery logQuery(DataBase);
            logQuery.prepare("update logInfo set online = true "
                              "where userId = :id");
            logQuery.bindValue(":id", id);
            bool result = logQuery.exec();
            if(!result) qDebug() << "Failed to login with username: /n"
                                 << name << "/n" << logQuery.lastError().text();

            onlinePlayers.push_back(name);
            return result;
        }
    }

    return false;
}

bool DatabaseOperations::adminLogin(QString name, QString password){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("select * from user where name = :name "
                      "and password = :password");
    userQuery.bindValue(":name", name);
    userQuery.bindValue(":password", password);
    userQuery.exec();

    //if user exist
    if(userQuery.next() && currentAdminName == ""){
            QString id = userQuery.value(0).toString();
            bool isAdmin = userQuery.value(5).toBool();
            if(isAdmin){
                QSqlQuery logQuery(DataBase);
                logQuery.prepare("update logInfo set online = true "
                                  "where userId = :id");
                logQuery.bindValue(":id", id);
                bool result = logQuery.exec();
                if(!result) qDebug() << "Failed to login with username: /n"
                                     << name << "/n" << logQuery.lastError().text();
                else{
                    currentAdminName = name;
                    qDebug() << currentAdminName;
                    return true;
                }
            }else{
                qDebug() << "not a administrator";
                return false;
            }

    }
    return false;
}

//player exit
bool DatabaseOperations::userLogout(QString name){
    //check player is online
    bool state = 0;
    for(int i = 0; i < onlinePlayers.size(); ++i){
        if(onlinePlayers[i] == name)
            state = 1;
    }

    //if player is online
    if(state){
        QSqlQuery userQuery(DataBase);
        userQuery.prepare("select * from user where name = :name");
        userQuery.bindValue(":name", name);
        userQuery.exec();
        userQuery.next();
        QString id = userQuery.value(0).toString();

        //change state in logInfo
        QSqlQuery logQuery(DataBase);
        logQuery.prepare("update logInfo set online = 0, lastExitTime = :time where userId = :id");
        QDateTime now = QDateTime::currentDateTime();
        logQuery.bindValue(0, now);
        logQuery.bindValue(1, id);
        logQuery.exec();
        int a = logQuery.next();
        logQuery.finish();
        if(a){
            for(int i = 0; i < onlinePlayers.size(); ++i){
                if(onlinePlayers[i] == name)
                    onlinePlayers.erase(onlinePlayers.begin() + i);
                return true;
            }
        }
    }
    return false;
}

//admin exit
bool DatabaseOperations::adminLogout(){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("select * from user where name = :name");
    userQuery.bindValue(":name", currentAdminName);
    userQuery.exec();
    userQuery.next();
    QString id = userQuery.value(0).toString();

    //change state in logInfo
    QSqlQuery logQuery(DataBase);
    logQuery.prepare("update logInfo set online = 0, lastExitTime = :time where userId = :id");
    QDateTime now = QDateTime::currentDateTime();
    logQuery.bindValue(0, now);
    logQuery.bindValue(1, id);
    logQuery.exec();
    int a = logQuery.next();
    if(!a){
        qDebug() << "admin state abnormal with name: /n"
                           << currentAdminName << "/n" << logQuery.lastError().text();
        return false;
   }
    currentAdminName = "";
    return true;
}

//start
bool DatabaseOperations::createPlayer(QString id, QString username, QString password, QString mail, QString phone){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("insert into user(id, name, password, mailAdd, phoneNum, isAdmin) "
                   "values(:id, :username, :password, :mail, :phone, false)");
    userQuery.bindValue(0, id);
    userQuery.bindValue(1, username);
    userQuery.bindValue(2, password);
    userQuery.bindValue(3, mail);
    userQuery.bindValue(4, phone);

    bool a = userQuery.exec();
    if(!a) qDebug() << "Failed to create user with username: /n"
                  << username << "/n" << userQuery.lastError().text();
    userQuery.finish();

    //create user in logInfo
    QSqlQuery logQuery(DataBase);
    logQuery.prepare("insert into logInfo(logId, userId, online, lastExitTime) "
                     "values(NULL, :id, :online, :lastLogout)");
    logQuery.bindValue(0, id);
    logQuery.bindValue(1, false);
    QDateTime now = QDateTime::currentDateTime();
    logQuery.bindValue(2, now);

    bool b = logQuery.exec();
    if(!b) qDebug() << "Failed to insert logInfo with username: /n"
                  << username << "/n" << userQuery.lastError().text();
    logQuery.finish();

    //create total play record
    QSqlQuery totalQuery(DataBase);
    totalQuery.prepare("insert into totalRecord(tRecordId, playerId, bestScore, tScore, tTime, logTimes) "
                       "values(NULL, :id, 0, 0, 0, 0)");
    totalQuery.bindValue(0, id);
    bool c = totalQuery.exec();
    if(!c) qDebug() << "Failed to create records in totalRecord with username: /n"
                     << username << "/n" << totalQuery.lastError().text();
    totalQuery.finish();

    return a&b&c;
}

bool DatabaseOperations::createAdmin(QString id, QString username, QString password, QString mail, QString phone){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("insert into user(id, name, password, mailAdd, phoneNum, isAdmin) "
                   "values(:id, :username, :password, :mail, :phone, true)");
    userQuery.bindValue(0, id);
    userQuery.bindValue(1, username);
    userQuery.bindValue(2, password);
    userQuery.bindValue(3, mail);
    userQuery.bindValue(4, phone);

    bool a = userQuery.exec();
    if(!a) qDebug() << "Failed to create user with username: /n"
                  << username << "/n" << userQuery.lastError().text();
    userQuery.finish();
    if(!a) qDebug() << "Failed to create user with username: /n"
                  << username << "/n" << userQuery.lastError().text();
    userQuery.finish();

    //create user in logInfo
    QSqlQuery logQuery(DataBase);
    logQuery.prepare("insert into logInfo(logId, userId, online, lastExitTime) "
                     "values(NULL, :id, :online, :lastLogout)");
    logQuery.bindValue(0, id);
    logQuery.bindValue(1, false);
    QDateTime now = QDateTime::currentDateTime();
    logQuery.bindValue(2, now);

    bool b = logQuery.exec();
    if(!b) qDebug() << "Failed to insert logInfo with username: /n"
                  << username << "/n" << userQuery.lastError().text();
    logQuery.finish();
    return a&b;
}

bool DatabaseOperations::deleteUser(QString name){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("select * from user where name = :name");
    userQuery.bindValue(0, name);
    userQuery.exec();

   //if user exsit
   if(userQuery.next()){
       QString id = userQuery.value(0).toString();
       userQuery.finish();
       qDebug() << id;

       //delete player's records in 4 tables
       QSqlQuery logQuery(DataBase);
       logQuery.prepare("delete from logInfo where userId = :id");
       logQuery.bindValue(":id", id);
       logQuery.exec();
       logQuery.finish();

       QSqlQuery playQuery(DataBase);
       playQuery.prepare("delete from playRecord where playerId = :id");
       playQuery.bindValue(":id", id);
       playQuery.exec();
       playQuery.finish();

       QSqlQuery totalQuery(DataBase);
       totalQuery.prepare("delete from totalRecord where playerId = :id");
       totalQuery.bindValue(":id", id);
       totalQuery.exec();
       totalQuery.finish();

       userQuery.prepare("delete from user where id = :id");
       userQuery.bindValue(":id", id);
       userQuery.exec();
       userQuery.finish();

       return true;
   }

    return false;
}

bool DatabaseOperations::modifyPassword(QString name, QString password, QString newPassword){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("update user set password=:new where "
                      "name = :name and password = :password");
    userQuery.bindValue(0, newPassword);
    userQuery.bindValue(1, name);
    userQuery.bindValue(2, password);

    bool result = userQuery.exec();
    if(!result) qDebug() << "Failed to modify password with username: /n"
                                     << name << "/n" << userQuery.lastError().text();
    userQuery.finish();

    return result;
}

bool DatabaseOperations::insertPlayRecord(QString name, QString skill, int score, QString difficulty, int totalTime){

    QSqlQuery userQuery(DataBase);
    userQuery.prepare("select * from user where name = :name");
    userQuery.bindValue(0, name);
    userQuery.exec();

    if(userQuery.next()){
        QString id;
        id = userQuery.value("id").toString();
        userQuery.finish();

        //query corrsponding skill id
        QSqlQuery skillQuery(DataBase);
        skillQuery.prepare("select * from skill where skillName = :skillname");
        skillQuery.bindValue(":skillname", skill);
        skillQuery.exec();
        int skillId = 0;
        if(skillQuery.next()){
            skillId = skillQuery.value(0).toInt();
        }else{
            qDebug() << "skill dosen't eixst!";
        }
        skillQuery.finish();


        QSqlQuery playQuery(DataBase);
        playQuery.prepare("insert into playRecord(playerId, skillid, grade, difficulty, endTime)"
                          "values(:id, :skill, :grade, :difficulty, :time)");
        playQuery.bindValue(":id", id);
        playQuery.bindValue(":skill", skillId);
        playQuery.bindValue(":grade", score);
        playQuery.bindValue(":difficulty", difficulty);
        QDateTime endTime = QDateTime::currentDateTime();
        playQuery.bindValue(":time", endTime);

        bool result = playQuery.exec();
        if(!result){
            qDebug() << "Failed to insert record in playRecord with mailAddress: "
                             << name << " " << playQuery.lastError().text();
        }else{
            //update totalrecord and return ture
            updateTotalGrade(id, score, totalTime);
            return true;
        }
        playQuery.finish();
    }
    return false;
}

bool DatabaseOperations::updateTotalGrade(QString id, int score, int time){

    QSqlQuery totalQuery(DataBase);
    totalQuery.prepare("select * from totalRecord where playerId = :id");
    totalQuery.bindValue(0, id);
    totalQuery.exec();

    qDebug() << id;

    //if player has a record, update that record
    if(totalQuery.next()){
        int bestScore = totalQuery.value("bestScore").toInt();
        int totalScore = totalQuery.value("tScore").toInt();
        int totalTime = totalQuery.value("tTime").toInt();
        int logTimes = totalQuery.value("logTimes").toInt() + 1;
        totalQuery.finish();

        if(bestScore < score) bestScore = score;
        totalScore += score;
        totalTime += time;

        totalQuery.prepare("update totalRecord set "
                           "bestScore = :bScore, "
                           "tScore = :tScore, "
                           "tTime = :tTime, "
                           "logTimes = :logTimes "
                           "where playerId = :id");

        totalQuery.bindValue( ":bScore", bestScore);
        totalQuery.bindValue( ":tScore", totalScore);
        totalQuery.bindValue( ":tTime", totalTime);
        totalQuery.bindValue( ":logTimes", logTimes);
        totalQuery.bindValue( ":id", id);

        bool result = totalQuery.exec();
        if(!result) qDebug() << "Failed to update record in totalRecord with id: "
                                         << id << totalQuery.lastError().text();
        totalQuery.finish();
        return result;
    }
    //create a record
    else{
        totalQuery.prepare("insert into totalRecord(playerId, bestScore, tScore, tTime, logTimes)"
                           "values(:id, :bScore, :tScore, :tTime, :logTimes)");
        totalQuery.bindValue(":id", id);
        totalQuery.bindValue(":bScore", score);
        totalQuery.bindValue(":tScore", score);
        totalQuery.bindValue(":tTime", time);
        totalQuery.bindValue(":logTimes", 1);
        bool result = totalQuery.exec();
        if(!result) qDebug() << "Failed to insert record in totalRecord with id: /n"
                             << id  <<totalQuery.lastError().text();
        totalQuery.finish();
        return result;
    }

    return false;
}

QVector<QString> DatabaseOperations::getOnlinePlayers(){
    return onlinePlayers;
}

void DatabaseOperations::OfflineAllUser(){
    for(int i=0; i< onlinePlayers.size(); i++){
        userLogout(onlinePlayers[i]);
    }
}
