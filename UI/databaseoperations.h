#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QItemSelectionModel>
#include<QVariant>
#include<QString>
#include<QDateTime>
#include<QSqlError>
#include<QDebug>

class DatabaseOperations
{
public:
    static DatabaseOperations& getDBInstance();
    static bool userLogin(QString name, QString password);
    static bool adminLogin(QString name, QString password);
    static bool userLogout(QString name);
    static bool adminLogout();

    static bool createPlayer(QString id, QString username, QString password, QString mail, QString phone);
    static bool createAdmin(QString id, QString username, QString password, QString mail, QString phone);
    static bool deleteUser(QString name);
    static bool deleteAdmin(QString name);
    static bool modifyUsername(QString name, QString password, QString newName);
    static bool modifyPassword(QString name, QString password, QString newPassword);

    static bool insertPlayRecord(QString name, QString skill, int score, QString difficulty,  int totalTime);
    static bool updateTotalGrade(QString name, int score, int time);
    static bool allPlayerTotalInfos();
    static bool allPlayerInofs();

    static QVector<QString> getOnlinePlayers();
    static void OfflineAllUser();

private:
    DatabaseOperations() = default;
    ~DatabaseOperations() = default;
    DatabaseOperations(const DatabaseOperations& other) = delete;
    DatabaseOperations& operator=( const DatabaseOperations&) = delete;

    static QSqlDatabase DataBase;
    static QString dbType;
    static QString dbName;
    static QString dbPath;
    static QString DBusername;
    static QString DBpassword;
    static QString currentAdminName;
    static QVector<QString> onlinePlayers;
};

#endif // DATABASEOPERATIONS_H
