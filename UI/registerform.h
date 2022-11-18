#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QMessageBox>
#include <random>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <QtGlobal>

#include"databaseoperations.h"
#include"rng.h"

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void on_btnSubmit_clicked();

private:
    Ui::RegisterForm *ui;
    void initBackground();

    void openDB();
    void register_user();
    void createUser(QString id,QString username, QString password, QString email, QString phone);
    QString createUserId();

    //id generation
    QString getCurrentTime();
    QString generateId();
};
#endif // REGISTERFORM_H
